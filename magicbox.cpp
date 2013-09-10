#include "magicbox.h"

#include "magics/ssq.h"
typedef magicobject_t (*MAGIC_FUNC)(const std::string& params);

CMagicBox::CMagicBox(QObject* parent)
    : QObject(parent)
{
}
CMagicBox::~CMagicBox()
{
}

QString CMagicBox::generate(const QString& type, const QString& params)
{
    MAGIC_FUNC func = magic_ssq;
    if (type == "ssq") {
        func = magic_ssq;
    }
    const magicobject_t& result = (*func)(params.toUtf8().constData());
    return QString::fromStdString(result.to_string());
}
