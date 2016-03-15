#include "legal.h"
#include "ui_legal.h"

legal::legal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::legal)
{
    ui->setupUi(this);
}

legal::~legal()
{
    delete ui;
}

void legal::on_pushButton_clicked()
{
    close();
}
