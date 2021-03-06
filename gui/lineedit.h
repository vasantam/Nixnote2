/****************************************************************************
**
** Copyright (c) 2007 Trolltech ASA <info@trolltech.com>
**
** Use, modification and distribution is allowed without limitation,
** warranty, liability or support of any kind.
**
****************************************************************************/

 #ifndef LINEEDIT_H
 #define LINEEDIT_H

 #include <QLineEdit>

 class QToolButton;

 class LineEdit : public QLineEdit
 {
     Q_OBJECT
 private:
     int filterPosition;

 public:
     LineEdit(QWidget *parent = 0);
     void updateSelection();

 protected:
     void resizeEvent(QResizeEvent *);

 private slots:
     void updateCloseButton(const QString &text);
     void buildSelection();

 private:
     QToolButton *clearButton;

 signals:
     void updateSelectionRequested();
 };

 #endif // LIENEDIT_H
