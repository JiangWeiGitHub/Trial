#include "./Insertion.h"

bool Insertion::sort(int* number, int length)
{
  struct tmp
  {
    int value;
    struct tmp* pt;
  };

  struct tmp first;
  first.value = number[0];
  first.pt = 0;

  struct tmp* next = &first;
  struct tmp* top = &first;

  for(int i = 1; i < length - 1; i ++)
  {
    next = top;

    while(next != 0)
    {
      if(number[i] < next->value)
      {
        struct tmp* tmp = new struct tmp;
        tmp->value = next->value;
        tmp->pt = next->pt;
        next->value = top->value = number[i];
        next->pt = top->pt = tmp;

        break;
      }

      next = next->pt;
    }

  }

  for(int j = 0; j < length; j ++)
  {
    number[j] = top->value;
    top = top->pt;
  }

  return true;
}