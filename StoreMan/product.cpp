#include "product.h"
#include "database.h"
#include <QDebug>

Product::Product()
{


}

void Product::addQuery(int id_product ,QString product_name = "null", int price = 0, int discount = 0, int quantity = 0, QString type = "null", QString brand = "null", QString size = "null", QString address_in_store = "null", QString image_address = "null"){
    DataBase db("store.db");
    QSqlQuery query = db.getQuery();
    query.exec("USE product");

    QString insertPerson = QString("INSERT INTO person VALUES(") + QString::number(id_product) + ", '" + product_name+ "', " + QString::number(price) + ", " + QString::number(discount) + ", " + QString::number(quantity) + ", '" + type + "', '" + brand + "', '" + size + "', '" + address_in_store + "', '" + image_address + "')";
    query.exec(insertPerson);
}

QString Product::getName(int id_product){
    DataBase db("store.db");
    QSqlQuery query = db.getQuery();
    query.exec("SELECT first_name FROM product WHERE id_product = " + QString::number(id_product));
    query.next();
    return query.value(1).toString();
}
