#include "magics_common.h"

magicobject::magicobject()
{
    for (size_t i=0; i<sizeof(numarray)/sizeof(numarray[0]); ++i)
    {
        numarray[i] = 0;
    }
}

std::string magicobject::to_string() const
{
    char result[21];
    snprintf(result, sizeof(result), "%d,%d,%d,%d,%d,%d+%d",
             numarray[0],numarray[1],numarray[2],numarray[3],numarray[4],numarray[5],specialnum);
    return result;
}

int caculate_ac(const magicobject_t& mo)
{
    return 7;
}
