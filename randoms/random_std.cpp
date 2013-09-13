#include "random_std.h"

#include <random>//require c++11
#include <sys/time.h>//gettimeofday

#include "utils/log.h"

CRandomStd::CRandomStd(int low, int high)
{
}
CRandomStd::CRandomStd(int low, int high, const std::string& params)
{
}
CRandomStd::~CRandomStd()
{
}

class CRandomGenerator
{
public:
    static const CRandomGenerator& Instance(int rstart, int rend);
protected:
private:
    CRandomGenerator();
    CRandomGenerator(const CRandomGenerator& rhs);
    ~CRandomGenerator();
};
const CRandomGenerator& CRandomGenerator::Instance(int rstart, int rend)
{
    static CRandomGenerator instance;
    return instance;
}
CRandomGenerator::CRandomGenerator()
{
    ;
}
CRandomGenerator::~CRandomGenerator()
{
}
