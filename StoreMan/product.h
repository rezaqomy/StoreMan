#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QSqlQuery>
#include "database.h"

struct ProductInformation {
    int id;
    QString productName;
    int price;
    int discount;
    int quantity;
    QString type;
    QString brand;
    QString size;
    QString addressInStore;
    QString imageAddress;
};


class Product
{
private:
    QSqlDatabase* db_;
    QSqlQuery query_;
public:
    int addProduct(ProductInformation* prinfo);
    ProductInformation* getProduct(int id);
    bool updateValues(ProductInformation* prinfo);
    QString getProductName(int id_product);
    QVector<ProductInformation> getAllProduct();
    Product(QSqlDatabase* db);
};

#endif // PRODUCT_H
