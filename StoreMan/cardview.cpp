#include "cardview.h"

CardView::CardView(QString productName, QString productImage, int productPrice)
{
   nameLabel = new QLabel(productName);
   nameLabel->setFont(QFont("Arial", 16));


   imageLabel = new QLabel();
   imageLabel->setPixmap(QPixmap(productImage));
   imageLabel->setFixedSize(100, 100);


   priceLabel = new QLabel(QString::number(productPrice));
   priceLabel->setFont(QFont("Arial", 12));


   vBoxLayout = new QVBoxLayout();
   vBoxLayout->addWidget(nameLabel);
   vBoxLayout->addWidget(imageLabel);
   vBoxLayout->addWidget(priceLabel);


   setLayout(vBoxLayout);
}
