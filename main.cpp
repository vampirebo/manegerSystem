﻿#include "pescitidesmaneger.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    PescitidesManeger w;
    w.show();



    return a.exec();
}