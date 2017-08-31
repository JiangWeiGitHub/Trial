#include <stdio.h>
#include <sys/time.h>
#include <time.h>

void main(void)
{
  struct timeval tmp;
  int result;
  if((result = gettimeofday(&tmp, NULL)) != 0)
  {
    printf("Something Wrong!\n");
  }
  printf("Time: %s", ctime(&tmp.tv_sec));
}