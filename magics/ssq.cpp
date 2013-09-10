#include "ssq.h"

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>//gettimeofday
#include <unistd.h>//usleep

#include <iostream>
using namespace std;

static int get_radom_index_between_1_36()
{
    int start = 1;
    int end = 36;
    //srand((unsigned int)(time(NULL)));
    usleep(10);  //毫秒级休眠
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_usec);
    cout<<tv.tv_usec<<endl;
    return (rand() % (end-start+1))+ start;
}

magicobject_t magic_ssq(const std::string& params)
{
    magicobject_t result;
    magicnum_t* blue = result.get_array();
    size_t blue_arraysize = result.get_arraysize();
    int red = 0;
    //
    blue[0] = get_radom_index_between_1_36();
    for (size_t j=1; j<blue_arraysize; ++j)
    {
        int index = get_radom_index_between_1_36();
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
    red = get_radom_index_between_1_36();
    result.specialnum = red;
    //
    return result;
}
