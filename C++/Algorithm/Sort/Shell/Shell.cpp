#include "./Shell.h"

struct number
{
  int value;
  struct number* before;
  struct number* next;
};

bool Shell::sort(int* number, int length)
{
  int i, j, gap;  

  for (gap = length / 2; gap > 0; gap /= 2)
  {
    for (i = 0; i < gap; i++)
    {
      for (j = i + gap; j < length; j += gap)
      {
        if (number[j] > number[j - gap])
        {  
          int temp = number[j];
          int k = j - gap;

          while (k >= 0 && number[k] < temp)  
          {
            number[k + gap] = number[k];  
            k -= gap;
          }

          number[k + gap] = temp;  
        }
      }
    }
  }

  return true;
}