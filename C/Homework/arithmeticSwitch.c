#include <stdio.h>

int main(void)
{
  if(-1 == (unsigned char)1)
  {
    printf("Equal\n");
  }
  else
  {
    printf("Not Equal\n");
  }

  return 0;
}