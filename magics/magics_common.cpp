#include "magics_common.h"
#include <string.h>//memset

#include "utils/log.h"


#define MAGICNUM_MAX_VALUE 36

magicobject::magicobject()
{
    for (size_t i=0; i<SIZEOF_ARRAY(numarray); ++i)
    {
        numarray[i] = 0;
    }
}

std::string magicobject::to_string(int ac) const
{
    char result[24];
    snprintf(result, sizeof(result), "%d,%d,%d,%d,%d,%d+%d|%d",
             numarray[0],numarray[1],numarray[2],numarray[3],numarray[4],numarray[5],specialnum,ac);
    return result;
}

int caculate_ac(const magicobject_t& mo)
{
    const magicnum_t* blue = mo.get_array();
    size_t blue_arraysize = mo.get_arraysize();
    magicnum_t delta_array[MAGICNUM_MAX_VALUE-1];
    memset(delta_array, 0, sizeof(delta_array));
    //
    for (size_t i=0; i<blue_arraysize; ++i)
    {
        for (size_t j=blue_arraysize-1; i<j; --j)
        {
            magicnum_t delta = blue[j]>=blue[i] ? blue[j]-blue[i] : blue[i]-blue[j];
            delta_array[delta] = 1;
        }
    }
    //
    int delta_count = 0;
    for (size_t k=0; k<SIZEOF_ARRAY(delta_array); ++k)
    {
        if (delta_array[k] > 0)
            ++ delta_count;
    }
    MAGICBOX_LOG_DEBUG(delta_count);
    //
    return delta_count-(blue_arraysize-1);
}
