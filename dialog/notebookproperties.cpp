#include "notebookproperties.h"

#include "global.h"
#include "sql/notebooktable.h"

#include <QString>
#include <QIcon>
#include <QGridLayout>
#include <QLabel>

extern Global global;

NotebookProperties::NotebookProperties(QWidget *parent) :
    QDialog(parent)
{
    okPressed = false;
    setWindowTitle(tr("Tag"));
    setWindowIcon(QIcon(":tag.png"));
    setLayout(&grid);

    syncBox.setText(tr("Synchronized"));
    syncBox.setChecked(true);
    syncBox.setEnabled(false);

    connect(&name, SIGNAL(textChanged(const QString&)), this, SLOT(validateInput()));

    nameLabel.setText(tr("Name"));
    queryGrid.addWidget(&nameLabel, 1,1);
    queryGrid.addWidget(&name, 1, 2);
    queryGrid.addWidget(&syncBox, 2,2);
//    queryGrid.setContentsMargins(10, 10,  -10, -10);
    grid.addLayout(&queryGrid,1,1);

    ok.setText(tr("OK"));
    connect(&ok, SIGNAL(clicked()), this, SLOT(okButtonPressed()));
    cancel.setText(tr("Cancel"));
    connect(&cancel, SIGNAL(clicked()), this, SLOT(cancelButtonPressed()));
    buttonGrid.addWidget(&ok, 1, 1);
    buttonGrid.addWidget(&cancel, 1,2);
    grid.addLayout(&buttonGrid,2,1);
}



void NotebookProperties::okButtonPressed() {
    okPressed = true;

    if (this->lid > 0) {
        Notebook book;
        NotebookTable table;
        table.get(book, lid);
        book.name = name.text().trimmed().toStdString();
        book.__isset.name = true;
        table.update(book, true);
        close();
        return;
    }

    // We have a new tag to add
    Notebook book;
    book.name = name.text().trimmed().toStdString();
    QUuid uuid;
    QString g =  uuid.createUuid().toString().replace("{","").replace("}","");
    book.guid = g.toStdString();
    book.__isset.name = true;
    book.__isset.guid = true;
    NotebookTable t;
    t.add(0,book,true);
    close();
}

void NotebookProperties::cancelButtonPressed() {
    okPressed = false;
    close();
}

void NotebookProperties::setLid(qint32 lid) {
    if (lid > 0) {
        this->lid = lid;
        Notebook book;
        NotebookTable table;
        table.get(book, lid);
        originalName = QString::fromStdString(book.name).trimmed();
        name.setText(originalName);
        syncBox.setEnabled(false);
        return;
    }
    this->lid = 0;
    this->setWindowTitle(tr("Add Notebook"));
    originalName = "";
}

void NotebookProperties::validateInput() {
    ok.setEnabled(true);
    if (name.text()=="") {
        ok.setEnabled(false);
        return;
    }
    NotebookTable t;
    QString tag = name.text().trimmed();
    if (t.findByName(tag)>0 && name.text().trimmed() != originalName) {
        ok.setEnabled(false);
        return;
    }
}
