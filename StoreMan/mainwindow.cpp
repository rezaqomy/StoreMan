#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "showproducts.h"
#include "cardview.h"
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
    QGridLayout* gridLayout = new QGridLayout();
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* window = new QWidget();

    window->setWindowTitle("Product List");
    for (int i = 0; i < prsInfo.size(); ++i) {
        CardView* cardView = new CardView(prsInfo[i].productName, "stor/stats.png", prsInfo[i].price);
        // cardView->setStyleSheet("border-radius:40.px; background-color: rgb(201, 214, 223);");
        gridLayout->addWidget(cardView, i / 3, i % 3);
        qDebug() << prsInfo[i].productName << prsInfo[i].price;
    }
    ui->all_product_widget->setLayout(gridLayout);


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

