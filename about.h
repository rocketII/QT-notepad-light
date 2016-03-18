#ifndef ABOUT_H
#define ABOUT_H
#include"string"
#include <QDialog>
using namespace std;
namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = 0);
    ~about();

private:
    const string stringForward =  "Shitty notepad light made by RLB is not finished yet. maybe 2020? more Security features? ;) ";
    const QString stringKeep();
    Ui::about *ui;
};

#endif // ABOUT_H
