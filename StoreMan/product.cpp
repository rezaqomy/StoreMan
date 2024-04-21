#include "product.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

Product::Product(QSqlDatabase* db) : db_(db) {
    query = QSqlQuery(*db_);
    if (!db_) {
        qWarning() << "Product: Database connection not provided!";
    }
}



void Product::queryToVector(QVector<ProductInformation>* allProduct)
{
    while (query.next()) {
        ProductInformation prinfo;

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


        allProduct->push_back(prinfo);
    }
}

bool Product::deleteProduct(int id)
{
    QString deleteQuery = "DELETE FROM product WHERE id = :id"
            "VALUES (:id)";
    query.prepare(deleteQuery);
    query.bindValue(":id", id);
}

QVector<ProductInformation> Product::getAllProduct() {
    QVector<ProductInformation> allProduct;


    query.exec("SELECT * FROM product");

    queryToVector(&allProduct);


    return allProduct;
}

QVector<ProductInformation> Product::getAllProduct(QString sortBy)
{
    QVector<ProductInformation> allProduct;
    QString selectQuery = QString("SELECT * FROM product ORDER BY %1").arg(sortBy);


    query.exec(selectQuery);

    queryToVector(&allProduct);


    return allProduct;
}

QVector<ProductInformation> Product::getAllProduct(QString sortBy, int limit)
{
    QVector<ProductInformation> allProduct;
    QString selectQuery = QString("SELECT * FROM product ORDER BY %1 LIMIT %2").arg(sortBy).arg(limit);


    query.exec(selectQuery);

    queryToVector(&allProduct);


    return allProduct;
}

QVector<ProductInformation> Product::getAllProduct(QString sortBy, int limit, int offset)
{
    QVector<ProductInformation> allProduct;
    QString selectQuery = QString("SELECT * FROM product ORDER BY %1 LIMIT %2 OFFSET %3").arg(sortBy).arg(limit).arg(offset);


    query.exec(selectQuery);

    queryToVector(&allProduct);


    return allProduct;
}

QVector<ProductInformation> Product::getAllProduct(QString where, QString sortBy)
{
    QVector<ProductInformation> allProduct;
    QString selectQuery = QString("SELECT * FROM product WHERE %1 ORDER BY %2").arg(where).arg(sortBy);


    query.exec(selectQuery);

    queryToVector(&allProduct);


    return allProduct;
}

QVector<ProductInformation> Product::getAllProduct(QString where, QString sortBy, int limit)
{
    QVector<ProductInformation> allProduct;
    QString selectQuery = QString("SELECT * FROM product WHERE %1 ORDER BY %2 LIMIT %3").arg(where).arg(sortBy).arg(limit);


    query.exec(selectQuery);

    queryToVector(&allProduct);


    return allProduct;
}

QVector<ProductInformation> Product::getAllProduct(QString where, QString sortBy, int limit, int offset)
{
    QVector<ProductInformation> allProduct;
    QString selectQuery = QString("SELECT * FROM product WHERE %1 ORDER BY %2 LIMIT %3 OFFSET %4").arg(where).arg(sortBy).arg(limit).arg(offset);


    query.exec(selectQuery);

    queryToVector(&allProduct);


    return allProduct;
}

QVector<ProductInformation> Product::getAllProduct(int limit, int offset)
{
    QVector<ProductInformation> allProduct;
    QString selectQuery = QString("SELECT * FROM product LIMIT %1 OFFSET %2").arg(limit).arg(offset);


    query.exec(selectQuery);

    queryToVector(&allProduct);


    return allProduct;
}

ProductInformation* Product::getProduct(int id){
    ProductInformation prinfo;




    QString idStr = QString::number(id);
    QString queryStr = "SELECT id FROM product WHERE id = :id";
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



    return true;

}




int Product::addProduct(ProductInformation* prinfo) {



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
