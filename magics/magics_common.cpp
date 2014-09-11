#include "magics_common.h"
#include <string.h>//memset

#include "utils/log.h"


#define MAGICNUM_MAX_VALUE 36
#define MAGICNUM_MIN_VALUE 1

magicobject::magicobject()
{
    for (size_t i=0; i<SIZEOF_ARRAY(_numarray); ++i)
    {
        _numarray[i] = 0;
    }
}

std::string magicobject::to_string() const
{
    char result[128];
    snprintf(result, sizeof(result), "{\"r\":[%d,%d,%d,%d,%d,%d],\"b\":%d,\"ac\":%d,\"score\":%d}",
             _numarray[0],_numarray[1],_numarray[2],_numarray[3],_numarray[4],_numarray[5],
             _specialnum,_ac,_score);
    return result;
}

int caculate_ac(const magicobject_t& mo)
{
    const magicnum_t* array = mo.get_array();
    const size_t arraysize = mo.get_arraysize();
    magicnum_t delta_array[MAGICNUM_MAX_VALUE-MAGICNUM_MIN_VALUE];
    memset(delta_array, 0, sizeof(delta_array));
    //
    for (size_t i=0; i<arraysize; ++i)
    {
        for (size_t j=arraysize-1; i<j; --j)
        {
            magicnum_t delta = array[j]>=array[i] ? array[j]-array[i] : array[i]-array[j];
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
    return delta_count-(arraysize-1);
}

int caculate_score(const magicobject_t& mo)
{
    //
    return 100;
}
