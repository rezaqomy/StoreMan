#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include "database.h"

class Product
{
private:

public:
    void addQuery(int id_product,QString product_name, int price, int discount, int quantity, QString type, QString brand, QString size, QString address_in_store, QString image_address);
    Product();
};

#endif // PRODUCT_H
