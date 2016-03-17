Open local browser
QDesktopServices::openUrl(QUrl("file:///C:/Documents and Settings/All Users/Desktop", QUrl::TolerantMode));

QTABWidget klassen har en del coola medlemsfunktioner.

QFileDialog är bra för att få en file path i QString.

QString går att få i std string.

Forms skapar alla pekare auto i en ui_<formname.ui>.h  använd alt+pekare för åtkomst.
class QPlainTextEdit bör hanteras i QTabs


//multi tabs
Use QAction for creating your '+' icon for creating new tabs.
Create an action and set a suitable '+' for it.
Then use QTabWidget::addAction to add it to your tab widget.
Connect the action's triggered signal to the slot which creates the new tab.

As for making the tabs closable use the method QTabBar::setTabsClosable(bool).

//QFile or filestream?
kolla exempel.

Auto resize? try layout as parent for tabwidget and its children.

==================================================================

        tab closse, create.
        QTabBar.h / QTabWidget
==================================================================


 enum QTabBar::SelectionBehavior
---
    tabsClosable : bool
    This property holds whether or not a tab bar should place close buttons on each tab.

    When tabsClosable is set to true a close button will appear on the tab on either the left or right hand side depending upon the style. When the button is clicked the tab the signal tabCloseRequested will be emitted.

    By default the value is false.
 ---

---
void QTabBar::tabCloseRequested(int index)
This signal is emitted when the close button on a tab is clicked. The index is the index that should be removed.
use with removeTab(int index).
---

---
QTabBar::addTab(const QString & text)
Adds a new tab with text text. Returns the new tab's index.
---

---
QWidget * QTabWidget::currentWidget() const
Returns a pointer to the page currently being displayed by the tab dialog. The tab dialog does its best to make sure that this value is never 0 (but if you try hard enough, it can be).
---
void QTabWidget::removeTab(int index)
Removes the tab at position index from this stack of widgets. The page widget itself is not deleted.
---
[signal]
void QTabWidget::tabBarClicked(int index)
This signal is emitted when user clicks on a tab at an index.

index refers to the tab clicked, or -1 if no tab is under the cursor.
---


                               ********* ideas*********
in constructor-----
menu.addAction(tr("New &Tab"), this, SIGNAL(newTab()), QKeySequence::AddTab);

QAction *action = menu.addAction(tr("&Close Tab"),this, SLOT(closeTab()), QKeySequence::Close);

QAction *action = menu.addAction(tr("Clone Tab"),this, SLOT(cloneTab()));

connect(this, SIGNAL(tabCloseRequested(int)),this, SIGNAL(closeTab(int)));

(från QTabBar <qtabbar.h>) setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);
QAction *m_tabBar;
connect(m_tabBar, SIGNAL(newTab()), this, SLOT(newTab()));
connect(m_tabBar, SIGNAL(closeTab(int)), this, SLOT(closeTab(int)));
connect(m_tabBar, SIGNAL(cloneTab(int)), this, SLOT(cloneTab(int)));
end in construct----



custom header


signals:
    void newTab();
    void cloneTab(int index);
    void closeTab(int index);
private slots:
    void cloneTab();
    void closeTab();
public slots:
    void cloneTab(int index = -1);
    void closeTab(int index = -1);
private:
    QAction *m_newTabAction;
    QAction *m_closeTabAction;

end custom header

void TabBar::cloneTab()
{
    if (QAction *action = qobject_cast<QAction*>(sender())) {
        int index = action->data().toInt();
        emit cloneTab(index);
    }
}
void TabBar::closeTab()
{
    if (QAction *action = qobject_cast<QAction*>(sender())) {
        int index = action->data().toInt();
        emit closeTab(index); //void closeTab(int index);
    }
}
==================end tabs==========================


draw.io klass diagram
