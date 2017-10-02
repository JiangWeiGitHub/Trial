#include <stdio.h>
#include <stdlib.h>

// #define MAX 1024
#define MAX 16

void main(void)
{
  char data[MAX/8] = {0};
  // int testData[MAX] = {1,2,5,8,6,5,445,5,85,5,258,2,532,52,5,266,35,\
  // 326,36,36,226,62,85,48,457,54,454,54,54,878,54,54,54,5,54,54,54,};
  // int testData[MAX] = {1,2,5,7,6,5,3,5};
  // int testData[MAX] = {1,2,3,4,5,6,7,0};
  int testData[MAX] = {1,2,3,4,5,6,7,0,8,9,10,11,13,12,14,15};

  int i;
  int key = 10;
  for(i = 0; i < MAX; i++)
  {
    data[testData[i] / 8] |= 1 << ( testData[i] % 8);

    // printf("data: %x\n", data[testData[i] / 8]);
  }

  for(i = 0; i < MAX - key; i++)
  {
    if( ((data[i / 8] & 1 << i) == 1 << i) && ((data[(i + key) / 8] & 1 << (i + key) ) == 1 << (i + key) ) )
    {
      printf("counter: %d\n", i);
      printf("data: %x, %x\n", data[i / 8], data[(i + key) / 8]);
    }
  }
}