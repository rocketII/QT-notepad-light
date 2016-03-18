#include "about.h"
#include "ui_about.h"
#include<QDebug>

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    qDebug() <<"about() : init";
    ui->setupUi(this);
    ui->textBrowser->setText(stringKeep());
}

about::~about()
{
    delete ui;
}

const QString about::stringKeep()
{
    return QString(this->stringForward.c_str());
}
