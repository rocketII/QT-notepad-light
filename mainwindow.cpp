#include "mainwindow.h"
#include"engine.h"
#include"about.h"
#include"legal.h"
#include "ui_mainwindow.h"
#include "settingsform.h"
#include<QDesktopServices>
#include<QDebug>
#include<QFormLayout>
#include<qtabbar.h>
#include<QPushButton>
#include<QtWidgets>
#include<qplaintextedit.h>
#include<QPlainTextEdit>
#include<QTextDocument>
#include<QFont>
//for menubar and dialogs.
#include<QFileDialog> //används för att öppna en fil med filbläddrare som kan ge en path.
#include<QMenuBar>
#include<QAction>

////////////////////////////////////////////////////////
/////////  IDEAS
/// ///////////////////////////////////////////////////

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
    this->usedRm = false;
    ui->setupUi(this);
    setCentralWidget(ui->tabWidget);
    //tab button
    //QToolButton *closeButton = new QToolButton(this);
    //closeButton->setIcon(QIcon(":/images/close_tab.png"));
    //closeButton->adjustSize();
    //connect(closeButton, SIGNAL(clicked()), this, SLOT(closeCurrentTab()));
    //tab button end
    /*
     * QPlainTextEdit monoEdit;
        QTextDocument *doc = monoEdit.document();
        QFont font = doc->defaultFont();
        font.setFamily("Courier New");
        doc->setDefaultFont(font);
        monoEdit.setPlainText
     */
    //size for tabs and plaintextedit obj:s
    this->plaintxtEdit = ui->tabWidget->size();
    this->plaintxtEdit.setHeight((this->plaintxtEdit.height()-60));//23
    this->plaintxtEdit.setWidth((this->plaintxtEdit.width()-2));//-2
    this->tabChildSize = ui->tabWidget->size();
    this->tabChildSize.setHeight((this->tabChildSize.height()-0));
    this->tabChildSize.setWidth((this->tabChildSize.width()-0));
    //////////////////////////////////////////////////////////////

    setWindowTitle(tr("notePadLight :: your source of swag::"));

    this->txtEditManagementArr = new QPlainTextEdit*[5];
    this->tabArr = new QWidget*[5];
    this->txtEditManagement = new QPlainTextEdit(ui->tab);
    this->txtEditManagementArr[0] = this->txtEditManagement;
    this->tabArr[0] = ui->tab;
    this->tabArr[1] = ui->tab_2;
    this->tabArr[2] = this->tab_3;
    this->tabArr[3] = this->tab_4;
    this->tabArr[4] = this->tab_5;
    ui->tab->setMinimumSize(this->tabChildSize);
    ui->tab->setMaximumSize(this->tabChildSize);
    this->txtEditManagementArr[0]->setMaximumSize(this->plaintxtEdit);
    this->txtEditManagementArr[0]->setMinimumSize(this->plaintxtEdit);

    //QTextDocument *doc = this->txtEditManagement->document();

    /*
     *  Lucida Console
        webdings
        Times New Roman
        Courier New
     */
    QFont font;
    font.setFamily("Times New Roman");
    this->txtEditManagement->setFont(font);
    this->txtEditManagementII = new QPlainTextEdit(ui->tab_2);
    this->txtEditManagementArr[1] = this->txtEditManagementII;
    this->tabArr[1]->setMinimumSize(this->tabChildSize);
    this->tabArr[1]->setMaximumSize(this->tabChildSize);
    this->txtEditManagementArr[1]->setMinimumSize(this->plaintxtEdit);
    this->txtEditManagementArr[1]->setMaximumSize(this->plaintxtEdit);

    this->nrOfTabs++;this->nrOfTabs++;

    ui->tabWidget->setTabText(ui->tabWidget->indexOf(ui->tab), tr("myTab 0"));

    qDebug() << ui->tabWidget->currentIndex();
    qDebug() <<"current Tabindex: "<< ui->tabWidget->indexOf(ui->tab_2);
    ui->tabWidget->setTabText(ui->tabWidget->indexOf(ui->tab_2), tr("myTab 1"));
    qDebug() <<"current TabIndex: "<< ui->tabWidget->currentIndex();

    actionMagic();
    menuMagic(); //menu or action first?
    this->aboutPopUp = new about;
    QString infoTxt2Screen = tr("Welcome to my shitty app!!!");
    statusBar()->showMessage(infoTxt2Screen);
}

