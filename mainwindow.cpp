#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsform.h"
#include<QDesktopServices>
#include<QDebug>
#include<qtabbar.h>
#include<QPushButton>
#include<QtWidgets>
#include<qplaintextedit.h>
#include<QPlainTextEdit>
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
    //setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);
    setWindowTitle(tr("notePadLight :: your source of swag::"));
    this->txtEditManagement = new QPlainTextEdit(ui->tab);
    this->txtEditManagementII = new QPlainTextEdit(ui->tab_2);
    setCentralWidget(ui->tabWidget);
    ui->tabWidget->setTabText(ui->tabWidget->indexOf(ui->tab), tr("I changed txt"));
    ui->tabWidget->setTabText(ui->tabWidget->indexOf(ui->tab_2), tr("no name"));
    /*QWidget *tab_3;
    tab_3 = new QWidget();
    tab_3->setObjectName(QStringLiteral("tab_3"));
    ui->tabWidget->addTab(tab_3, QString());
    ui->tabWidget->setTabText(ui->tabWidget->indexOf(tab_3), tr("no name"));
    QWidget *tab_4;
    tab_4 = new QWidget();
    tab_4->setObjectName(QStringLiteral("tab_4"));
    ui->tabWidget->addTab(tab_4, QString());
    QPushButton *button = new QPushButton(QApplication::translate("childwidget", "Press me"), tab_3);
    button->show();
    QPlainTextEdit *testMe= new QPlainTextEdit(tab_4);
    testMe->setMinimumSize(ui->tabWidget->size());
    testMe->show(); */
    actionMagic();
    connect(this, SIGNAL(tabCloseRequested(int)),this, SIGNAL(closeTab(int)));
    menuMagic(); //menu or action first?
    //actionMagic();
    QString infoTxt2Screen = tr("Welcome to my shitty app!!!");
    statusBar()->showMessage(infoTxt2Screen);
    //connect(this, SIGNAL(this->closeThemTabs.tabCloseRequested((int)),this, SIGNAL(this->closeThemTabs.clo(int)));
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
    newTabAct = new QAction(tr("&Open..."), this);
    newTabAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));
    newTabAct->setStatusTip(tr("Find youre file and open it here(must be .md or .txt)"));
    connect(newTabAct, SIGNAL(triggered()), this, SLOT(newTabSlot()));

    closeTabAct = new QAction(tr("&Open..."), this);
    closeTabAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    closeTabAct->setStatusTip(tr("Find youre file and open it here(must be .md or .txt)"));
    connect(closeTabAct, SIGNAL(triggered()), this, SLOT(closeTabSlot()));

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
void MainWindow::newTabSlot()
{
    if(this->nrOfTabs<6)
    {
    //save new tab to some aray

        switch (this->nrOfTabs)
        {
        case 3:
            this->tab_3 = new QWidget();
            this->tab_3->setObjectName(QStringLiteral("tab_3"));
            ui->tabWidget->addTab(this->tab_3, QString());
            this->txtEditManagementIII = new QPlainTextEdit(this->tab_3);
            this->txtEditManagementIII->show();
            break;
        case 4:
            this->tab_4 = new QWidget();
            this->tab_4->setObjectName(QStringLiteral("tab_4"));
            ui->tabWidget->addTab(this->tab_4, QString());
            this->txtEditManagementIV = new QPlainTextEdit(this->tab_4);
            this->txtEditManagementIV->show();
            break;
        case 5:
            this->tab_5 = new QWidget();
            this->tab_5->setObjectName(QStringLiteral("tab_5"));
            ui->tabWidget->addTab(this->tab_5, QString());
            this->txtEditManagementV = new QPlainTextEdit(this->tab_5);
            this->txtEditManagementV->show();
            break;
        default:
            break;
        }
        this->nrOfTabs++;
    }
    qDebug() << "newTabSlot: init";
}

