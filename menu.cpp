#include "menu.h"
#include "ui_login.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);}

Widget::~Widget()
{
    delete ui;
}