void MainWindow::menuMagic()
{
    //file
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newTabAct);
    fileMenu->addAction(closeTabAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    //edit

    editMenu = menuBar()->addMenu(tr("&Edit"));
    //editMenu->addAction(boldAct);
    //editMenu->addAction(italicAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    //editMenu->addAction(findAndReplaceAct);
    editMenu->addAction(settingAct);
    //magic
    magicMenu = menuBar()->addMenu(tr("&magic"));
    magicMenu->addAction(toCapitalAct);
    magicMenu->addAction(toLowerCaseAct);
    //magicMenu->addAction(RainBowColorsAct);
    magicMenu->addAction(caesarCryptoAct);
    magicMenu->addAction(caesarDeCryptoAct);
    //magicMenu->addAction(hexEditAct);

    //about
    aboutMenu = menuBar()->addMenu(tr("&about"));
    aboutMenu->addAction(aboutAct);
    aboutMenu->addAction(legalAct);
    aboutMenu->addSeparator();
    aboutMenu->addAction(HomepageAct);
    aboutMenu->addAction(ContactDevAct);

                 //actionQuit
}
//menu items
void MainWindow::actionMagic()
{
    //File menu
    //repeat for each menu item
    newTabAct = new QAction(tr("&NewTab..."), this);
    newTabAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));
    newTabAct->setStatusTip(tr("Find youre file and open it here(must be .md or .txt)"));
    connect(newTabAct, SIGNAL(triggered()), this, SLOT(newTabSlot()));

    closeTabAct = new QAction(tr("&closeTab..."), this);
    closeTabAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
    closeTabAct->setStatusTip(tr("less tabs"));
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
    /*boldAct = new QAction(tr("&bold"), this);
    boldAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
    boldAct->setStatusTip(tr("bold text"));
    connect(boldAct, SIGNAL(triggered()), this, SLOT(boldSlot()));
    */

    /*italicAct = new QAction(tr("&Italic"), this);
    italicAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_I));
    italicAct->setStatusTip(tr("I feel dizzy"));
    connect(italicAct, SIGNAL(triggered()), this, SLOT(italicSlot()));
*/

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
    /*
    findAndReplaceAct = new QAction(tr("&Find & replace"), this);
    findAndReplaceAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
    findAndReplaceAct->setStatusTip(tr("replace word with another"));
    connect(findAndReplaceAct, SIGNAL(triggered()), this, SLOT(findAndReplaceSlot()));

*/
    settingAct = new QAction(tr("&Settings"), this);
    settingAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U));
    settingAct->setStatusTip(tr("make system wide changes"));
    connect(settingAct, SIGNAL(triggered()), this, SLOT(settingSlot()));
    ///
