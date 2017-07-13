#include <stdio.h>

int main(void)
{
  unsigned int a = 4294967295;
  int b = 2147483647;

  printf("a+1= %d\n", a+1);
  printf("b+1= %u\n", b+1);
  printf("(unsigned int)b+1= %u\n", (unsigned int)b+1);

  return 0;
}