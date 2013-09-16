#ifndef MAGICBOX_RANDOM_STD_H
#define MAGICBOX_RANDOM_STD_H

#include <string>

class CRandomStd
{
public:
    CRandomStd(int low, int high);
    CRandomStd(int low, int high, const std::string& params);
    ~CRandomStd();
    //
    int RandomNumber();
private:
    CRandomStd(const CRandomStd& rhs);
};

#endif // MAGICBOX_RANDOM_STD_H
