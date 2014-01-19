#include "ssq.h"
#include "../randoms/random_rand.h"

#include "utils/log.h"

#define SSQ_MAX_BALL 36
#define SSQ_MIN_BALL 1

static inline bool is_in_array(const magicnum_t* blue, size_t bule_filled, magicnum_t value)
{
    bool result = false;
    size_t k=0;
    for (; k<bule_filled; ++k)
    {
        if (blue[k] == value) {
            result = true;
            break;
        }
    }
    //
    return result;
}

magicobject_t magic_ssq(const std::string& params)
{
    magicobject_t result;
    magicnum_t* blue = result.get_array();
    size_t blue_arraysize = result.get_arraysize();
    int red = 0;
    CRandomRand random(params);
    //
    blue[0] = random.RandomRange(SSQ_MIN_BALL, SSQ_MAX_BALL);
    for (size_t j=1; j<blue_arraysize; ++j)
    {
        int index = random.RandomRange(SSQ_MIN_BALL, SSQ_MAX_BALL);
        while (is_in_array(blue,j,index))
        {
            index = random.RandomRange(SSQ_MIN_BALL, SSQ_MAX_BALL);
        }
        blue[j] = index;
    }
    //
    red = random.RandomRange(SSQ_MIN_BALL, SSQ_MAX_BALL);
    result.specialnum = red;
    //
    return result;
}
