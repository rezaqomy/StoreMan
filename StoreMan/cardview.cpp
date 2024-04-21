#include "cardview.h"

void CardView::on_addToCartButton_clicked()
{
    orderInfo->ids_product.push_back(productInfo->id);
    orderInfo->quantity.push_back(1);
    orderInfo->discounted_prices.push_back(productInfo->discount);
    grideLayout->removeWidget(addToCartButton);

    updateBuyButton();
    setLayout(grideLayout);
}

void CardView::on_increase_clicked()
{
    indexProduct = orderInfo->ids_product.indexOf(productInfo->id);
    if (indexProduct == -1 or indexProduct >= orderInfo->ids_product.size()){
        return;
    }
    qDebug() << orderInfo->quantity[indexProduct];
    orderInfo->quantity[indexProduct]++;
    numberProductLineEdit->setText(QString::number(orderInfo->quantity[indexProduct]));
    updateBuyButton();
}

void CardView::lineEditTextChanged()
{
    int quantity =  numberProductLineEdit->text().toInt();
    if (quantity <= productInfo->quantity) {
        orderInfo->quantity[orderInfo->ids_product.indexOf(productInfo->id)] = quantity;
        qDebug() << "ok" << productInfo->quantity;
    }
    else{
        orderInfo->quantity[orderInfo->ids_product.indexOf(productInfo->id)] = productInfo->quantity;
        numberProductLineEdit->setText(QString::number(productInfo->quantity));
    }
    qDebug() << orderInfo->quantity[orderInfo->ids_product.indexOf(productInfo->id)];
}

void CardView::on_decrease_clicked()
{
    indexProduct = orderInfo->ids_product.indexOf(productInfo->id);
    if (indexProduct == -1 or indexProduct >= orderInfo->ids_product.size()){
        return;
    }
    orderInfo->quantity[indexProduct]--;
    if (orderInfo->quantity[indexProduct] == 0) {
        orderInfo->ids_product.remove(indexProduct);
        //orderInfo->prices.remove(indexProduct);
        orderInfo->discounted_prices.remove(indexProduct);
        orderInfo->quantity.remove(indexProduct);
    } else
        numberProductLineEdit->setText(QString::number(orderInfo->quantity[indexProduct]));
    updateBuyButton();
}


void CardView::updateBuyButton()
{
    if(orderInfo->ids_product.indexOf(productInfo->id) < 0){
        addToCartButton->show();
        grideLayout->addWidget(addToCartButton, 4, 0, 1, 7);
        decrease->hide();
        numberProductLineEdit->hide();
        increase->hide();
        qDebug() << "if worked";

    } else {
        increase->show();
        numberProductLineEdit->show();
        decrease->show();
        addToCartButton->hide();
        grideLayout->addWidget(decrease, 4, 0, 1, 1);
        grideLayout->addWidget(numberProductLineEdit, 4, 1, 1, 4);
        grideLayout->addWidget(increase, 4, 5, 1, 1);
    }


}

void CardView::setGridLayout()
{

    grideLayout = new QGridLayout();
    grideLayout->addWidget(nameLabel,0, 0, 1, 6);
    grideLayout->addWidget(deleteLabel, 0, 5, 1, 1);
    grideLayout->addWidget(imageLabel, 1, 0, 3, 3);
    if (productInfo->discount != 0){
        grideLayout->addWidget(priceLabel, 1, 4, 1, 3);
        grideLayout->addWidget(discountLabel, 2, 4, 1, 3);
        grideLayout->addWidget(finalPrice, 3, 4, 1, 3);
    } else
        grideLayout->addWidget(priceLabel, 2, 4, 1, 3);
    grideLayout->addWidget(quantityLabel, 5, 0);
    updateBuyButton();


    setLayout(grideLayout);
}

CardView::CardView(ProductInformation* productInfo, OrderInformation* orderInfo):productInfo(productInfo), orderInfo(orderInfo)
{
    nameLabel = new QLabel(productInfo->productName);


    if (productInfo->imageAddress == "")
        productInfo->imageAddress = ":/stor/imageNotFound.jpg";
    imageLabel = new QLabel();
    imageLabel->setPixmap(QPixmap(productInfo->imageAddress));
    imageLabel->setFixedSize(100, 100);

    if (productInfo->discount != 0){
        priceLabel = new QLabel(QString("<html><del><b>price: </b><font style = 'color:rgb(255, 100, 100)' > %1 </font></del></html>").arg(productInfo->price));
        discountLabel = new QLabel(QString("<font style = 'color:rgb(255, 100, 100)' ><b>- discount:</b> %1 </font>").arg(productInfo->discount));
        finalPrice = new QLabel(QString("<b>Final Price: </b> %1 ").arg(productInfo->price - productInfo->discount));
    } else
        priceLabel = new QLabel(QString("<b>price: </b>")  + QString::number(productInfo->price));

    addToCartButton = new QPushButton("add to cart");
    addToCartButton->connect(addToCartButton, &QPushButton::clicked, this, &CardView::on_addToCartButton_clicked);

    quantityLabel = new QLabel;

    quantityLabel->setText(QString::number(productInfo->quantity));


    increase = new QPushButton("+");
    increase->connect(increase, &QPushButton::clicked, this, &CardView::on_increase_clicked);
    decrease = new QPushButton("-");
    decrease->connect(decrease, &QPushButton::clicked, this, &CardView::on_decrease_clicked);
    numberProductLineEdit = new QLineEdit();
    numberProductLineEdit->setText("1");
    numberProductLineEdit->connect(numberProductLineEdit, &QLineEdit::textChanged, this, &CardView::lineEditTextChanged);


    deleteLabel = new QPushButton();
    deleteLabel->setStyleSheet("background-image:url(':/stor/delete.png'); border:none;");





    setGridLayout();
}

