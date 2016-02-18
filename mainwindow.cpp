#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //http://doc.qt.io/qt-4.8/qdesktopservices.html#openUrl
    QDesktopServices::openUrl(QUrl("http://bth.se", QUrl::TolerantMode));
    QDesktopServices::openUrl(QUrl("mailto:rocket@dflund.se?subject=Test&body=Just a test", QUrl::TolerantMode));


}

MainWindow::~MainWindow()
{
    delete ui;
}
