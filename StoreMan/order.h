#ifndef ORDER_H
#define ORDER_H

#include <QVector>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

struct OrderInformation {
  int id_order;
  QVector<int> ids_product;
  QVector<int> prices;
  QVector<int> discounted_prices;
  int discount_rate;
  QString order_date;
  int id_customer;
};


class Order
{
private:
    QSqlDatabase* db;
    QSqlQuery query;
    QString vectorToQString(QVector<int> vec) noexcept;

public:
    Order(QSqlDatabase* db);
    int addOrder(OrderInformation* ordInfo);
    QVector<OrderInformation> getCustomerOrders(int customer_id);
    QVector<OrderInformation> getOredersLastMonth();
    QVector<OrderInformation> getAllOrders();
};

#endif // ORDER_H
