/********************************************************************************
** Form generated from reading UI file 'pescitidesmaneger.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PESCITIDESMANEGER_H
#define UI_PESCITIDESMANEGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <histogram.h>
#include <pie.h>

QT_BEGIN_NAMESPACE

class Ui_PescitidesManeger
{
public:
    QAction *actionmaneger;
    QAction *actionsale;
    QAction *actionmin;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QStackedWidget *stackedWidget;
    QWidget *maneger;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *factory;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label12;
    QComboBox *brand;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *price11;
    QLineEdit *price;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QSpinBox *number;
    QLabel *label_11;
    QLabel *lastNum;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *sum;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ok;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_6;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *add;
    QPushButton *del;
    QPushButton *sub;
    QPushButton *rev;
    QListWidget *listWidget;
    QWidget *sale;
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *changjia;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_3;
    QComboBox *pinpai;
    QSpacerItem *horizontalSpacer_9;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    Histogram *histogram;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    Pie *pie;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *PescitidesManeger)
    {
        if (PescitidesManeger->objectName().isEmpty())
            PescitidesManeger->setObjectName(QStringLiteral("PescitidesManeger"));
        PescitidesManeger->resize(683, 514);
        actionmaneger = new QAction(PescitidesManeger);
        actionmaneger->setObjectName(QStringLiteral("actionmaneger"));
        actionsale = new QAction(PescitidesManeger);
        actionsale->setObjectName(QStringLiteral("actionsale"));
        actionmin = new QAction(PescitidesManeger);
        actionmin->setObjectName(QStringLiteral("actionmin"));
        centralWidget = new QWidget(PescitidesManeger);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        title = new QLabel(centralWidget);
        title->setObjectName(QStringLiteral("title"));

        verticalLayout->addWidget(title);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        maneger = new QWidget();
        maneger->setObjectName(QStringLiteral("maneger"));
        horizontalLayout = new QHBoxLayout(maneger);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter = new QSplitter(maneger);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setFrameShape(QFrame::Box);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 337, 383));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        factory = new QComboBox(widget);
        factory->setObjectName(QStringLiteral("factory"));

        horizontalLayout_2->addWidget(factory);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 4);
        horizontalLayout_2->setStretch(2, 5);

        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(page);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label12 = new QLabel(widget_3);
        label12->setObjectName(QStringLiteral("label12"));

        horizontalLayout_4->addWidget(label12);

        brand = new QComboBox(widget_3);
        brand->setObjectName(QStringLiteral("brand"));

        horizontalLayout_4->addWidget(brand);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 4);
        horizontalLayout_4->setStretch(2, 5);

        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(page);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        price11 = new QLabel(widget_4);
        price11->setObjectName(QStringLiteral("price11"));

        horizontalLayout_5->addWidget(price11);

        price = new QLineEdit(widget_4);
        price->setObjectName(QStringLiteral("price"));

        horizontalLayout_5->addWidget(price);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_4);

        widget_7 = new QWidget(page);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_8 = new QHBoxLayout(widget_7);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_10 = new QLabel(widget_7);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_8->addWidget(label_10);

        number = new QSpinBox(widget_7);
        number->setObjectName(QStringLiteral("number"));

        horizontalLayout_8->addWidget(number);

        label_11 = new QLabel(widget_7);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_8->addWidget(label_11);

        lastNum = new QLabel(widget_7);
        lastNum->setObjectName(QStringLiteral("lastNum"));

        horizontalLayout_8->addWidget(lastNum);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 3);
        horizontalLayout_8->setStretch(2, 1);
        horizontalLayout_8->setStretch(3, 2);
        horizontalLayout_8->setStretch(4, 3);

        verticalLayout_2->addWidget(widget_7);

        widget_6 = new QWidget(page);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_7 = new QHBoxLayout(widget_6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(widget_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        sum = new QLineEdit(widget_6);
        sum->setObjectName(QStringLiteral("sum"));

        horizontalLayout_7->addWidget(sum);

        label_9 = new QLabel(widget_6);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget_6);

        widget_8 = new QWidget(page);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        horizontalLayout_9 = new QHBoxLayout(widget_8);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        ok = new QPushButton(widget_8);
        ok->setObjectName(QStringLiteral("ok"));

        horizontalLayout_9->addWidget(ok);

        cancel = new QPushButton(widget_8);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_9->addWidget(cancel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_2->addWidget(widget_8);

        toolBox->addItem(page, QString::fromUtf8("\345\207\272\345\224\256\345\206\234\350\215\257"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 337, 383));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableView = new QTableView(page_2);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_3->addWidget(tableView);

        widget_9 = new QWidget(page_2);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        horizontalLayout_10 = new QHBoxLayout(widget_9);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        add = new QPushButton(widget_9);
        add->setObjectName(QStringLiteral("add"));
        add->setMinimumSize(QSize(45, 0));
        add->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_10->addWidget(add);

        del = new QPushButton(widget_9);
        del->setObjectName(QStringLiteral("del"));
        del->setMinimumSize(QSize(45, 0));
        del->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_10->addWidget(del);

        sub = new QPushButton(widget_9);
        sub->setObjectName(QStringLiteral("sub"));
        sub->setMinimumSize(QSize(45, 0));
        sub->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_10->addWidget(sub);

        rev = new QPushButton(widget_9);
        rev->setObjectName(QStringLiteral("rev"));
        rev->setMinimumSize(QSize(45, 0));
        rev->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_10->addWidget(rev);


        verticalLayout_3->addWidget(widget_9);

        toolBox->addItem(page_2, QString::fromUtf8("\346\226\260\350\215\257\345\205\245\345\272\223"));
        splitter->addWidget(toolBox);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        splitter->addWidget(listWidget);

        horizontalLayout->addWidget(splitter);

        stackedWidget->addWidget(maneger);
        sale = new QWidget();
        sale->setObjectName(QStringLiteral("sale"));
        horizontalLayout_11 = new QHBoxLayout(sale);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        widget_2 = new QWidget(sale);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(widget_5);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        changjia = new QComboBox(widget_5);
        changjia->setObjectName(QStringLiteral("changjia"));

        horizontalLayout_3->addWidget(changjia);

        horizontalSpacer_8 = new QSpacerItem(60, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        pinpai = new QComboBox(widget_5);
        pinpai->setObjectName(QStringLiteral("pinpai"));

        horizontalLayout_3->addWidget(pinpai);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);
        horizontalLayout_3->setStretch(2, 4);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 4);
        horizontalLayout_3->setStretch(5, 4);

        verticalLayout_4->addWidget(widget_5);

        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        horizontalLayout_6 = new QHBoxLayout(widget_10);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        frame_10 = new QFrame(widget_10);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        frame_10->setFrameShape(QFrame::Box);
        verticalLayout_5 = new QVBoxLayout(frame_10);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_4 = new QLabel(frame_10);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(label_4);

        histogram = new Histogram(frame_10);
        histogram->setObjectName(QStringLiteral("histogram"));

        verticalLayout_5->addWidget(histogram);


        horizontalLayout_6->addWidget(frame_10);

        frame_11 = new QFrame(widget_10);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setFrameShape(QFrame::Box);
        verticalLayout_6 = new QVBoxLayout(frame_11);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_5 = new QLabel(frame_11);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(label_5);

        pie = new Pie(frame_11);
        pie->setObjectName(QStringLiteral("pie"));

        verticalLayout_6->addWidget(pie);


        horizontalLayout_6->addWidget(frame_11);


        verticalLayout_4->addWidget(widget_10);


        horizontalLayout_11->addWidget(widget_2);

        stackedWidget->addWidget(sale);

        verticalLayout->addWidget(stackedWidget);

        PescitidesManeger->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PescitidesManeger);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 683, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        PescitidesManeger->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionmaneger);
        menu->addAction(actionsale);
        menu_2->addAction(actionmin);

        retranslateUi(PescitidesManeger);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PescitidesManeger);
    } // setupUi

    void retranslateUi(QMainWindow *PescitidesManeger)
    {
        PescitidesManeger->setWindowTitle(QApplication::translate("PescitidesManeger", "PescitidesManeger", nullptr));
        actionmaneger->setText(QApplication::translate("PescitidesManeger", "\345\206\234\350\215\257\347\256\241\347\220\206", nullptr));
        actionsale->setText(QApplication::translate("PescitidesManeger", "\351\224\200\345\224\256\347\273\237\350\256\241", nullptr));
        actionmin->setText(QApplication::translate("PescitidesManeger", "\345\257\206\347\240\201\344\277\256\346\224\271", nullptr));
        title->setText(QApplication::translate("PescitidesManeger", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("PescitidesManeger", "\345\216\202\345\256\266\357\274\232", nullptr));
        label12->setText(QApplication::translate("PescitidesManeger", "\345\220\215\347\247\260\357\274\232", nullptr));
        price11->setText(QApplication::translate("PescitidesManeger", "\344\273\267\346\240\274\357\274\232", nullptr));
        label_6->setText(QApplication::translate("PescitidesManeger", "\345\205\203", nullptr));
        label_10->setText(QApplication::translate("PescitidesManeger", "\346\225\260\351\207\217\357\274\232", nullptr));
        label_11->setText(QApplication::translate("PescitidesManeger", "\345\211\251\344\275\231\346\225\260\351\207\217\357\274\232", nullptr));
        lastNum->setText(QApplication::translate("PescitidesManeger", "000", nullptr));
        label_8->setText(QApplication::translate("PescitidesManeger", "\351\207\221\351\242\235\357\274\232", nullptr));
        label_9->setText(QApplication::translate("PescitidesManeger", "\345\205\203", nullptr));
        ok->setText(QApplication::translate("PescitidesManeger", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QApplication::translate("PescitidesManeger", "\345\217\226\346\266\210", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("PescitidesManeger", "\345\207\272\345\224\256\345\206\234\350\215\257", nullptr));
        add->setText(QApplication::translate("PescitidesManeger", "\346\267\273\345\212\240", nullptr));
        del->setText(QApplication::translate("PescitidesManeger", "\345\210\240\351\231\244", nullptr));
        sub->setText(QApplication::translate("PescitidesManeger", "\346\217\220\344\272\244", nullptr));
        rev->setText(QApplication::translate("PescitidesManeger", "\346\222\244\351\224\200", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("PescitidesManeger", "\346\226\260\350\215\257\345\205\245\345\272\223", nullptr));
        label->setText(QApplication::translate("PescitidesManeger", "\345\216\202\345\256\266\357\274\232", nullptr));
        label_3->setText(QApplication::translate("PescitidesManeger", "\345\223\201\347\211\214\357\274\232", nullptr));
        label_4->setText(QApplication::translate("PescitidesManeger", "\345\216\202\345\256\266\345\223\201\347\211\214", nullptr));
        label_5->setText(QApplication::translate("PescitidesManeger", "\345\223\201\347\211\214\350\215\257\345\223\201", nullptr));
        menu->setTitle(QApplication::translate("PescitidesManeger", "\351\224\200\345\224\256\347\256\241\347\220\206", nullptr));
        menu_2->setTitle(QApplication::translate("PescitidesManeger", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PescitidesManeger: public Ui_PescitidesManeger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PESCITIDESMANEGER_H
