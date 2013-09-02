#include "magicbox.h"

CMagicBox::CMagicBox(QObject* parent)
    : QObject(parent)
{
}
CMagicBox::~CMagicBox()
{
}

QString CMagicBox::greeting()
{
    return "Hello world!";
}
