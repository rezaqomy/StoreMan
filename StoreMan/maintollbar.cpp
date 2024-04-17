#include "maintollbar.h"
#include "ui_maintollbar.h"

MainTollBar::MainTollBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainTollBar)
{
    ui->setupUi(this);
}

MainTollBar::~MainTollBar()
{
    delete ui;
}
