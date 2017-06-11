#include "./Selection.h"

bool Selection::sort(int* number, int length)
{
  int tmp = 0;
  for(int i = 0; i < length; i ++)
  {
    tmp = number[i];
    for(int j = 0; j < length; j ++)
    {
      if(tmp > number[j])
      {
        int tmptmp = tmp;
        tmp = number[j];
        number[j] = tmptmp;
      }
    }

    number[i] = tmp;
  }

  return true;
}