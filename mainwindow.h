#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QMenu>
#include<QAction>
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
    void menuMagic();
    void actionMagic();

    Ui::MainWindow *ui;
  //File menu
    QMenu   *fileMenu;
    QAction *openAct;
    QAction *exitAct;
    QAction *saveAct;
  //Edit menu

    QMenu   *editMenu;
    QAction *italicAct;
    QAction *boldAct;
    QAction *copyAct;
    QAction *cutAct;
    QAction *pasteAct;
    QAction *findAndReplaceAct;
    QAction *settingAct;
  //Magic menu
    QMenu   *magicMenu;
    QAction *toCapitalAct;
    QAction *toLowerCaseAct;
    QAction *RainBowColorsAct;
    QAction *hexEditAct;
    QAction *caesarCryptoAct;
  //About menu
    QMenu   *aboutMenu;
    QAction *aboutAct;
    QAction *helpAct;
    QAction *legalAct;
    QAction *HomepageAct;
    QAction *ContactDevAct;


private slots:
  //file menu
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
  //about menu
    void aboutSlot();
    void helpSlot();
    void legalSlot();
    void HomepageSlot();
    void ContactDevSlot();
};

#endif // MAINWINDOW_H
