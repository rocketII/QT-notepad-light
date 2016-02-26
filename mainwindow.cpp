#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDesktopServices>
#include<QDebug>
//for menubar and dialogs.
#include<QFileDialog> //används för att öppna en fil med filbläddrare som kan ge en path.
#include<QMenuBar>
#include<QAction>

////////////////////////////////////////////////////////
/////////  IDEAS
/// ///////////////////////////////////////////////////
//QT har hashning googla.
//qt lexer lexin
//Qstring hej = "hej";
//hej.number()
//(int)hej[o];
//(int)'H'; base 16
//execlp("c++ -flagga -flagga > compiler.txt")


//http://doc.qt.io/qt-4.8/qdesktopservices.html#openUrl
// QDesktopServices::openUrl(QUrl("http://bth.se", QUrl::TolerantMode));
// QDesktopServices::openUrl(QUrl("mailto:rocket@dflund.se?subject=Test&body=Just a test", QUrl::TolerantMode));
//ui->actionContact_Developer;
//ui->tabWidget->addTab(new QWidget,new QIcon, new QString);

//////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("notePadLight :: your source of swag::"));
    actionMagic();
    menuMagic(); //menu or action first?
    //actionMagic();
    QString infoTxt2Screen = tr("Welcome to my shitty app!!!");
    statusBar()->showMessage(infoTxt2Screen);
    //resize(500,500);
}

void MainWindow::menuMagic()
{
    //file
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    //edit

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(boldAct);
    editMenu->addAction(italicAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addAction(findAndReplaceAct);
    editMenu->addAction(settingAct);
    //magic
    magicMenu = menuBar()->addMenu(tr("&magic"));
    /*magicMenu->addAction(toCapitalAct);
    magicMenu->addAction(toLowerCaseAct);
    magicMenu->addAction(RainBowColorsAct);
    magicMenu->addAction(caesarCryptoAct);
    magicMenu->addAction(hexEditAct);*/

    //about
    aboutMenu = menuBar()->addMenu(tr("&about"));
    aboutMenu->addAction(aboutAct);
    aboutMenu->addAction(legalAct);
    aboutMenu->addSeparator();
    aboutMenu->addAction(HomepageAct);
    aboutMenu->addAction(ContactDevAct);

                 //actionQuit
}

void MainWindow::actionMagic()
{
    //File menu
    //repeat for each menu item
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    openAct->setStatusTip(tr("Find youre file and open it here(must be .md or .txt)"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFileWithMagicSlot()));

    saveAct = new QAction(tr("&Save file"), this);
    saveAct->setShortcut(Qt::CTRL + Qt::Key_S);
    saveAct->setStatusTip(tr("Before the power is gone and your file with it! :("));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveSlot()));

    exitAct = new QAction(tr("&Exit shitty app..."), this);
    exitAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
    exitAct->setStatusTip(tr("Your are feeling tired and hungry and want to quit... nows your chance! ;)"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
  //Edit
    boldAct = new QAction(tr("&bold"), this);
    boldAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
    boldAct->setStatusTip(tr("bold text"));
    connect(boldAct, SIGNAL(triggered()), this, SLOT(boldSlot()));
    italicAct = new QAction(tr("&Italic"), this);
    italicAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_I));
    italicAct->setStatusTip(tr("I feel dizzy"));
    connect(italicAct, SIGNAL(triggered()), this, SLOT(italicSlot()));

    copyAct = new QAction(tr("&copy"), this);
    copyAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    copyAct->setStatusTip(tr("copy your marked txt;)"));
    connect(copyAct, SIGNAL(triggered()), this, SLOT(copySlot()));
    cutAct = new QAction(tr("&Cut"), this);
    cutAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    cutAct->setStatusTip(tr("Cut and then paste ;)"));
    connect(cutAct, SIGNAL(triggered()), this, SLOT(cutSlot()));
    pasteAct = new QAction(tr("&paste..."), this);
    pasteAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    pasteAct->setStatusTip(tr("make sure you alredy copied or cuted something ;)"));
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(pasteSlot()));
    findAndReplaceAct = new QAction(tr("&Find & replace"), this);
    findAndReplaceAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
    findAndReplaceAct->setStatusTip(tr("replace word with another"));
    connect(findAndReplaceAct, SIGNAL(triggered()), this, SLOT(findAndReplaceSlot()));
    settingAct = new QAction(tr("&Settings"), this);
    settingAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U));
    settingAct->setStatusTip(tr("make system wide changes"));
    connect(settingAct, SIGNAL(triggered()), this, SLOT(settingSlot()));
  //magic menu
    toCapitalAct = new QAction(tr("&Caps for everyone"), this);
    toCapitalAct->setStatusTip(tr("Your are feeling tired and hungry and want to quit... let me change something ;)"));
    connect(toCapitalAct, SIGNAL(triggered()), this, SLOT(toCapitalSlot()));
    toLowerCaseAct= new QAction(tr("&to lower"), this);
    toLowerCaseAct->setStatusTip(tr("everything to lowercase ;)"));
    connect(toLowerCaseAct, SIGNAL(triggered()), this, SLOT(toLowerCaseSlot()));
    RainBowColorsAct= new QAction(tr("&NyanCat mode"), this);
    RainBowColorsAct->setStatusTip(tr("Your are feeling tired and hungry and want to quit...but I can still entertain. :3"));
    connect(RainBowColorsAct, SIGNAL(triggered()), this, SLOT(rainBowColorsSlot()));
    caesarCryptoAct= new QAction(tr("&EncryptWithCaesar"), this);
    caesarCryptoAct->setStatusTip(tr("It's old it's shitty and I won't be safe even if you can't read it. :("));
    connect(caesarCryptoAct, SIGNAL(triggered()), this, SLOT(caesarCryptoSlot()));
  //About menu
    aboutAct= new QAction(tr("&about"), this);
    aboutAct->setStatusTip(tr("what you need to know about the app and versions"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(aboutSlot()));
    helpAct= new QAction(tr("&help"), this);
    helpAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));
    helpAct->setStatusTip(tr("Explain, when your need it :("));
    connect(helpAct, SIGNAL(triggered()), this, SLOT(helpSlot()));
    legalAct= new QAction(tr("&legal"), this);
    legalAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
    legalAct->setStatusTip(tr("It's old it's shitty and I won't be safe even if you can't read it. :("));
    connect(legalAct, SIGNAL(triggered()), this, SLOT(legalSlot()));
    HomepageAct= new QAction(tr("&home page"), this);
    HomepageAct->setStatusTip(tr("Visit dev home page"));
    connect(HomepageAct, SIGNAL(triggered()), this, SLOT(HomepageSlot()));
    ContactDevAct= new QAction(tr("&Contact Dev"), this);
    ContactDevAct->setStatusTip(tr("Here's your way of telling me how much you hate my programming skill and layout. You can also wish for future enchantments."));
    connect(ContactDevAct, SIGNAL(triggered()), this, SLOT(ContactDevSlot()));

}
////////////////////////////////////////////////////////////
//slots
///////////////////////////////////////////////////////////

