// uniform_int_distribution
#include <iostream>
#include <random>
#include <time.h>

int main()
{
  const int nrolls = 100000; // number of experiments
  const int nstars = 95;    // maximum number of stars to distribute

  std::default_random_engine generator(time(NULL));
  std::uniform_int_distribution<int> distribution(0,9);

  int p[10]={};

  for (int i=0; i<nrolls; ++i) {
    int number = distribution(generator);
    ++p[number];
  }

  std::cout << "uniform_int_distribution (0,9):" << std::endl;
  for (int i=0; i<10; ++i)
    std::cout << i << ": " << (double)p[i]*100/nrolls << "%" << std::endl;

  return 0;
}
