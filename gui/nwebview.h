#ifndef NWEBVIEW_H
#define NWEBVIEW_H

#include <QWebView>
#include <gui/nwebpage.h>


//****************************************************
//* This inherits everything from QWebView.  It is
//* useful to allow us to setup things that are
//* needed to view & edit notes.
//****************************************************
class NWebView : public QWebView
{
    Q_OBJECT
public:
    explicit NWebView(QWidget *parent = 0);
    bool isDirty;
    NWebPage *editorPage;

signals:

public slots:
    void editAlert();

private slots:
    void exposeToJavascript();

public slots:
    void decryptText(QString id, QString text, QString hint);

};

#endif // NWEBVIEW_H
