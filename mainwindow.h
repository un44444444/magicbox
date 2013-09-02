#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWebView>

class CMagicBox;

class MainWindow : public QWebView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    CMagicBox * m_magicbox;

private slots:
    void addJSObject();
    void linkClickedSlot( QUrl url );
};

#endif // MAINWINDOW_H
