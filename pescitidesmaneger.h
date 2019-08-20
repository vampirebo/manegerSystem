#ifndef PESCITIDESMANEGER_H
#define PESCITIDESMANEGER_H

#include <QMainWindow>
#include <QDomDocument>

namespace Ui {
class PescitidesManeger;
}

class PescitidesManeger : public QMainWindow
{
    Q_OBJECT

public:
    explicit PescitidesManeger(QWidget *parent = 0);
    ~PescitidesManeger();
    //连接数据库
    bool connectDB();

    //设置厂家选择的Box
    void initSaleSystem();

    //厂家变化
    void factoryChange(const QString & fName);

    //品牌变化
    void brandChange(const QString & bName);

    //数量变化
    void numChange(int num);

    //创建XML表
    void createXML();

    //往XML文件中写入数据
    void writeXMLData();
    //读XML文档
    bool readXML();
    //将XML文档写到文件中
    bool writeXML();

    //获取日期时间
    QString getDateTime(QString type);

    //封装XML的创建节点的方法
    void createXMLNode(QDomElement & parent);

    //把销售清单显示到列表中
     void showSaleList();

     //销售统计
     void initCalculate();

    //新药入库
     void newPes();
private:
    Ui::PescitidesManeger *ui;
    QDomDocument m_doc;
};

#endif // PESCITIDESMANEGER_H
