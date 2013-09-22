#include "random_rand.h"

#include <stdlib.h>//srand() rand()
#include "seed.h"

#include "utils/log.h"

CRandomRand::CRandomRand()
{
    srand(get_32bit_seed());
}
CRandomRand::CRandomRand(const std::string& params)
{
    srand(get_32bit_seed());
}
CRandomRand::~CRandomRand()
{
}

int CRandomRand::RandomRange(int low, int high)
{
    return (rand() % (high-low+1))+ low;
}
