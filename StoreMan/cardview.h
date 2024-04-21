#ifndef CARDVIEW_H
#define CARDVIEW_H
#include <QLabel>
#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <product.h>
#include <order.h>

class CardView : public QWidget
{
public:
    CardView(ProductInformation* productInfo, OrderInformation* orderInfo);

private:
    QLabel* nameLabel;
    QLabel* imageLabel;
    QLabel* priceLabel;
    QLabel* discountLabel;
    QLabel* finalPrice;
    QLabel* quantityLabel;
    QPushButton* deleteLabel;
    QGridLayout* grideLayout;
    QGridLayout* grideLayoutbuy;
    QWidget* widgetBuy;
    QStackedWidget* stackedBuy;
    QLineEdit* numberProductLineEdit;
    QPushButton* decrease;
    QPushButton* increase;
    QPushButton* addToCartButton;
    OrderInformation* orderInfo;
    ProductInformation* productInfo;
    int indexProduct;
    void on_addToCartButton_clicked();
    void on_increase_clicked();
    void lineEditTextChanged();
    void on_decrease_clicked();
    void setGridLayout();
    void updateBuyButton();
};

#endif // CARDVIEW_H