//file menu slots
void MainWindow::openFileWithMagicSlot()
{
    QString path2YourShittyFile = QFileDialog::getOpenFileName(this);
    if(!path2YourShittyFile.isEmpty())
        qDebug() << path2YourShittyFile;
    else
        qDebug() << "you shitty file are totz empty";
}

void MainWindow::saveSlot()
{
    ;
}

//Edit menu slots

void MainWindow::boldSlot()
{

}

void MainWindow::italicSlot()
{

}

void MainWindow::cutSlot()
{

}
void MainWindow::copySlot()
{

}

void MainWindow::pasteSlot()
{

}

void MainWindow::findAndReplaceSlot()
{

}
//connect to settingsform
void MainWindow::settingSlot()
{

}

//magic menu slots
void MainWindow::toCapitalSlot()
{

}
void MainWindow::toLowerCaseSlot()
{

}

void MainWindow::rainBowColorsSlot()
{

}
void MainWindow::hexEditSlot()
{

}

void MainWindow::caesarCryptoSlot()
{

}
//about menu slots

void MainWindow::aboutSlot()
{
    qDebug() << "hello";
}

void MainWindow::helpSlot()
{

}

void MainWindow::legalSlot()
{

}

void MainWindow::HomepageSlot()
{
    QDesktopServices::openUrl(QUrl("http://vangandr.synology.me", QUrl::TolerantMode));
}

void MainWindow::ContactDevSlot()
{
    QDesktopServices::openUrl(QUrl("mailto:rocket@dflund.se?subject=Test&body=Just a test", QUrl::TolerantMode));
}

MainWindow::~MainWindow()
{
    QString infoTxt2Screen = tr("Closing your shitty app!!!");
    statusBar()->showMessage(infoTxt2Screen);
    delete ui;
}
//draw,io class diagram.
