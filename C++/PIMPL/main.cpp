#include "./Pimpl.h"

int main(void)
{
  Pimpl tmp;
  tmp.addWithPrivateNumber(9);
  tmp.echoNumber('a');

  return 0;
}