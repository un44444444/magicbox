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

string magic_ssq(const string& params)
{
    int blue[6+1];
    int red = 0;
    for (size_t i=0; i<sizeof(blue)/sizeof(blue[0]); ++i)
    {
        blue[i] = 0;
    }
    //
    blue[0] = get_radom_index_between_1_36();
    for (size_t j=1; j<sizeof(blue)/sizeof(blue[0])-1; ++j)
    {
        int index = get_radom_index_between_1_36();
        size_t k=0;
        for (; blue[k]!=0; ++k)
        {
            if (index >= blue[k]) ++index;
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
        if (blue[k]==0) blue[k]=index;
    }
    //
    red = get_radom_index_between_1_36();
    //
    char result[21];
    snprintf(result, sizeof(result), "%d,%d,%d,%d,%d,%d+%d",
             blue[0],blue[1],blue[2],blue[3],blue[4],blue[5],red);
    return result;
}
