#include "customer.h"

Customer::Customer(QSqlDatabase* db): db(db)
{
    query = QSqlQuery(*db);
    if (!db) {
        qWarning() << "Product: Database connection not provided!";
    }
}


int Customer::addCustomer(CustomerInformation* cusInfo){
    QString insertQuery = "INSERT INTO customer(first_name, last_name, phone_number, address)"
            "VALUES (:first_name, :last_name, :phone_number, :address)";

    query.prepare(insertQuery);
    query.bindValue(":first-name", cusInfo->firs_name);
    query.bindValue(":last_name", cusInfo->Last_name);
    query.bindValue(":phone_number", cusInfo->phone_number);
    query.bindValue(":address", cusInfo->address);


    cusInfo->id = query.lastInsertId().toInt();

    if (!query.exec()) {
        qCritical() << "Product: Error adding product to database:" << query.lastError().text();
        return -1;
    }

    return cusInfo->id;
}




CustomerInformation Customer::getCustomer(int id) {
    CustomerInformation cusInfo;

    QString selectQuery = "SELECT * FROM customer WHERE id_customer = id"
            "VALUES (:id)";
    query.prepare(selectQuery);
    query.bindValue(":id", id);

    query.next();

    cusInfo.id = id;
    cusInfo.firs_name = query.value(0).toString();
    cusInfo.Last_name = query.value(1).toString();
    cusInfo.phone_number = query.value(2).toString();
    cusInfo.address = query.value(3).toString();

    if (!query.exec()) {
        qCritical() << "Product: Error adding product to database:" << query.lastError().text();
        return cusInfo;
    }


    return cusInfo;

}
