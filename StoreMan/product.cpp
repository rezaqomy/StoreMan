#include "product.h"
#include "database.h"

Product::Product()
{


}

void Product::addQuery(int id_product,QString product_name, int price, int discount, int quantity, QString type, QString brand, QString size, QString address_in_store, QString image_address){
    DataBase db("store.db");
    QSqlQuery query = db.getQuery();
    query.exec("USE product");

    QString insertPerson = QString("INSERT INTO person VALUES()" + id_product);
    query.exec(insertPerson);
}
