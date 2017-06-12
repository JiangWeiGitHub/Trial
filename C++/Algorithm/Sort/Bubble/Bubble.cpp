#include "./Bubble.h"

bool Bubble::sort(int* number, int length)
{
  int* tmp = number;
  int tmp_number = 0;
  for(int i = 0; i < length - 1; i ++)
  {
    for(int j = 0; j < length - i - 1; j ++)
    {
      if(number[j] > number[j + 1])
      {
        tmp_number = number[j + 1];
        number[j + 1] = number[j];
        number[j] = tmp_number;
      }
    }
  }

  return true;
}