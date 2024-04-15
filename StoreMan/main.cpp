#include "mainwindow.h"
#include "database.h"
#include "product.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("store.db");
    DataBase database(&db);
    Product pr(&db);
    pr.addProduct(100, "reza", 2000, 10, 10, "small", "nike", "small", "null", "null");
    qDebug() << pr.getProductName(100);
    w.show();
    return a.exec();
}
