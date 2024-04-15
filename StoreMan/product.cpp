#include "product.h"
#include "database.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

Product::Product(QSqlDatabase* db) : db_(db) {
    query_ = QSqlQuery();
    if (!db_) {
        qWarning() << "Product: Database connection not provided!";
    }
}

bool Product::addProduct(int id_product, const QString& product_name, int price, int discount, int quantity,
                          const QString& type, const QString& brand, const QString& size,
                          const QString& address_in_store, const QString& image_address) {
    if (!db_) {
        qCritical() << "Product: Database connection not provided!";
        return false;
    }

    QSqlQuery query(*db_);
    QString insertQuery = "INSERT INTO product (id_product, product_name, price, discount, quantity, type, brand, size, address_in_store, image_address) "
                          "VALUES (:id_product, :product_name, :price, :discount, :quantity, :type, :brand, :size, :address_in_store, :image_address)";

    query.prepare(insertQuery);
    query.bindValue(":id_product", id_product);
    query.bindValue(":product_name", product_name);
    query.bindValue(":price", price);
    query.bindValue(":discount", discount);
    query.bindValue(":quantity", quantity);
    query.bindValue(":type", type);
    query.bindValue(":brand", brand);
    query.bindValue(":size", size);
    query.bindValue(":address_in_store", address_in_store);
    query.bindValue(":image_address", image_address);

    if (!query.exec()) {
        qCritical() << "Product: Error adding product to database:" << query.lastError().text();
        return false;
    }

    return true;
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
