#include "database.h"

DataBase::DataBase(QSqlDatabase* db){
    this->db = db;
    if (!openConnection()) {
        throw std::runtime_error("Failed to open database connection");
    }
    createTables();
}

DataBase::~DataBase() {
    db->close(); // Close connection in destructor
}

bool DataBase::openConnection() {
    if (!db->open()) {
        qDebug() << "Database connection error:" << db->lastError();
        return false;
    }
    return true;
}

void DataBase::createTables() {
    query.exec("CREATE TABLE customer (id_customer INTEGER PRIMARY KEY AUTOINCREMENT, first_name VARCHAR(30) NOT NULL, last_name VARCHAR(40) NOT NULL, phone_number VARCHAR(11), address TEXT)");
    query.exec("CREATE TABLE product (id_product INTEGER PRIMARY KEY AUTOINCREMENT, product_name VARCHAR(40) NOT NULL, price INTEGER NOT NULL, discount INTEGER, quantity INTEGER NOT NULL, type VARCHAR(30), brand VARCHAR(30), size VARCHAR(20), address_in_store TEXT, image_address TEXT)");
    query.exec("CREATE TABLE orders (id_order INTEGER PRIMARY KEY AUTOINCREMENT, ids_product JSON NOT NULL, prices JSON NOT NULL, discounted_prices JSON NOT NULL, discount_rate INTEGER NOT NULL, order_date TEXT NOT NULL, id_customer INTEGER NOT NULL, FOREIGN KEY (id_customer) REFERENCES customer(id_customer))");
    // ... Add more table definitions if needed
}
