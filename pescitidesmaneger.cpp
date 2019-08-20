#include "pescitidesmaneger.h"
#include "ui_pescitidesmaneger.h"
#include <QString>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QModelIndexList>
#include <QItemSelectionModel>

PescitidesManeger::PescitidesManeger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PescitidesManeger)
{
    ui->setupUi(this);
    //创建空的XML表
    createXML();
    //界面初始化
    ui->title->setText(QString("<center><h1> 农药管理 </h1><center>"));
    ui->stackedWidget->setCurrentWidget(ui->maneger);
    //切换农药管理和销售统计
    connect(ui->actionmaneger,&QAction::triggered,[=](){
        ui->stackedWidget->setCurrentWidget(ui->maneger);
//        ui->stackedWidget->setCurrentIndex(0);
        ui->title->setText(QString("<center><h1> 农药管理 </h1></center>"));
    });
    connect(ui->actionsale,&QAction::triggered,[=](){
        ui->stackedWidget->setCurrentWidget(ui->sale);
        ui->title->setText(QString("<center><h1> 销售统计 </h1></center>"));
    });

    //连接数据库
    bool result =  connectDB();
    if(!result)
        return;

    //初始化农药管理界面
    initSaleSystem();
    //初始化ok
    factoryChange("请选择厂家");
    //销售统计
    initCalculate();
    //新药入库
    newPes();
}

void PescitidesManeger::initSaleSystem()
{
    //使用模型进行厂家的下拉选择
    QSqlQueryModel * model = new QSqlQueryModel(this);
    model->setQuery("select name from factory");
    ui->factory->setModel(model);
    ui->changjia->setModel(model);

    //厂家的变化
    void(QComboBox::*sigCombox)(const QString &) = &QComboBox::currentIndexChanged;
    connect(ui->factory,sigCombox,this,&PescitidesManeger::factoryChange);

    //品牌变化
    connect(ui->brand,sigCombox,this,&PescitidesManeger::brandChange);

    //数量变化
    void (QSpinBox:: * sigSpin)(int) = QSpinBox::valueChanged;//数量变化，指针的重载
    connect(ui->number,sigSpin,this,&PescitidesManeger::numChange);

    //取消按键
    connect(ui->cancel,&QPushButton::clicked,[=](){
        ui->factory->setCurrentText("请选择厂家");
    });

    //确定按钮
    connect(ui->ok,&QPushButton::clicked,[=](){
         QString factory = ui->factory->currentText();
         QString brand = ui->brand->currentText();
         int num = ui->number->value();
         int last = ui->lastNum->text().toInt()-num;//购买后剩余数量
         QSqlQuery query;
         query.exec(QString("select sell from brand where factory = '%1'and name= '%2'").arg(factory).arg(brand));
         if(query.next())
         {
             int sell = query.value(0).toInt() + num;

             QSqlDatabase::database().transaction();//记录当前数据库状态
//             QString str1 = QString("update brand set sell = '%1',last = '%2' where factory = '%3' and name = '%4'").arg(sell).arg(last).arg(factory).arg(brand));
             bool result = query.exec(QString("update brand set sell = '%1',last = '%2' where factory = '%3' and name = '%4'").arg(sell).arg(last).arg(factory).arg(brand));

             if(!result){
                 //回滚数据库
                 QSqlDatabase::database().rollback();
             }
             else
             {
                 //提交数据库
                 QSqlDatabase::database().commit();
                 QMessageBox::information(this,"success","恭喜购买成功");

                 //将数据写入到XML
                 writeXMLData();

                 //将XML中的数据 显示到销售清单中
                 showSaleList();

             }
         }
         ui->factory->setCurrentText("请选择厂家");
    });
}


