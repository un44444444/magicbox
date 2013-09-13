#include "random_rand.h"

#include <stdlib.h>
#include <sys/time.h>//gettimeofday

#include "utils/log.h"

CRandomRand::CRandomRand()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    MAGICBOX_LOG_DEBUG(tv.tv_sec);
    MAGICBOX_LOG_DEBUG(tv.tv_usec);
    srand(tv.tv_sec+tv.tv_usec*1000);
}
CRandomRand::CRandomRand(const std::string& params)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    MAGICBOX_LOG_DEBUG(tv.tv_sec);
    MAGICBOX_LOG_DEBUG(tv.tv_usec);
    srand(tv.tv_sec+tv.tv_usec*1000);
}
CRandomRand::~CRandomRand()
{
}

int CRandomRand::RandomRange(int low, int high)
{
    return (rand() % (high-low+1))+ low;
}
