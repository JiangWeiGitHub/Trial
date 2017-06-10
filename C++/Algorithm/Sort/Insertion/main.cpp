#include "./Insertion.h"

int main(void)
{
  int test[] = {1,45,78,54,545,245,152,4,251,55,478};

  Insertion tmp;
  tmp.sort(test, 11);

  for(int i = sizeof(test) / sizeof(int) - 1; i >= 0 ; i --)
  {    
    std::cout<<test[i]<<std::endl;
  }

  return 0;
}