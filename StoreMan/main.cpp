#include "mainwindow.h"
#include "database.h"
#include "product.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DataBase db("store.db");
    Product pr;
    pr.addQuery(100, "reza", 2000, 10, 10, "small", "nike", "small", "null", "null");
    qDebug() << pr.getName(100);
    w.show();
    return a.exec();
}
