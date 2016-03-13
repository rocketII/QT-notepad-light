#include"mainwindow.h"
#include"engine.h"
#include<qmainwindow.h>
#include<QObject>
#include<QMessageBox>
#include<QDialog>
///*
///
/*
void engine::caesarCrypto(QPlainTextEdit &obj)
{
    //string arr[]={obj.toPlainText()};
    //loop through every character and increase ascii value by k steps which gets saved into obj.
}
*/

bool engine::fileSave(const QString& shittyPath2File, QPlainTextEdit *obj)
{
    //QString onlyFileName = QFileInfo(shittyPath2File).fileName();
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QFile openFile(shittyPath2File);
    if (!openFile.open( QFile::Text | QFile::WriteOnly ))
    {
        return false;
    }

    QTextStream toHardDrive(&openFile);



    toHardDrive << obj->toPlainText();

    QApplication::restoreOverrideCursor();
    //engine::CurrentFile(shittyPath2File, onlyFileName, CurrentFile);

    //statusBar()->showMessage(QObject::tr("Saved File ").arg(shittyPath2File).QObject::tr("\n which is good! :3"));
    return true;
}

/*
bool engine::fileSaveAs(QPlainTextEdit &obj, QString CurrentFile[])
{
    QFileDialog openWindow(this);
    QStringList holderOfChoice;
    openWindow.setAcceptMode(QFileDialog::AcceptSave);
    if(openWindow.show())
        holderOfChoice = openWindow.selectedFiles();
    else
    {
        return false;
    }
    return fileSave(holderOfChoice, obj, CurrentFile);
}
*/

bool engine::fileLoad(const QString &shittyPath2File, QPlainTextEdit *obj)
{
    QFile fileLoad(shittyPath2File);
    if (!fileLoad.open(QFile::ReadOnly | QFile::Text)) {
        //QMessageBox::warning(this, QObject::tr("Application"),QObject::tr("Cannot read file %1:\n%2.").arg(QFileInfo(shittyPath2File).fileName()).arg(file.errorString()));
        return false;
    }
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QTextStream inStream(&fileLoad);


    obj->setPlainText(inStream.readAll());

    QApplication::restoreOverrideCursor();

    //CurrentFile(QFileInfo(shittyPath2File).fileName(), shittyPath2File);
    //statusBar()->showMessage(QObject::tr("File loaded: %1").arg(shittyPath2File), -1);
    return true;
}




//remember tab with file should should recive new name
/*
bool engine::CurrentFile(const QString &onlyFileName, QPlainTextEdit &nameOfFile, QString CurrentFile[])
{
    currentFileInUse(onlyFileName, arr);
    nameOfFile->document()->setModified(false);
    setWindowModified(false);

    QString shownName = arr[this->nrOfFilesInUse-1];
    if (arr[this->nrOfFilesInUse-1].isEmpty())
        shownName = "no_title.txt";
    setWindowFilePath(shownName);
    return true;
}
*/

/*
void engine::currentFileInUse(const QString fileName, QString tabArr[])
{
    if(this->nrOfFilesInUse == 5)
    {
         QMessageBox::warning(this, QObject::tr("No more than 5 tabs"));
    }
    else
        arr[this->nrOfFilesInUse++]= fileName;

}*/

/*void engine::fileGotModed(const QPlainTextEdit &obj)
{
    //keep track of unsaved changes
    QWidget::setWindowModified(obj.document()->isModified());
}*/
/*bool engine::beforeClosing(QPlainTextEdit *obj, QString CurrentFile[], const QString shittyPath2File)
{
    if(obj->document()->isModified())
    {
        QMessageBox::StandardButton answear;
        answear = QMessageBox::warning(this,QObject::tr("Application"),QObject::tr("The document has been modified.\n""Do you want to save your changes?"),QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (answear == QMessageBox::Save)
            return save(CurrentFile, obj, shittyPath2File);
        else if (answear == QMessageBox::Cancel)
            return false;
    }
}*/
//CurrentFile should handle array of files
/*
bool engine::save(QString CurrentFile[], QPlainTextEdit &obj, const QString shittyPath2File)
{
    if (CurrentFile.isEmpty())
    {
        return fileSaveAs(obj);
    }
    else
    {
        return fileSave( shittyPath2File, obj, CurrentFile);
    }
} */
//*/
