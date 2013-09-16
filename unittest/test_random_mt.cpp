#include "randoms/random_mt.h"
#include "unittest_log.h"
#include <time.h>//time()

int main()
{
  const int nrolls = 100000; // number of experiments
  const int nstars = 95;    // maximum number of stars to distribute

  CRandomMT random;
  random.SeedMT(time(NULL));

  int p[10]={};

  for (int i=0; i<nrolls; ++i) {
    int number = random.RandomRange(0, 9);
    ++p[number];
  }

  UNITTEST_STDOUT << "CRandomMT::RandomRange(0,9):" << std::endl;
  for (int i=0; i<10; ++i)
    UNITTEST_STDOUT << i << ": " << (double)p[i]*100/nrolls << "%" << std::endl;

  return 0;
}
