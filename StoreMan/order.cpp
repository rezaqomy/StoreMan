#include "order.h"

Order::Order(QSqlDatabase* db): db(db)
{
    query = QSqlQuery(*db);
    if (!db) {
        qWarning() << "Product: Database connection not provided!";
    }
}

int Order::addOrder(OrderInformation* ordInfo) {
    QString InsertOrder = "INSERT INTO order(ids_product, prices,  discounted_prices, discount_rate, order_date , id_customer)"
            "VALUES(:ids_product, :prices,  :discounted_prices, :discount_rate, :order_date , :id_customer)";
    query.prepare(InsertOrder);
    query.bindValue(":ids_product", vectorToQString(ordInfo->ids_product));
    query.bindValue(":prices", vectorToQString(ordInfo->prices));
    query.bindValue(":discount_prices", vectorToQString(ordInfo->discounted_prices));
    query.bindValue(":discounted_prices", vectorToQString(ordInfo->discounted_prices));
    query.bindValue(":discount_rate", ordInfo->discount_rate);
    query.bindValue(":order_date", ordInfo->order_date);
    query.bindValue(":id_customer", ordInfo->id_customer);

    ordInfo->id_order = query.lastInsertId().toInt();

    return ordInfo->id_order;
}


QString Order::vectorToQString(QVector<int> vec) noexcept{
    QString json = "{ ";
    for(int i{}; i < vec.size(); i++){
        if (!i == 0){
            json += ", " + QString::number(vec[i]);
        }
        else
            json += QString::number(vec[i]);
    }
    json += "}";
    return json;
}
