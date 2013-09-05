#ifndef CMAGICBOX_H
#define CMAGICBOX_H

#include <QtWidgets>

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
