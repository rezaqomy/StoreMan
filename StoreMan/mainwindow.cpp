#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "showproducts.h"
#include "product.h"

MainWindow::MainWindow(QSqlDatabase* db, QWidget *parent)
    : QMainWindow(parent), db(db)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->icon_name_widget->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}


/* methods clicked Menu_Button */

void MainWindow::product_clicked(){
    /* TODO */
    // ADD CARD VIEW HORIZANTALI
    // SHOW THE IMAGE IN CARD VIEW


    Product pr(db);
    QVector<ProductInformation> prsInfo = pr.getAllProduct();
    QStandardItemModel *model = new QStandardItemModel(prsInfo.size(), 10, this);

    for (int i = 0; i < prsInfo.size(); ++i) {
        model->setData(model->index(i, 0), QString("Item name = %1,price = %2, id = %3, quantity = %4").arg(prsInfo[i].productName).arg(prsInfo[i].price).arg(prsInfo[i].id).arg(prsInfo[i].quantity));
    }

    ui->all_product_listView->setModel(model);
    prsInfo = pr.getAllProduct("quantity < 11 AND quantity != 0", "quantity DESC");
    model = new QStandardItemModel(prsInfo.size(), 10, this);

    for (int i = 0; i < prsInfo.size(); ++i) {
        model->setData(model->index(i, 0), QString("Item name = %1,price = %2, id = %3, quantity = %4").arg(prsInfo[i].productName).arg(prsInfo[i].price).arg(prsInfo[i].id).arg(prsInfo[i].quantity));
    }

    ui->running_out_listView->setModel(model);

    prsInfo = pr.getAllProduct("quantity = 0", "quantity DESC");
    model = new QStandardItemModel(prsInfo.size(), 10, this);

    for (int i = 0; i < prsInfo.size(); ++i) {
        model->setData(model->index(i, 0), QString("Item name = %1,price = %2, id = %3, quantity = %4").arg(prsInfo[i].productName).arg(prsInfo[i].price).arg(prsInfo[i].id).arg(prsInfo[i].quantity));
    }

    ui->finished_product_listView->setModel(model);

    ui->Screen_widget->setCurrentIndex(0);
}

void MainWindow::add_product_clicked(){
    ui->Screen_widget->setCurrentIndex(1);
}

void MainWindow::order_clicked(){
    ui->Screen_widget->setCurrentIndex(2);
}

void MainWindow::orders_clicked(){
    ui->Screen_widget->setCurrentIndex(3);
}

void MainWindow::turnover_clicked(){
    ui->Screen_widget->setCurrentIndex(4);
}


/* methods CONNECT TO BUTTON clicked Menu_Button */

void MainWindow::on_products_button_2_clicked()
{
    product_clicked();
}


void MainWindow::on_products_button_clicked()
{
    product_clicked();
}


void MainWindow::on_add_products_button_clicked()
{
    add_product_clicked();
}


void MainWindow::on_add_product_button_2_clicked()
{
    add_product_clicked();
}


void MainWindow::on_Turnover_button_2_clicked()
{
    turnover_clicked();
}


void MainWindow::on_Turnover_button_clicked()
{
    turnover_clicked();
}


void MainWindow::on_orders_button_clicked()
{
    orders_clicked();
}


void MainWindow::on_orders_button_2_clicked()
{
    orders_clicked();
}


void MainWindow::on_order_button_clicked()
{
    order_clicked();
}


void MainWindow::on_order_button_2_clicked()
{
    order_clicked();
}


void MainWindow::on_add_new_product_button_clicked()
{
    ProductInformation pr;
    pr.productName = ui->product_name_lineEdit->text();
    pr.price = ui->price_lineEdit->text().toInt();
    pr.discount = ui->discount_lineEdit->text().toUInt();
    pr.quantity = ui->quantity_lineEdit->text().toInt();
    pr.type = ui->type_lineEdit->text();
    pr.brand = ui->brand_lineEdit->text();
    pr.size = ui->size_lineEdit->text();
    pr.addressInStore = ui->address_in_store_lineEdit->text();
    pr.imageAddress = ui->image_address_lineEdit->text();

    Product product(db);
    product.addProduct(&pr);

    /*   TODO */
    // DESIGN UI
    // ADD CHECK FUNCTION
    // ADD CONFRIM WINDOW
    // OPEN NEW WINDOW TO SELECT IMAGE ADDRESS

}

