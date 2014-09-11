#include "mainwindow.h"
#include "magicbox.h"

#include <QWebFrame>
#include <QWebInspector>

MainWindow::MainWindow(QWidget *parent)
    : QWebView(parent)
{
    //! The object we will expose to JavaScript engine:
    m_magicbox = new CMagicBox(this);

    // Signal is emitted before frame loads any web content:
    QObject::connect(page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                     this, SLOT(addJSObject()));

    // QWebInspector
    QWebInspector *inspector = new QWebInspector;
    inspector->setPage(page());
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    // context menu
    this->setContextMenuPolicy(Qt::NoContextMenu); //No context menu is allowed if you don't need it

    // Try to handle cicks by self
    page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);//Handle link clicks by yourself
    QObject::connect(page(), SIGNAL( linkClicked( QUrl ) ),
                  this, SLOT( linkClickedSlot( QUrl ) ) );

    // qrc:// URLs refer to resources. See views.qrc
    QUrl startURL = QUrl("qrc:/index.html");
    // Load web content now!
    this->setUrl(startURL);
}

MainWindow::~MainWindow()
{
}

void MainWindow::addJSObject()
{
    // Add to JavaScript Frame as member "magicbox".
    page()->mainFrame()->addToJavaScriptWindowObject(QString("magicbox"), m_magicbox);
}

//This slot handles all clicks
void MainWindow::linkClickedSlot(const QUrl& url)
{
    if (url.isValid()) {//isHtml does not exist actually you need to write something like it by yourself
        this->load (url);
    }
    else {//non html (pdf) pages will be opened with default application
        QDesktopServices::openUrl( url );
    }
}