void MainWindow::closeTabSlot()
{
    /*if (QAction *action = qobject_cast<QAction*>(sender()))
    {
        int index = action->data().toInt();
        emit closeTab(index);
    }*/
    if(this->nrOfTabs > 0)
    {

        switch (this->nrOfTabs)
        {
        case 1:
            ui->tabWidget->removeTab(0);
        case 2:
            ui->tabWidget->removeTab(1);
            break;
        case 3:
            ui->tabWidget->removeTab(2);
            break;
        case 4:
            ui->tabWidget->removeTab(3);
            break;
        case 5:
            ui->tabWidget->removeTab(4);
            break;
        default:
            break;
        }
        this->nrOfTabs--;
    }
    qDebug() << "closeTabSlot: init";
}
void MainWindow::openFileWithMagicSlot()
{
    QString path2YourShittyFile = QFileDialog::getOpenFileName(this);
    if(!path2YourShittyFile.isEmpty())
    {
        qDebug() << path2YourShittyFile;
        //should I use current Tab?
        //this->currentFile[this->nrOfTabs]= path2YourShittyFile;
        //how should I handle parameter with 5 paths?
        bool flag = this->engineRoar->fileLoad(path2YourShittyFile, this->txtEditManagement);
        if(flag)
            ui->statusBar->showMessage(tr("Succes!!"));
        else
            ui->statusBar->showMessage(tr("Fail"));
    } //Use engine class for this file path.
    else
        qDebug() << "you shitty file are totz empty";
}

void MainWindow::saveSlot()
{
    qDebug() << "Save: init";
    QString pathWhereISaveYourFile2 = QFileDialog::getSaveFileName(this);
    if(!pathWhereISaveYourFile2.isEmpty())
    {
        qDebug() << pathWhereISaveYourFile2;
        bool flag = this->engineRoar->fileSave(pathWhereISaveYourFile2,this->txtEditManagement);
        if(flag)
            statusBar()->showMessage(tr("Saved File "));
        else
            statusBar()->showMessage(tr("Saved File = fail :( ) "));
    }   // use engine class to handle filestream.
    else
        qDebug() << "you shitty file path are totz empty";
}

//Edit menu slots

void MainWindow::boldSlot()
{
    //use  this->txtEditManagement-> try to change txt content in widget.
    qDebug() << "Bold: init";
}

void MainWindow::italicSlot()
{
    //ui->plainTextEdit->
    //this->txtEditManagement->
    qDebug() << "Italic: init";
    //ui->plainTextEdit->;
}

void MainWindow::cutSlot()
{
    qDebug() << "cut: init";
    //this->txtEditManagement->cut();
    this->txtEditManagement->cut();
}
void MainWindow::copySlot()
{
    qDebug() << "copy: init";
    //this->doIt.copy();
    //this->txtEditManagement->copy();
    this->txtEditManagement->copy();
}

void MainWindow::pasteSlot()
{
    qDebug() << "paste: init";
    //this->doIt.paste();
    //this->txtEditManagement->paste();
     this->txtEditManagement->paste();
}

void MainWindow::findAndReplaceSlot()
{
    qDebug() << "find and replace: init";

}
//connect to settingsform
void MainWindow::settingSlot()
{
    qDebug() << "settings: init";
    SettingsForm *mySettings;
    mySettings = new SettingsForm;
    mySettings->setWindowTitle(tr("::notepad light::shitty settings::"));
    mySettings->show();

}

//magic menu slots
void MainWindow::toCapitalSlot()
{
    //this->txtEditManagement->
    qDebug() << "to capital: init";

}
void MainWindow::toLowerCaseSlot()
{
    qDebug() << "to capital: init";

}

void MainWindow::rainBowColorsSlot()
{
    qDebug() << "rainbow colors: init";

}
void MainWindow::hexEditSlot()
{
    qDebug() << "Hex editing: init";

}

void MainWindow::caesarCryptoSlot()
{
    qDebug() << "Caesar encryption: init";

}
//about menu slots

void MainWindow::aboutSlot()
{
    qDebug() << "About: init";
}

void MainWindow::helpSlot()
{
    qDebug() << "Heĺp: init";

}

void MainWindow::legalSlot()
{
    qDebug() << "legal: init";
}

void MainWindow::HomepageSlot()
{
    qDebug() << "www: init";
    QDesktopServices::openUrl(QUrl("http://vangandr.synology.me", QUrl::TolerantMode));
}

void MainWindow::ContactDevSlot()
{
    qDebug() << "Contact Dev: init";
    QDesktopServices::openUrl(QUrl("mailto:rocket@dflund.se?subject=Test&body=Just a test", QUrl::TolerantMode));
}

MainWindow::~MainWindow()
{
    qDebug() << "Destructor: init";
    QString infoTxt2Screen = tr("Closing your shitty app!!!... and you probably can't read this...");
    statusBar()->showMessage(infoTxt2Screen);
    delete ui;
}
/*
void MainWindow::closeEvent(QCloseEvent *event)

{
    //*&
    bool engine::beforeClosing(QPlainTextEdit *obj, QString CurrentFile[], const QString shittyPath2File);
    if (this->engineRoar->beforeClosing(ui->plainTextEdit), this->currentFile, )
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}*/
//draw,io class diagram.
