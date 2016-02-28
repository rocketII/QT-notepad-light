#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QWidget>
#include<QAction>

namespace Ui {
class SettingsForm;
}

class SettingsForm : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsForm(QWidget *parent = 0);
    ~SettingsForm();
private slots:
    void saveSettingsSlot();
    void noSaveSettingsSlot();

private:
    Ui::SettingsForm *ui;
    /* se ui forms
    QAction saveSettingsAct;
    QAction noSaveSettingsAct;
    */

};

#endif // SETTINGSFORM_H
