#include <stdio.h>

void sort(int *data, int length)
{
  int tmp[1024] = {0};
  tmp[0] = data[0];
  int flag = 0;
  int i, j;
  for(i = 1; i < length; i++)
  {
    for(j = flag; j >= 0 && flag < length; j--)
    {
      if(data[i] >= tmp[flag])
      {
        flag++;
        tmp[flag] = data[i];

        break;
      }
      else
      {        
        int counter = flag;
        while(tmp[counter] > data[i] && counter >= 0)
        {
          tmp[counter + 1] = tmp[counter];
          counter--;
        }

        tmp[counter + 1] = data[i];

        flag++;

        break;
      }
    }
  }

  int t;
  for(t = 0; t < length; t++)
  {
    printf("%d ", tmp[t]);
  }

  printf("\n");
}

void main(void)
{
  // int data[] = {10,875,5654,85,856,44,54,58,6522,2};
  // int data[] = {0,1,2,3,4,5,6,7,8,9,10};
  int data[] = {10,9,8,7,6,5,4,3,2,1,0};
  // int data[] = {1,22,33,4,55555,666,7777,888,9};

  sort(data, sizeof(data) / sizeof(data[0]));
}