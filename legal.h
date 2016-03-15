#ifndef LEGAL_H
#define LEGAL_H

#include <QDialog>

namespace Ui {
class legal;
}

class legal : public QDialog
{
    Q_OBJECT

public:
    explicit legal(QWidget *parent = 0);
    ~legal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::legal *ui;
};

#endif // LEGAL_H
