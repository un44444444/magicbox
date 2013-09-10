#include "magicbox.h"

#include "utils/log.h"
#include "magics/ssq.h"
typedef magicobject_t (*MAGIC_FUNC)(const std::string& params);

CMagicBox::CMagicBox(QObject* parent)
    : QObject(parent)
{
}
CMagicBox::~CMagicBox()
{
}

QString CMagicBox::generate(const QVariantMap& type, const QString& params)
{
    //
    if (!type.contains("c")) {
        return "format error(c not found).";
    }
    const QString& type_class = type.value("c").toString();
    MAGICBOX_LOG_DEBUG(type_class.toUtf8().constData());
    //
    MAGIC_FUNC func = magic_ssq;
    if (type_class == "ssq") {
        func = magic_ssq;
    }
    const magicobject_t& result = (*func)(params.toUtf8().constData());
    return QString::fromStdString(result.to_string());
}
