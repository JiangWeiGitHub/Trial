#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

int main(void)
{
  char a[5];
  char *b = "abcdefg";
  char *c = "123";

  // sprintf(a, "%.3s%.2s", b, c);
  snprintf(a, sizeof(a), "%.5s%.2s", b, c);

  printf("a: %s\n", a);

  return 0;
}