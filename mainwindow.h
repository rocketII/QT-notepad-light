#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "about.h"
#include"legal.h"
#include"engine.h"
#include<QMainWindow>
#include<QMenu>
#include<QFormLayout>
#include<QAction>
#include<QTabBar>
#include<QPlainTextEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    legal *showMe;
    //File menu
      QMenu   *fileMenu;
      QAction *openAct;
      QAction *exitAct;
      QAction *saveAct;
      QAction *newTabAct;
      QAction *closeTabAct;
    //Edit menu

      QMenu   *editMenu;
      //QAction *italicAct;
      //QAction *boldAct;
      QAction *copyAct;
      QAction *cutAct;
      QAction *pasteAct;
      //QAction *findAndReplaceAct;
    QAction *settingAct;
    //Magic menu
    QMenu   *magicMenu;
    QAction *toCapitalAct;
    QAction *toLowerCaseAct;
    //QAction *RainBowColorsAct;
    //QAction *hexEditAct;
    QAction *caesarCryptoAct;
    QAction *caesarDeCryptoAct;
   //About menu
    QMenu   *aboutMenu;
    QAction *aboutAct;
    QAction *helpAct;
    QAction *legalAct;
    QAction *HomepageAct;
    QAction *ContactDevAct;
    //QPlainTextEdit doIt; used with some slots f(x)
    QPlainTextEdit *txtEditManagement;//used for text editor. One for each tab.
    QPlainTextEdit *txtEditManagementII;
    QPlainTextEdit *txtEditManagementIII;
    QPlainTextEdit *txtEditManagementIV;
    QPlainTextEdit *txtEditManagementV;
    QPlainTextEdit **txtEditManagementArr;
    //menu end
    QSize plaintxtEdit;
    QSize tabChildSize;
    //tab_1 and tab_2 are in ui->
    QWidget **tabArr;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    //error: 'engine' does not name a type engine *engineRoar;
    engine *engineRoar;
    QWidget *tmp;
    QString tmp1;
    about *aboutPopUp;
    bool usedRm;

    //QString currentFile[5]; used with engine save. maybe QString *currentFile = new QString[5]; max 5 tabs.
    QFormLayout *layout1;
    //void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
    //QTabBar closeThemTabs;
    void menuMagic();
    void actionMagic();
    //QString filesNowInUse[5]; //maximum 5 tabs then on six error.
    int nrOfTabs=0;
    Ui::MainWindow *ui;
signals:
    //void newTab();
    //void cloneTab(int index);
    void closeTab(int index);


private slots:
  //file menu
    void newTabSlot();
    void closeTabSlot();
    void openFileWithMagicSlot();
    void saveSlot();
    //exit uses close() which I don't have to define.
  //edit menu
    void boldSlot();
    void italicSlot();
    void cutSlot();
    void copySlot();
    void pasteSlot();
    void findAndReplaceSlot();
    void settingSlot();
  //magic menu
    void toCapitalSlot();
    void toLowerCaseSlot();
    void rainBowColorsSlot();
    void hexEditSlot();
    void caesarCryptoSlot();
    void caesarDeCryptoSlot();
  //about menu
    void aboutSlot();
    void helpSlot();
    void legalSlot();
    void HomepageSlot();
    void ContactDevSlot();
//public slots:
   // void closeTab(int index = -1);
};

#endif // MAINWINDOW_H
