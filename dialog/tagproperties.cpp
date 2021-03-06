#include "tagproperties.h"

#include "global.h"
#include "sql/tagtable.h"

#include <QString>
#include <QIcon>
#include <QGridLayout>
#include <QLabel>

extern Global global;

TagProperties::TagProperties(QWidget *parent) :
    QDialog(parent)
{
    okPressed = false;
    setWindowTitle(tr("Tag"));
    setWindowIcon(QIcon(":tag.png"));
    setLayout(&grid);

    connect(&name, SIGNAL(textChanged(const QString&)), this, SLOT(validateInput()));

    nameLabel.setText(tr("Name"));
    queryGrid.addWidget(&nameLabel, 1,1);
    queryGrid.addWidget(&name, 1, 2);
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



void TagProperties::okButtonPressed() {
    okPressed = true;

    if (this->lid > 0) {
        Tag tag;
        TagTable table;
        table.get(tag, lid);
        tag.name = this->name.text().trimmed().toStdString();
        tag.__isset.name = true;
        table.update(tag, true);
        close();
        return;
    }

    // We have a new tag to add
    Tag tag;
    tag.name = name.text().trimmed().toStdString();
    QUuid uuid;
    QString g =  uuid.createUuid().toString().replace("{","").replace("}","");
    tag.guid = g.toStdString();
    tag.__isset.name = true;
    tag.__isset.guid = true;
    TagTable t;
    t.add(0,tag,true);
    close();
}

void TagProperties::cancelButtonPressed() {
    okPressed = false;
    close();
}

void TagProperties::setLid(qint32 lid) {
    if (lid > 0) {
        this->lid = lid;
        Tag tag;
        TagTable table;
        table.get(tag, lid);
        originalName = QString::fromStdString(tag.name).trimmed();
        name.setText(originalName);
        return;
    }
    this->lid = 0;
    this->setWindowTitle(tr("Add Tag"));
    originalName = "";
}

void TagProperties::validateInput() {
    ok.setEnabled(true);
    if (name.text()=="") {
        ok.setEnabled(false);
        return;
    }
    TagTable t;
    QString tag = name.text().trimmed();
    if (t.findByName(tag)>0 && name.text().trimmed() != originalName) {
        ok.setEnabled(false);
        return;
    }
}
