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



    int num = pr.addProduct(&info);

    qDebug() << pr.getProductName(1580) << "   id : " << num;
    w.show();
    return a.exec();
}
