#ifndef NTABWIDGET_H
#define NTABWIDGET_H

#include "gui/nbrowserwindow.h"

#include <QTabBar>
#include <QStackedWidget>

class NTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NTabWidget();
    ~NTabWidget();
    QTabBar tabBar;
    QVBoxLayout vboxlayout;
    QList<NBrowserWindow *> *browserList;
    void addBrowser(NBrowserWindow *v, QString title);
    void setTitle(QString t);
    void setTitle(qint32 index, QString title);
    QStackedWidget stack;
    NBrowserWindow *currentBrowser();


signals:
    void updateSelectionRequested();
    void noteUpdated(qint32);
    void tagCreated(qint32);

public slots:
    void closeTab(int index);
    void moveTab(int to, int from);
    void openNote(int lid, bool newWindow);
    void tagCreationSignaled(qint32 lid);

private slots:
    void noteUpdateSignaled(qint32);

};

#endif // NTABWIDGET_H
