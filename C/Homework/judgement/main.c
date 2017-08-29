#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  int a[3] = {0, -1, 1};
  char test = 'a';
  char *b[2] = {NULL, &test};

  float c[3] = {1.0587, 0, 0.000001};

  int tmp;

  for(tmp = 0; tmp < 3; tmp++)
  {
    // if(a[tmp] == 0)
    if(!a[tmp])
    {
      printf("%d: False\n", a[tmp]);
    }
    else
    {
      printf("%d: True\n", a[tmp]);
    }
  }

  for(tmp = 0; tmp < 2; tmp++)
  {
    if(b[tmp] == NULL)
    {
      printf("%p: Empty Pointer\n", b[tmp]);
    }
    else
    {
      printf("%p: Not Empty Pointer\n", b[tmp]);
    }
  }

  for(tmp = 0; tmp < 3; tmp++)
  {
    if(abs(c[tmp]) <= 0.000001)
    {
      printf("%f: Zero\n", c[tmp]);
    }
    else
    {
      printf("%f: Not Zero\n", c[tmp]);
    }
  }

}