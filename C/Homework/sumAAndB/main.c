#include <stdio.h>
#include <stdlib.h>

// #define MAX 1024
#define MAX 8

void main(void)
{
  char data[MAX/8] = {0};
  // int testData[MAX] = {1,2,5,8,6,5,445,5,85,5,258,2,532,52,5,266,35,\
  // 326,36,36,226,62,85,48,457,54,454,54,54,878,54,54,54,5,54,54,54,};
  // int testData[MAX] = {1,2,5,7,6,5,3,5};
  int testData[MAX] = {1,2,3,4,5,6,7,0};

  int i;
  for(i = 0; i < MAX; i++)
  {
    data[testData[i] / 8] |= 1 << ( testData[i] % 8);

    printf("data: %x\n", data[testData[i] / 8]);
  }
}