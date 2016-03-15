#ifndef ENGINE_H
#define ENGINE_H
#include"mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QFileInfo>
#include<QPlainTextEdit>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
/////////////////////////////////////////////////////////////////
/// \brief The engine class which handles all the "manly" stuff///////////////////7
////////////////////////////////////////////////////////////////
class engine
{
private:
    //int nrOfFilesInUse=0;
    //int nrOfTabsInUse=0;

public:
    engine();
    virtual ~engine();
    //engine(int nrOfFilesInUse, int nrOfTabsInUse){this->nrOfFilesInUse=nrOfFilesInUse; this->nrOfTabsInUse=nrOfTabsInUse;}
    //before closing make sure to ask about save.
    //bool save(QString CurrentFile[], QPlainTextEdit &obj, const QString shittyPath2File);
    //bool beforeClosing(QPlainTextEdit *obj, QString CurrentFile[], const QString shittyPath2File);
    //keep tabs on file modifying
    //void fileGotModed(const QPlainTextEdit &obj);
    //knows which files that are in use
    //void currentFileInUse(const QString fileName, QString tabArr[]);
    //void caesarCrypto(QPlainTextEdit &obj);
    bool fileSave(const QString& shittyPath2File, QPlainTextEdit *obj);
    QString toTxT(QString caesar, int key);
    QString toCaesar(QString txt, int key);
    //bool fileSaveAs(QPlainTextEdit &obj);
    bool fileLoad(const QString &shittyPath2File, QPlainTextEdit *obj);
    //bool CurrentFile(const QString &onlyFileName, QPlainTextEdit &nameOfFile, QString CurrentFile[]);
};

#endif // ENGINE_H
