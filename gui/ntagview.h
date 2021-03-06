#ifndef NTAGVIEW_H
#define NTAGVIEW_H
#include "ntagviewitem.h"
#include "treewidgeteditor.h"

#include <QTreeWidget>
#include <QShortcut>
#include <QMenu>
#include <QAction>

class NTagView : public QTreeWidget
{
    Q_OBJECT
private:
    NTagViewItem *root;
    QHash<qint32, NTagViewItem*> dataStore;
    virtual void mousePressEvent(QMouseEvent *event);
    int filterPosition;
    void copyTreeItem(QTreeWidgetItem *source, QTreeWidgetItem *target);
    QMenu context;
    QAction *addAction;
    QAction *propertiesAction;
    QAction *deleteAction;
    QAction *renameAction;
    QShortcut *renameShortcut;
    QShortcut *addShortcut;
    QShortcut *deleteShortcut;
    TreeWidgetEditor *editor;


private slots:
    int calculateHeightRec(QTreeWidgetItem * item);
    void calculateHeight();
    void editComplete();

public:
    explicit NTagView(QWidget *parent = 0);
    ~NTagView();
    void resetSize();
    void updateSelection();
    void loadData();
    bool rebuildTagTreeNeeded;
    void dragEnterEvent(QDragEnterEvent *event);
    bool dropMimeData(QTreeWidgetItem *parent, int index, const QMimeData *data, Qt::DropAction action);
    void mouseMoveEvent(QMouseEvent *event);
    void dropEvent(QDropEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);


signals:
    void updateSelectionRequested();
    void tagRenamed(qint32 lid, QString oldName, QString newName);
    void tagDeleted(qint32 lid, QString name);
    void tagAdded(qint32 lid);

public slots:
    void tagUpdated(qint32 lid, QString name);
    void rebuildTree();
    void buildSelection();
    void addNewTag(qint32 lid);
    void addRequested();
    void propertiesRequested();
    void deleteRequested();
    void renameRequested();

protected:
    void dragMoveEvent(QDragMoveEvent *event);

};

#endif // NTAGVIEW_H
