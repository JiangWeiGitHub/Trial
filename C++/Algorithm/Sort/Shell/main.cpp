#include "./Shell.h"

int main(void)
{
  // int test[] = {1,45,78,54,545,245,45,152,4,251,55,478,564,45,889,56,5448,45,6,545,45,58,88};
  int test[] = {9,8,7,6,5,4,3,2,1};

  Shell tmp;
  tmp.sort(test, sizeof(test) / sizeof(int));

  for(int i = sizeof(test) / sizeof(int) - 1; i >= 0 ; i --)
  {    
    std::cout<<test[i]<<std::endl;
  }

  return 0;
}