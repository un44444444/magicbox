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
    magicobject_t result = (*func)(params.toUtf8().constData());
    result.set_ac(caculate_ac(result));
    result.set_score(caculate_score(result));
    return QString::fromStdString(result.to_string());
}
