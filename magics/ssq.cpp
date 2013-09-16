#include "ssq.h"
#include "../randoms/random_rand.h"

#include "utils/log.h"

magicobject_t magic_ssq(const std::string& params)
{
    magicobject_t result;
    magicnum_t* blue = result.get_array();
    size_t blue_arraysize = result.get_arraysize();
    int red = 0;
    CRandomRand random(params);
    //
    blue[0] = random.RandomRange(1, 36);
    for (size_t j=1; j<blue_arraysize; ++j)
    {
        int index = random.RandomRange(1, 36);
        size_t k=0;
        for (; k<blue_arraysize; ++k)
        {
            if (blue[k]==0) {
                blue[k]=index;
                break;
            }
            else if (index >= blue[k]) ++index;
            else {
                //
                for (size_t tmp=j;tmp>k;--tmp) {
                    blue[tmp] = blue[tmp-1];
                }
                //
                blue[k]=index;
                break;
            }
        }
        if (k==blue_arraysize-1) blue[k]=index;
    }
    //
    red = random.RandomRange(1, 36);
    result.specialnum = red;
    //
    return result;
}
