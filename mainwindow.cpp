#include "mainwindow.h"
#include "magicbox.h"

#include <QWebFrame>

MainWindow::MainWindow(QWidget *parent)
    : QWebView(parent)
{
    //! The object we will expose to JavaScript engine:
    m_magicbox = new CMagicBox(this);
    // Signal is emitted before frame loads any web content:
    QObject::connect(page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                     this, SLOT(addJSObject()));

    // qrc:// URLs refer to resources. See views.qrc
    QUrl startURL = QUrl("qrc:/index.html");
    // Load web content now!
    setUrl(startURL);
}

MainWindow::~MainWindow()
{
}

void MainWindow::addJSObject() {
    // Add to JavaScript Frame as member "magicbox".
    page()->mainFrame()->addToJavaScriptWindowObject(QString("magicbox"), m_magicbox);
}
