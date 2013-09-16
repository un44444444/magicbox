#ifndef MAGICBOX_RANDOM_RAND_H
#define MAGICBOX_RANDOM_RAND_H

#include <string>

class CRandomRand
{
public:
    CRandomRand();
    CRandomRand(const std::string& params);
    ~CRandomRand();
    //
    int RandomRange(int low, int high);
private:
    CRandomRand(const CRandomRand& rhs);
};

#endif // MAGICBOX_RANDOM_RAND_H
