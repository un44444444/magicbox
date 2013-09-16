#include "random_std.h"

#include <random>//require c++11
#include <sys/time.h>//gettimeofday

#include "utils/log.h"

// CRandomGenerator
class CRandomGenerator
{
public:
    static CRandomGenerator* Instance(int rstart, int rend);
    void ChangeParam(const std::string& params);
    int GenarateNumber();
protected:
private:
    CRandomGenerator(int rstart, int rend);
    CRandomGenerator(const CRandomGenerator& rhs);
    ~CRandomGenerator();
private:
    std::default_random_engine* m_pGenerator;
    std::uniform_int_distribution<int>* m_pDistribution;
};
CRandomGenerator* CRandomGenerator::Instance(int rstart, int rend)
{
    static CRandomGenerator instance(rstart, rend);
    return &instance;
}
CRandomGenerator::CRandomGenerator(int rstart, int rend)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    m_pGenerator = new std::default_random_engine(tv.tv_sec+tv.tv_usec*1000);
    m_pDistribution = new std::uniform_int_distribution<int>(rstart, rend);
}
CRandomGenerator::~CRandomGenerator()
{
    delete m_pGenerator;
    m_pGenerator = NULL;
    delete m_pDistribution;
    m_pDistribution = NULL;
}
void CRandomGenerator::ChangeParam(const std::string& params)
{
    MAGICBOX_LOG_DEBUG(params);
}

int CRandomGenerator::GenarateNumber()
{
    int number = (*m_pDistribution)(*m_pGenerator);
    return number;
}

// CRandomStd
static CRandomGenerator* s_pInstance = NULL;
CRandomStd::CRandomStd(int low, int high)
{
    s_pInstance = CRandomGenerator::Instance(low, high);
}
CRandomStd::CRandomStd(int low, int high, const std::string& params)
{
    s_pInstance = CRandomGenerator::Instance(low, high);
    s_pInstance->ChangeParam(params);
}
CRandomStd::~CRandomStd()
{
}
int CRandomStd::RandomNumber()
{
    return s_pInstance->GenarateNumber();
}
