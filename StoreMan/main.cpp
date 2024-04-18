#include "mainwindow.h"
#include "database.h"
#include "product.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("store.db");
    MainWindow w(&db);

    DataBase database(&db);
    Product pr(&db);
    ProductInformation info;


    QVector<ProductInformation> vec = pr.getAllProduct();




    w.show();
    return a.exec();
}
