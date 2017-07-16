#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrccpy(char* dst, char* src)
{
  int tmp = dst - src;
  int srcLength = strlen(src);

  char* srcTmp = src;
  char* dstTmp = dst;

  if(abs(tmp) >= srcLength)
  {
    while(*(dst++) = *(src++));
    *(--dst) = '\0';
    return dstTmp;
  }
  else if(abs(tmp) < srcLength && tmp >= 0)
  {
    return dstTmp;
  }
  else if(abs(tmp) < srcLength && tmp < 0)
  {
    int hehe = abs(tmp);
    while(hehe --)
    {
      *(dst++) = *(src++);
    }

    *(--dst) = '\0';

    return dstTmp;
  }
}

int main(void)
{
  char *total = (char*)malloc(100);
  char *a = total;
  char *b = total + 8;
  
  printf("a address: %p\n", a);
  printf("b address: %p\n\n", b);

  char *haha = b;
  char c[30] = "abc123456789";
  int tmp = 0;
  for(; tmp < 10; tmp++)
  {
    *(b++) = c[tmp];
  }

  *b = '\0';

  printf("b before: %s\n", haha);

  char *test = mystrccpy(a, haha);

  printf("a: %s\n", test);

  printf("b after: %s\n", haha);

  return 0;
}