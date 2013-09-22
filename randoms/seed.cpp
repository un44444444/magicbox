#include <sys/time.h>//gettimeofday() clock_gettime()
#include <intrin.h>//__rdtsc();

#include "utils/log.h"

unsigned int get_32bit_seed_by_timeval()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    MAGICBOX_LOG_DEBUG(tv.tv_sec);
    MAGICBOX_LOG_DEBUG(tv.tv_usec);
    return (tv.tv_sec+tv.tv_usec*1000);
}
unsigned int get_32bit_seed_by_timespec()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    MAGICBOX_LOG_DEBUG(ts.tv_sec);
    MAGICBOX_LOG_DEBUG(ts.tv_nsec);
    return (ts.tv_sec%1000000+4*ts.tv_nsec);
}
unsigned int get_32bit_seed_by_rdtsc()
{
    unsigned int result = 0;
    unsigned __int64 i;
    i = __rdtsc();
    MAGICBOX_LOG_DEBUG(i);
    result = i & 0xFFFFFFFF;
    return result;
}

unsigned int get_32bit_seed()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    MAGICBOX_LOG_DEBUG(tv.tv_sec);
    MAGICBOX_LOG_DEBUG(tv.tv_usec);
    //
    unsigned int result = 0;
    unsigned __int64 i;
    i = __rdtsc();
    MAGICBOX_LOG_DEBUG(i);
    result = i & 0x1FFFFFFF;
    //
    result = result+4000*tv.tv_usec;
    MAGICBOX_LOG_DEBUG(result);
    return result;
}
