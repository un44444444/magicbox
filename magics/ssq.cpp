#include "ssq.h"
#include "../randoms/random_rand.h"

#include "utils/log.h"

#define SSQ_MAX_BALL 36
#define SSQ_MIN_BALL 1

#define SSQ_MAX_SPECIAL 16
#define SSQ_MIN_SPECIAL 1

static bool insert_into_sorted_array(magicnum_t* array, size_t arr_max_idx, magicnum_t value);
//static bool sorted_array_exist_value(magicnum_t* array, size_t arr_max_idx, magicnum_t value);

magicobject_t magic_ssq(const std::string& params)
{
    magicobject_t result;
    magicnum_t* array = result.get_array();
    size_t arraysize = result.get_arraysize();
    int specialnum = 0;
    CRandomRand random(params);
    //
    array[0] = random.RandomRange(SSQ_MIN_BALL, SSQ_MAX_BALL);
    for (size_t j=1; j<arraysize; ++j)
    {
        int index = random.RandomRange(SSQ_MIN_BALL, SSQ_MAX_BALL);
        bool is_success = insert_into_sorted_array(array, j, index);
        while (!is_success)
        {
            index = random.RandomRange(SSQ_MIN_BALL, SSQ_MAX_BALL);
            is_success = insert_into_sorted_array(array, j, index);
        }
    }
    //
    specialnum = random.RandomRange(SSQ_MIN_SPECIAL, SSQ_MAX_SPECIAL);
    result.set_specialnum(specialnum);
    //
    return result;
}

static bool insert_into_sorted_array(magicnum_t* array, size_t arr_max_idx, magicnum_t value)
{
    bool result_success = true;
    size_t k=0;
    for (; k<arr_max_idx; ++k)
    {
        if (array[k] < value) {
            continue;
        }
        else if (array[k] == value) {
            result_success = false;
            break;
        }
        else {
            break;
        }
    }
    //
    if (result_success) {
        if (k != arr_max_idx) {
            for (; arr_max_idx>k; --arr_max_idx)
            {
                array[arr_max_idx] = array[arr_max_idx-1];
            }
        }
        array[k] = value;
    }
    //
    return result_success;
}
