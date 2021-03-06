#include "endecryptdialog.h"

#include "global.h"

#include <QString>
#include <QIcon>
#include <QGridLayout>
#include <QLabel>

extern Global global;

EnDecryptDialog::EnDecryptDialog(QWidget *parent) :
    QDialog(parent)
{
    okPressed = false;
    setWindowTitle(tr("Decrypt"));
    setWindowIcon(QIcon(":password.png"));
    setLayout(&grid);

    connect(&password, SIGNAL(textChanged(const QString&)), this, SLOT(validateInput()));

    hintLabel.setText(tr("Userid"));
    passwordLabel.setText(tr("Password"));
    passwordGrid.addWidget(&passwordLabel, 1,1);
    passwordGrid.addWidget(&password, 1, 2);
    passwordGrid.addWidget(&hintLabel, 2,1);
    passwordGrid.addWidget(&hint, 2, 2);
    passwordGrid.setContentsMargins(10, 10,  -10, -10);
    grid.addLayout(&passwordGrid,1,1);

    ok.setText(tr("OK"));
    if (global.password == "" and global.username == "")
        ok.setEnabled(false);
    connect(&ok, SIGNAL(clicked()), this, SLOT(okButtonPressed()));
    cancel.setText(tr("Cancel"));
    connect(&cancel, SIGNAL(clicked()), this, SLOT(cancelButtonPressed()));
    buttonGrid.addWidget(&ok, 1, 1);
    buttonGrid.addWidget(&cancel, 1,2);
    grid.addLayout(&buttonGrid,2,1);
    grid.setSizeConstraint( QLayout::SetFixedSize );
}



void EnDecryptDialog::okButtonPressed() {
    okPressed = true;
    close();
}

void EnDecryptDialog::cancelButtonPressed() {
    okPressed = false;
    close();
}



void EnDecryptDialog::validateInput() {
    ok.setEnabled(true);
    if (password.text()=="") {
            ok.setEnabled(false);
            return;
    }
}
