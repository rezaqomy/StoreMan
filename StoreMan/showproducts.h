#ifndef SHOWPRODUCTS_H
#define SHOWPRODUCTS_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class ShowProducts;
}

class ShowProducts : public QWidget
{
    Q_OBJECT

public:
    explicit ShowProducts(QWidget *parent = nullptr);
    ~ShowProducts();


private:
    Ui::ShowProducts *ui;
};

#endif // SHOWPRODUCTS_H
