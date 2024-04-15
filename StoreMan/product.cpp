#include "product.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

Product::Product(QSqlDatabase* db) : db_(db) {
    query_ = QSqlQuery();
    if (!db_) {
        qWarning() << "Product: Database connection not provided!";
    }
}

ProductInformation* Product::getProduct(int id){
    ProductInformation prinfo;
    if (!db_) {
        qCritical() << "Product: Database connection not provided!";
        return &prinfo;
    }



    QString idStr = QString::number(id);
    QString queryStr = "SELECT id FROM mytable WHERE id = :id";
    QSqlQuery query(*db_);
    query.prepare(queryStr);
    query.bindValue(":id", idStr);

    if (!query.exec()) {
        return &prinfo;
    }









    QString insertQuery = "SELECT * FROM product WHERE id_product = id"
                            "VALUES (:id)";






    query.prepare(insertQuery);
    query.bindValue(":id", id);

    query.next();

    prinfo.id = query.value(0).toInt();
    prinfo.productName = query.value(1).toString();
    prinfo.price = query.value(2).toInt();
    prinfo.discount = query.value(3).toInt();
    prinfo.quantity = query.value(4).toInt();
    prinfo.type = query.value(5).toString();
    prinfo.brand = query.value(6).toString();
    prinfo.size = query.value(7).toString();
    prinfo.addressInStore = query.value(8).toString();
    prinfo.imageAddress = query.value(9).toString();

    return &prinfo;
}

bool Product::updateValues(ProductInformation* prinfo){
    if (!db_) {
        qCritical() << "Product: Database connection not provided!";
        return false;
    }

    QSqlQuery query(*db_);
    QString insertQuery = "UPDATE product SET product_name = Nproduct_name, price = Nprice, discount = Ndiscount, quantity = Nquantity, type = Ntype, brand = Nbrand, size = Nsize, address_in_store = Naddress_in_store, image_address = Nimage_address) "
                          "VALUES (:Nproduct_name, :Nprice, :Ndiscount, :Nquantity, :Ntype, :Nbrand, :Nsize, :Naddress_in_store, :Nimage_address)";



    query.prepare(insertQuery);
    query.bindValue(":Nproduct_name", prinfo->productName);
    query.bindValue(":Nprice", prinfo->price);
    query.bindValue(":Ndiscount", prinfo->discount);
    query.bindValue(":Nquantity", prinfo->quantity);
    query.bindValue(":Ntype", prinfo->type);
    query.bindValue(":Nbrand", prinfo->brand);
    query.bindValue(":Nsize", prinfo->size);
    query.bindValue(":Naddress_in_store", prinfo->addressInStore);
    query.bindValue(":Nimage_address", prinfo->imageAddress);



    prinfo->id = query.lastInsertId().toInt();

    if (!query.exec()) {
        qCritical() << "Product: Error adding product to database:" << query.lastError().text();
        return -1;
    }

    return true;

}




int Product::addProduct(ProductInformation* prinfo) {
    if (!db_) {
        qCritical() << "Product: Database connection not provided!";
        return false;
    }

    QSqlQuery query(*db_);
    QString insertQuery = "INSERT INTO product (product_name, price, discount, quantity, type, brand, size, address_in_store, image_address) "
                          "VALUES (:product_name, :price, :discount, :quantity, :type, :brand, :size, :address_in_store, :image_address)";

    query.prepare(insertQuery);
    query.bindValue(":product_name", prinfo->productName);
    query.bindValue(":price", prinfo->price);
    query.bindValue(":discount", prinfo->discount);
    query.bindValue(":quantity", prinfo->quantity);
    query.bindValue(":type", prinfo->type);
    query.bindValue(":brand", prinfo->brand);
    query.bindValue(":size", prinfo->size);
    query.bindValue(":address_in_store", prinfo->addressInStore);
    query.bindValue(":image_address", prinfo->imageAddress);




    prinfo->id = query.lastInsertId().toInt();

    if (!query.exec()) {
        qCritical() << "Product: Error adding product to database:" << query.lastError().text();
        return -1;
    }

    return prinfo->id;
}

QString Product::getProductName(int id_product) {
    if (!db_) {
        qCritical() << "Product: Database connection not provided!";
        return "";
    }

    QSqlQuery query(*db_);
    QString selectQuery = "SELECT product_name FROM product WHERE id_product = :id_product";

    query.prepare(selectQuery);
    query.bindValue(":id_product", id_product);

    if (!query.exec()) {
        qCritical() << "Product: Error getting product name:" << query.lastError().text();
        return "";
    }

    if (query.next()) {
        return query.value(0).toString();
    } else {
        return "";
    }
}