//worst programming language youtube.
    ///
  //magic menu
    toCapitalAct = new QAction(tr("&Caps for everyone"), this);
    toCapitalAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    toCapitalAct->setStatusTip(tr("Your are feeling tired and hungry and want to quit... let me change something ;)"));
    connect(toCapitalAct, SIGNAL(triggered()), this, SLOT(toCapitalSlot()));
    toLowerCaseAct= new QAction(tr("&to lower"), this);
    toLowerCaseAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
    toLowerCaseAct->setStatusTip(tr("everything to lowercase ;)"));
    connect(toLowerCaseAct, SIGNAL(triggered()), this, SLOT(toLowerCaseSlot()));
    /*RainBowColorsAct= new QAction(tr("&NyanCat mode"), this);
    RainBowColorsAct->setStatusTip(tr("Your are feeling tired and hungry and want to quit...but I can still entertain. :3"));
    connect(RainBowColorsAct, SIGNAL(triggered()), this, SLOT(rainBowColorsSlot()));
*/

    caesarCryptoAct= new QAction(tr("&EncryptWithCaesar"), this);
    caesarCryptoAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    caesarCryptoAct->setStatusTip(tr("It's old it's shitty and I won't be safe even if you can't read it. :("));
    connect(caesarCryptoAct, SIGNAL(triggered()), this, SLOT(caesarCryptoSlot()));
    caesarDeCryptoAct= new QAction(tr("&DecryptWithCaesar"), this);
    caesarDeCryptoAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Comma));
    caesarDeCryptoAct->setStatusTip(tr("It's old it's shitty and I won't be safe even if you can't read it. :("));
    connect(caesarDeCryptoAct, SIGNAL(triggered()), this, SLOT(caesarDeCryptoSlot()));
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
    if(this->usedRm)
    {
        this->nrOfTabs++;
        this->usedRm=false;
    }


    if(this->nrOfTabs<5)
    {
    //save new tab to some aray

        switch (this->nrOfTabs)
        {
        case 0:
            this->tabArr[0] = new QWidget();
            this->tabArr[0]->setObjectName(QStringLiteral("tab"));
            ui->tabWidget->addTab(this->tabArr[0], QString("mytab 0"));
            this->txtEditManagement = new QPlainTextEdit(this->tabArr[0]);
            this->txtEditManagement->show();
            this->txtEditManagementArr[0] = this->txtEditManagement;
            this->tabArr[0]->setMinimumSize(this->tabChildSize);
            this->tabArr[0]->setMaximumSize(this->tabChildSize);
            this->txtEditManagementArr[0]->setMinimumSize(this->plaintxtEdit);
            this->txtEditManagementArr[0]->setMaximumSize(this->plaintxtEdit);
            this->tmp= ui->tabWidget->currentWidget();
            qDebug() <<"indexOf tmp:"<< ui->tabWidget->indexOf(this->tmp);
            qDebug() << ui->tabWidget->currentIndex();
            qDebug() <<"index of tab1"<< ui->tabWidget->indexOf(this->tabArr[0]);
            break;
        case 1:
            this->tabArr[1] = new QWidget();
            this->tabArr[1]->setObjectName(QStringLiteral("tab_2"));
            ui->tabWidget->addTab(this->tabArr[1], QString("myTab 1"));
            this->txtEditManagementII = new QPlainTextEdit(this->tabArr[1]);
            this->txtEditManagementII->show();
            this->txtEditManagementArr[1] = this->txtEditManagementII;
            this->tabArr[1]->setMinimumSize(this->tabChildSize);
            this->tabArr[1]->setMaximumSize(this->tabChildSize);
            this->txtEditManagementArr[1]->setMinimumSize(this->plaintxtEdit);
            this->txtEditManagementArr[1]->setMaximumSize(this->plaintxtEdit);
            this->tmp= ui->tabWidget->currentWidget();
            qDebug() <<"indexOf tmp:"<< ui->tabWidget->indexOf(this->tmp);
            qDebug() << ui->tabWidget->currentIndex();
            qDebug() <<"index of tab2"<< ui->tabWidget->indexOf(this->tabArr[1]);
            break;
        case 2:
            this->tabArr[2] = new QWidget();
            this->tabArr[2]->setObjectName(QStringLiteral("tab_3"));
            ui->tabWidget->addTab(this->tabArr[2], QString("mytab 2"));
            this->txtEditManagementIII = new QPlainTextEdit(this->tabArr[2]);
            this->txtEditManagementIII->show();
            this->txtEditManagementArr[2] = this->txtEditManagementIII;
            this->tabArr[2]->setMinimumSize(this->tabChildSize);
            this->tabArr[2]->setMaximumSize(this->tabChildSize);
            this->txtEditManagementArr[2]->setMinimumSize(this->plaintxtEdit);
            this->txtEditManagementArr[2]->setMaximumSize(this->plaintxtEdit);
            this->tmp= ui->tabWidget->currentWidget();
            qDebug() <<"indexOf tmp:"<< ui->tabWidget->indexOf(this->tmp);
            qDebug() << ui->tabWidget->currentIndex();
            qDebug() <<"index of tab3"<< ui->tabWidget->indexOf(this->tabArr[2]);
            break;
        case 3:
            this->tabArr[3] = new QWidget();
            this->tabArr[3]->setObjectName(QStringLiteral("tab_4"));
            ui->tabWidget->addTab(this->tabArr[3], QString("myTab 3"));
            this->txtEditManagementIV = new QPlainTextEdit(this->tabArr[3]);
            this->txtEditManagementIV->show();
            this->txtEditManagementArr[3] = this->txtEditManagementIV;
            this->tabArr[3]->setMinimumSize(this->tabChildSize);
            this->tabArr[3]->setMaximumSize(this->tabChildSize);
            this->txtEditManagementArr[3]->setMinimumSize(this->plaintxtEdit);
            this->txtEditManagementArr[3]->setMaximumSize(this->plaintxtEdit);
            this->tmp= ui->tabWidget->currentWidget();
            qDebug() <<"indexOf tmp:"<< ui->tabWidget->indexOf(this->tmp);
            qDebug() << ui->tabWidget->currentIndex();
            qDebug() <<"index of tab4"<< ui->tabWidget->indexOf(this->tabArr[3]);
            break;
        case 4:
            this->tabArr[4] = new QWidget();
            this->tabArr[4]->setObjectName(QStringLiteral("tab_5"));
            ui->tabWidget->addTab(this->tabArr[4], QString("myTab 4"));
            this->txtEditManagementV = new QPlainTextEdit(this->tabArr[4]);
            this->txtEditManagementV->show();
            this->txtEditManagementArr[4] = this->txtEditManagementV;
            this->tabArr[4]->setMinimumSize(this->tabChildSize);
            this->tabArr[4]->setMaximumSize(this->tabChildSize);
            this->txtEditManagementArr[4]->setMinimumSize(this->plaintxtEdit);
            this->txtEditManagementArr[4]->setMaximumSize(this->plaintxtEdit);
            qDebug() <<"tab current index: "<< ui->tabWidget->currentIndex();
            this->tmp= ui->tabWidget->currentWidget();
            qDebug() <<"index of tmp:"<< ui->tabWidget->indexOf(this->tmp);
            qDebug() <<"current tab got index: "<< ui->tabWidget->currentWidget();
            qDebug() <<"index of tab5"<< ui->tabWidget->indexOf(this->tabArr[4]);
            break;
        default:
            break;
        }
        this->nrOfTabs++;
    }
    qDebug() << "newTabSlot: init, nrOfTabs" << nrOfTabs;
}

