#include "database.h"

DataBase::DataBase(const QString &dbName)
{
    db.setDatabaseName(dbName);

    if (!db.open()){
        QMessageBox msgbox;
        msgbox.setText("data base not opened!!!");
        msgbox.setInformativeText("please restart the program");
        msgbox.exec();
    }
    crateTables();


}

void DataBase::crateTables(){
    query.exec("CREATE TABLE customer(id_customer int primary key, first_name varchar(30), last_name varchar(40), phone_number varchar(11), addres Qstring)");
    query.exec("CREATE TABLE product(id_puoduct int primary key, product_name varchar(40), price int, discount int, quantity int, type varchar(30), brand varchar(30), size varchar(20), address_in_store QString, image_address QString");
    // query.exec("CREATE TABLE order(id_order int primary key, date_order , )");
    /*TODO*/

}


QSqlQuery& DataBase::getQuery() {
    return query;
}
