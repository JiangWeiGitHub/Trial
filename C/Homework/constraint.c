#include <stdio.h>

int main(void)
{
  char a = 'a';
  char b = 'b';
  char* cp = &a;
  const char * cpp = &b;

  // cpp = cp;
  cp = cpp;

  printf("cpp: %c\n", *cpp);
  printf("cp: %c\n", *cp);

  return 0;
}