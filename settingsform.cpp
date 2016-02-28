#include "settingsform.h"
#include "ui_settingsform.h"
#include<QDebug>
#include<string.h>
#include<QString>
#include<iostream>

SettingsForm::SettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsForm)
{
    ui->setupUi(this);
    connect(ui->saveSettingsButtom,SIGNAL(pressed()),this,SLOT(saveSettingsSlot()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(noSaveSettingsSlot()));
}
void SettingsForm::saveSettingsSlot()
{
    /*
     * Legend
     * BG color
     * box 1 white
     * box 2 Black
     * box 3 Navy blue
     * box 4 Green
     * Text color
     * box 5 Black
     * box 6 Green
     * box 7 White
     * box 8 Navy blue
    */
  qDebug() << "save settings: init";
  //gather radio boxes status, string to engine class function.
  bool checkBox1 = ui->radioButton->isChecked();
  qDebug()<<"box1"<<checkBox1;
  bool checkBox2 = ui->radioButton_2->isChecked();
  qDebug() <<"box2"<<checkBox2;
  bool checkBox3 = ui->radioButton_3->isChecked();
  qDebug() <<"box3"<<checkBox3;
  bool checkBox4 = ui->radioButton_4->isChecked();
   qDebug() <<"box4"<<checkBox4;
  bool checkBox5 = ui->radioButton_5->isChecked();
   qDebug() <<"box5"<<checkBox5;
  bool checkBox6 = ui->radioButton_6->isChecked();
   qDebug() <<"box6"<<checkBox6;
  bool checkBox7 = ui->radioButton_7->isChecked();
   qDebug() <<"box7"<<checkBox7;
  bool checkBox8 = ui->radioButton_8->isChecked();
   qDebug() <<"box8"<<checkBox8;
   QString path2Font = ui->lineEditPath2Font->text();
   qDebug() <<"QString from lineEdit class: "<< path2Font;
   std::string cuzIneedStd = path2Font.toStdString();
   qDebug() <<"std string got "<<QString::fromUtf8(cuzIneedStd.c_str());
   //
   close();
}
void SettingsForm::noSaveSettingsSlot()
{
    qDebug() << "exit without saving settings: init";
    close();
}

SettingsForm::~SettingsForm()
{
    delete ui;
}