//更改厂家的变化，清空
void PescitidesManeger::factoryChange(const QString &fName)
{
    ui->brand->clear();
    ui->number->setValue(0);//重置数量变化
    ui->sum->setText("");//重置金额
    if(fName == "请选择厂家")
    {
        ui->price->clear();
        ui->sum->clear();
        ui->sum->setEnabled(false);
        ui->number->setValue(0);
        ui->lastNum->setText(0);
        ui->ok->setEnabled(false);
    }
    else
    {
        QSqlQuery query;
        query.exec(QString("select name from brand where factory='%1'").arg(fName));
        while(query.next()){
            QString brandItem = query.value(0).toString();
            ui->brand->addItem(brandItem);
        }
    }
}
//品牌变化
void PescitidesManeger::brandChange(const QString & bName)
{
    ui->number->setValue(0);//重置数量变化
    ui->sum->setText("");//重置金额
    QSqlQuery query;
    query.exec(QString("select price,last from brand where factory = '%1' and name = '%2'").arg(ui->factory->currentText()).arg(bName));
    if(query.next())
    {
        int price= query.value(0).toInt();
        int last = query.value(1).toInt();
        ui->price->setText(QString::number(price));
        ui->lastNum->setText(QString::number(last));
    }
}
//数量变化
void PescitidesManeger::numChange(int num)
{
    if(num == 0){
        ui->ok->setEnabled(false);
    }
    else{
        ui->ok->setEnabled(true);
        int sum = num * ui->price->text().toInt();
        ui->sum->setText(QString::number(sum));
    }
}
bool PescitidesManeger::readXML()
{
    QFile file("saleList.xml");
    bool result = file.open(QIODevice::ReadOnly);
    if(!result)
        return false;
    else{
        m_doc.setContent(&file);
        file.close();
        return true;
    }

}
bool PescitidesManeger::writeXML()
{
    QFile file("SaleList.xml");
    bool result = file.open(QIODevice::WriteOnly);
    if(result){
        QTextStream stream(&file);
        m_doc.save(stream,4);
        file.close();
        return true;
    }
    else{
        file.close();
        return false;
    }

}
//设置时间的方法
QString PescitidesManeger::getDateTime(QString type)
{
    QDateTime today = QDateTime::currentDateTime();
    if(type == "DATE")
        return today.toString("yyyy-MM-dd");
    else if(type =="TIME")
        return today.toString("hh:mm:ss");
    else
        return today.toString("yyyy-MM-dd hh:mm:ss");
}
//XML写入数据
 void PescitidesManeger::writeXMLData()
 {

     if(readXML())
     {
        QDomElement root =  m_doc.documentElement();
        if(!root.hasChildNodes())
        {
            QDomElement dateEle = m_doc.createElement("日期");
            QDomAttr dateAttr = m_doc.createAttribute("date");
            //将属性的值赋给属性
            dateAttr.setValue(getDateTime("DATE"));
            //将属性整体 给日期元素
            dateEle.setAttributeNode(dateAttr);
            root.appendChild(dateEle);
            //对子节点进行封装
            createXMLNode(dateEle);
        }
        else
        {
            QDomElement lastEle = root.lastChildElement();
            if(lastEle.attribute("date")==getDateTime("DATE"))
            {
                //有今天的数据了
                createXMLNode(lastEle);
            }
            else{
                QDomElement dateEle = m_doc.createElement("日期");
                QDomAttr dateAttr = m_doc.createAttribute("date");
                //将属性的值赋给属性
                dateAttr.setValue(getDateTime("DATE"));
                //将属性整体 给日期元素
                dateEle.setAttributeNode(dateAttr);
                root.appendChild(dateEle);
                createXMLNode(dateEle);
            }
        }
        writeXML();
     }
 }
//在销售清单中追加子节点
void PescitidesManeger::createXMLNode(QDomElement & parent)
{
    //时间
    QDomElement timeEle = m_doc.createElement("时间");
    QDomAttr timeAttr = m_doc.createAttribute("time");
    timeAttr.setValue(getDateTime("TIME"));
    timeEle.setAttributeNode(timeAttr);
    parent.appendChild(timeEle);

    //厂家
    QDomElement factoryEle =m_doc.createElement("厂家");
    timeEle.appendChild(factoryEle);
    QDomText factoryText = m_doc.createTextNode(ui->factory->currentText());
    factoryEle.appendChild(factoryText);

    //品牌
    QDomElement brandEle =m_doc.createElement("品牌");
    timeEle.appendChild(brandEle);
    QDomText brandText = m_doc.createTextNode(ui->brand->currentText());
    brandEle.appendChild(brandText);

    //价格
    QDomElement priceEle =m_doc.createElement("价格");
    timeEle.appendChild(priceEle);
    QDomText priceText = m_doc.createTextNode(ui->price->text());
    priceEle.appendChild(priceText);

    //数量
    QDomElement numberEle =m_doc.createElement("数量");
    timeEle.appendChild(numberEle);
    QDomText numberText = m_doc.createTextNode(ui->number->text());
    numberEle.appendChild(numberText);

    //金额
    QDomElement sumEle =m_doc.createElement("金额");
    timeEle.appendChild(sumEle);
    QDomText sumText = m_doc.createTextNode(ui->sum->text());
    sumEle.appendChild(sumText);

    //库存
    QDomElement lastNumEle =m_doc.createElement("库存剩余");
    timeEle.appendChild(lastNumEle);
    QDomText lastNumText = m_doc.createTextNode(ui->lastNum->text());
    lastNumEle.appendChild(lastNumText);
}

