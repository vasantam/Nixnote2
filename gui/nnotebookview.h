#ifndef NNOTEBOOKVIEW_H
#define NNOTEBOOKVIEW_H
#include "nnotebookviewitem.h"
#include "treewidgeteditor.h"
#include <QTreeWidget>
#include <QMenu>
#include <QShortcut>

class NNotebookView : public QTreeWidget
{
    Q_OBJECT
private:
    NNotebookViewItem *root;
    QHash<qint32, NNotebookViewItem*> dataStore;
    QHash<QString, NNotebookViewItem*> stackStore;
    virtual void mousePressEvent(QMouseEvent *event);
    int filterPosition;
    QMenu context;
    QMenu *stackMenu;
    QAction *addAction;
    QAction *propertiesAction;
    QAction *deleteAction;
    QAction *renameAction;
    QAction *newStackAction;
    QAction *removeFromStackAction;
    QShortcut *renameShortcut;
    QShortcut *addShortcut;
    QShortcut *deleteShortcut;
    TreeWidgetEditor *editor;
    QHash<QString, QAction*> menuData;
    void sortStackMenu();


private slots:
    int calculateHeightRec(QTreeWidgetItem * item);
    void calculateHeight();
    void editComplete();

public:
    explicit NNotebookView(QWidget *parent = 0);
    ~NNotebookView();
    void resetSize();
    void updateSelection();
    void loadData();
    bool rebuildNotebookTreeNeeded;
    void contextMenuEvent(QContextMenuEvent *event);

signals:
    void updateSelectionRequested();
    void notebookRenamed(qint32 lid, QString oldName, QString newName);
    void notebookDeleted(qint32 lid, QString name);
    void notebookAdded(qint32 lid);
    void stackAdded(QString name);
    void stackDeleted(QString name);
    void stackRenamed(QString oldName, QString newName);

public slots:
    void notebookUpdated(qint32 lid, QString name);
    void rebuildTree();
    void buildSelection();
    void addRequested();
    void propertiesRequested();
    void deleteRequested();
    void renameRequested();
    void moveToStackRequested();
    void moveToNewStackRequested();
    void removeFromStackRequested();
};

#endif // NNOTEBOOKVIEW_H