void MainWindow::closeTabSlot()
{
    ui->tabWidget->removeTab(this->nrOfTabs--);
    this->usedRm=true;
    qDebug() << "closeTabSlot: init, nrOfTabs"<< this->nrOfTabs;
}
void MainWindow::openFileWithMagicSlot()
{
    QString path2YourShittyFile = QFileDialog::getOpenFileName(this);
    if(!path2YourShittyFile.isEmpty())
    {
        qDebug() << path2YourShittyFile;
        this->tmp= ui->tabWidget->currentWidget();
        bool flag = this->engineRoar->fileLoad(path2YourShittyFile, this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]);
        if(flag)
        {
            ui->statusBar->showMessage(tr("Succes!!"));
            setWindowTitle(path2YourShittyFile);
            ui->tabWidget->setTabText(ui->tabWidget->indexOf(this->tabArr[ui->tabWidget->indexOf(tmp)]), QFileInfo(path2YourShittyFile).fileName());
        }
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
        this->tmp= ui->tabWidget->currentWidget();
        bool flag = this->engineRoar->fileSave(pathWhereISaveYourFile2,this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]);
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
    //QString format =this->txtEditManagement->toPlainText();
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
    this->tmp= ui->tabWidget->currentWidget();
    this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->cut();
}
void MainWindow::copySlot()
{
    qDebug() << "copy: init";
    //this->doIt.copy();
    //this->txtEditManagement->copy();
    this->tmp= ui->tabWidget->currentWidget();
    this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->copy();
}

void MainWindow::pasteSlot()
{
    qDebug() << "paste: init";
    //this->doIt.paste();
    //this->txtEditManagement->paste();
    this->tmp= ui->tabWidget->currentWidget();
    this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->paste();
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
    this->tmp= ui->tabWidget->currentWidget();
    this->tmp1 = this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->toPlainText();
    this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->setPlainText(this->tmp1.toUpper());
}
void MainWindow::toLowerCaseSlot()
{

    qDebug() << "to capital: init";
    this->tmp = ui->tabWidget->currentWidget();
    this->tmp1 = this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->toPlainText();
    this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->setPlainText(tmp1.toLower());
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
    int key = 4;
    this->tmp = ui->tabWidget->currentWidget();
    this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->setPlainText(this->engineRoar->toCaesar(this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->toPlainText(), key));
}
void MainWindow::caesarDeCryptoSlot()
{
    qDebug() << "Caesar encryption: init";
    int key = 4;
    this->tmp = ui->tabWidget->currentWidget();
    this->txtEditManagementArr[ui->tabWidget->indexOf(this->tmp)]->setPlainText(this->engineRoar->toTxT(this->txtEditManagementArr[ui->tabWidget->indexOf(tmp)]->toPlainText(), key));
}

//about menu slots

void MainWindow::aboutSlot()
{
    qDebug() << "About: init";
    this->aboutPopUp->setWindowTitle(QString("::about shitty pad::"));
    this->aboutPopUp->show();
    //QDesktopServices::openUrl(QUrl("http://vangandr.synology.me/about.html", QUrl::TolerantMode));
}

void MainWindow::helpSlot()
{
    qDebug() << "Heĺp: init";


}

void MainWindow::legalSlot()
{
    qDebug() << "legalSlot(): init";
    legal *showMe;
    showMe = new legal;
    showMe->setWindowTitle(tr("::notepad light::shitty legal txt::"));
    showMe->show();
    delete showMe;
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
    //delete [] this->txtEditManagementArr;
    //delete [] this->tabArr;
    //for (int var = 0; var < this->nrOfTabs; ++var)
    {
      //  delete this->tabArr[var];
      //  delete this->txtEditManagementArr[var];
    }
    delete[] this->txtEditManagementArr;
    delete [] this->tabArr;
    delete this->aboutPopUp;
    QString infoTxt2Screen = tr("Closing your shitty app!!!... and you probably can't read this...");
    statusBar()->showMessage(infoTxt2Screen);
    delete ui;
}

//draw,io class diagram.
