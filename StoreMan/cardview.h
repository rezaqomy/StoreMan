#ifndef CARDVIEW_H
#define CARDVIEW_H
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>

class CardView : public QWidget
{
public:
    CardView(QString productName, QString productImage, int productPrice);

private:
    QLabel* nameLabel;
    QLabel* imageLabel;
    QLabel* priceLabel;
    QVBoxLayout* vBoxLayout;

};

#endif // CARDVIEW_H
