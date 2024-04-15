#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QSqlQuery>
#include "database.h"

class Product
{
private:
    QSqlDatabase* db_;
    QSqlQuery query_;
public:
    int addProduct(const QString& product_name, int price, int discount, int quantity,
                              const QString& type, const QString& brand, const QString& size,
                              const QString& address_in_store, const QString& image_address);
    QString getProductName(int id_product);
    Product(QSqlDatabase* db);
};

#endif // PRODUCT_H
