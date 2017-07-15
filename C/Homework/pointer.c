#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // char *p1 = "hello";
  // char *p2, *p3;
  // p2 = p3 = (char*)malloc(20);
  // memset(p2, 0, 20);
  // while(*(p2++) = *(p1++));
  // printf("p2: %s\n", p2);
  // printf("p3: %s\n", p3);

  // int a, *b;
  // a = 9;
  // b = &a;
  // (*b)++;
  // printf("a: %d\n", a);

  int *ia, *ib, ic;
  char *ca, *cb, cc;
  ia = (int*)0x500;
  ib = (int*)0x518;
  ic = ib - ia;

  ca = (char*)0x500;
  cb = (char*)0x518;
  cc = cb - ca;

  printf("ic: %d, cc: %d\n", ic, cc);

  return 0;
}