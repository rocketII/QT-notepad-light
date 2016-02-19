#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDesktopServices>
#include<QFileDialog> //används för att öppna en fil med filbläddrare som kan ge en path.
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //http://doc.qt.io/qt-4.8/qdesktopservices.html#openUrl
    QDesktopServices::openUrl(QUrl("http://bth.se", QUrl::TolerantMode));
    QDesktopServices::openUrl(QUrl("mailto:rocket@dflund.se?subject=Test&body=Just a test", QUrl::TolerantMode));
    ui->actionContact_Developer;
    ui->tabWidget->addTab();
   QFileDialog test;
   //qDebug() << test.show();
   //qDebug() << test.getSaveFileName();
}
//QT har hashning googla.
//qt lexer lexin
//Qstring hej = "hej";
//hej.number()
//(int)hej[o];
//(int)'H'; base 16
//execlp("c++ -flagga -flagga > compiler.txt")
MainWindow::~MainWindow()
{
    delete ui;
}
