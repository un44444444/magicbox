#ifndef CMAGICBOX_H
#define CMAGICBOX_H

#if QT_VERSION >= 0x050000
    #include <QtWidgets>
#else
    #include <QtGui>
#endif


class CMagicBox : public QObject
{
    Q_OBJECT
public:
    explicit CMagicBox(QObject * parent=0);
    ~CMagicBox();

public slots:
    QString generate(const QString& type, const QString& params);
};

#endif // CMAGICBOX_H
