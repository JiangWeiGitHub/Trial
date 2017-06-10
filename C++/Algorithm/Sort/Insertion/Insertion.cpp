#include "./Insertion.h"

struct number
{
  int value;
  struct number* before;
  struct number* next;
};

bool Insertion::sort(int* number, int length)
{
  struct number tmpList[length];
  tmpList[0].value = number[0];
  tmpList[0].next = 0;

  struct number* next = 0;
  struct number* top = &tmpList[0];

  for(int i = 1; i < length; i ++)
  {
    next = top;

    while(next != 0)
    {
      if(number[i] < next->value)
      {
        if(number[i] >= next->next->value)
        {
          tmpList[i].value = number[i];
          tmpList[i].next = next->next;

          next->next = &tmpList[i];

          break;
        }
      }

      if(number[i] >= top->value)
      {
        tmpList[i].value = number[i];
        tmpList[i].next = top;

        top = &tmpList[i];

        break;
      }

      next = next->next;
    }
  }

  for(int j = 0; j < length; j ++)
  {
    number[j] = top->value;
    top = top->next;
  }

  return true;
}