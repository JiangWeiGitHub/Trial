#include <stdio.h>

int add(long int a, long int b, long int *c)
{
  *c = a + b;
  return (a > 0 && b > 0 && (*c < a || *c < b) || (a < 0 && b < 0 && (*c > a || *c > b)));
}

void main(void)
{
  long int a = 1999999999999999999;
  long int b = 1999999999999999999;
  long int c = 999;
  int tmp = 999;

  tmp = add(a, b, &c);

  printf("Result: %ld, return: %d\n", c, tmp);

}