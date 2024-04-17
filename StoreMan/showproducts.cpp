#include "showproducts.h"
#include "ui_showproducts.h"
#include "product.h"
#include "QPushButton"

ShowProducts::ShowProducts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowProducts)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("store.db");
    Product pr(&db);
    QVector<ProductInformation> vec = pr.getAllProduct();



}

ShowProducts::~ShowProducts()
{
    delete ui;
}
