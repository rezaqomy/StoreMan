#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QStandardItem>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QSqlDatabase* db, QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_products_button_2_clicked();

    void on_products_button_clicked();

    void on_add_products_button_clicked();

    void on_add_product_button_2_clicked();

    void on_Turnover_button_2_clicked();

    void on_Turnover_button_clicked();

    void on_orders_button_clicked();

    void on_orders_button_2_clicked();

    void on_order_button_clicked();

    void on_order_button_2_clicked();

    void on_add_new_product_button_clicked();

private:
    QSqlDatabase* db;
    void product_clicked();
    void add_product_clicked();
    void order_clicked();
    void orders_clicked();
    void turnover_clicked();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
