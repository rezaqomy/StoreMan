#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>



class DataBase
{
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    void crateTables();
    QSqlQuery query;

public:
    DataBase(const QString &dbName);
    QSqlQuery& getQuery();
};

#endif // DATABASE_H
