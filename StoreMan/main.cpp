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
    ProductInformation info;


    QVector<ProductInformation> vec = pr.getAllProduct();

    for(int i{}; i < vec.size(); i++) {
        qDebug() <<  vec[i].id << vec[i].productName << vec[i].price;
    }


    w.show();
    return a.exec();
}