//将销售清单显示到列表中
void PescitidesManeger::showSaleList()
{
    //对清单进行操作，避免重复出现
    ui->listWidget->clear();
    if(readXML())
    {
        QDomElement root = m_doc.documentElement();
        QListWidgetItem * item =  new QListWidgetItem(QString("********%1********").arg(root.tagName()));
        item->setTextAlignment(Qt::AlignCenter);
        ui->listWidget->addItem(item);

        QDomElement lastEle = root.lastChildElement();
        QDomNodeList timeNodeList = lastEle.childNodes();//时间节点

        //遍历时间节点里面的数据
        for(int i = 0;i < timeNodeList.count();++i)
        {
             QDomElement timeEle = timeNodeList.at(i).toElement();
             QDomNodeList list = timeEle.childNodes();
             QString factory = list.at(0).toElement().text();
             QString brand = list.at(1).toElement().text();
             QString price = list.at(2).toElement().text();
             QString number = list.at(3).toElement().text();
             QString sum = list.at(4).toElement().text();
             QString lastNum = list.at(5).toElement().text();


             //拼接，某时间卖出品牌，数量，价格以及金额
             QString str = QString("%1卖出%2的%3共%4件，单价为%5元，总金额为：%6元,剩余库存%7件")
                     .arg(timeEle.attribute("time")).arg(factory).arg(brand).arg(number).arg(price).arg(sum).arg(lastNum);
             ui->listWidget->addItem(str);
        }
    }
}

//销售统计
void  PescitidesManeger::initCalculate()
{
    //柱状图
    ui->histogram->SetMaxValue(1500);
    void(QComboBox::*sigCombox)(const QString &) = &QComboBox::currentIndexChanged;
    connect(ui->changjia,sigCombox,[=](const QString &fName){
        //清空之前的图形数据
         ui->pinpai->clear();
        ui->histogram->Clear();

        QSqlQuery query;
        query.exec(QString("select name,sell from brand where factory = '%1'").arg(fName));
        while(query.next())
        {
            QString name = query.value(0).toString();
            ui->pinpai->addItem(name);

            int sell = query.value(1).toInt();
            QColor color(qrand()%255,qrand()%255,qrand()%255);
            ui->histogram->AddItem(name,sell,color);
        }
        ui->histogram->update();
    });
    //饼图
    connect(ui->pinpai, sigCombox, [=](const QString &name)
        {
            QSqlQuery query;
            QVector<SectorInfo> vc;
            query.exec(QString("select sell, last from brand where factory='%1' and name ='%2'")
                       .arg(ui->changjia->currentText()).arg(name));
            if(query.next())
            {
                SectorInfo info;
                float sell = query.value(0).toInt();
                float last = query.value(1).toInt();
                float sum = sell + last;
                info.description = "已出售";
                info.percent = sell/sum*100;
                vc.push_back(info);
                info.description = "剩余";
                info.percent = 100 - info.percent;
                vc.push_back(info);
            }
            ui->pie->setData(vc);
        });
}

//新药入库
void PescitidesManeger::newPes()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("brand");
    model->select();
    ui->tableView->setModel(model);
    //提交模式，避免直接更改操作数据库
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //提交
    connect(ui->sub,&QPushButton::clicked,[=](){
        model->submitAll();
    });
    //撤销
    connect(ui->rev,&QPushButton::clicked,[=](){
    model->revertAll();
    });
    //添加
    connect(ui->add,&QPushButton::clicked,[=](){
        QSqlRecord record = model->record();
        int count = model->rowCount();
        model->insertRecord(count,record);
    });
    //删除
    connect(ui->del,&QPushButton::clicked,[=](){
        QItemSelectionModel * smodel = ui->tableView->selectionModel();
        QModelIndexList list = smodel->selectedRows();
        for(int i = 0;i<list.size();++i)
        {
            model->removeRow(list.at(0).row());
        }
    });
}
//数据库连接
bool PescitidesManeger::connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("system");
    db.setUserName("root");
    db.setPassword("hyb123");

    if(!db.open()){
        QMessageBox::critical(this,"打开失败",db.lastError().text());
        return false;
    }
    else
        return true;
}

//创建XML表
void PescitidesManeger::createXML()
{
    QFile file("SaleList.xml");
    //打开成功，直接返回
    if(!file.open(QFile::WriteOnly|QFile::Truncate)) //可以用QIODevice，Truncate表示清空原来的内容
           return;
    QDomDocument doc;
    //创建 配置指令 文件头
    QDomProcessingInstruction ins = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");

    doc.appendChild(ins);

    //创建根节点
    QDomElement root = doc.createElement("日销售清单");
    doc.appendChild(root);
    QTextStream stream(&file);
    doc.save(stream, 4);
    file.close();
}

PescitidesManeger::~PescitidesManeger()
{
    delete ui;
}
