#include <stdio.h>
#include <string.h>

int main(void)
{
  char a[] = "123";
  char *b = "123";

  printf("sizeof(a): %lu\n", sizeof(a));
  printf("sizeof(b): %lu\n", sizeof(b));

  printf("strlen(a): %lu\n", strlen(a));
  printf("strlen(b): %lu\n", strlen(b));

  return 0;
}