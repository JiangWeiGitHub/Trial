#include "./Pimpl.h"

int main(void)
{
  Pimpl tmp;
  int result = tmp.addWithPrivateNumber(9);
  std::cout<<result<<std::endl;

  tmp.echoNumber('a');

  return 0;
}