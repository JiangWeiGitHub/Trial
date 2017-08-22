#include <stdio.h>

void sort(int data[])
{
  int tmp[1024] = {0};
  tmp[0] = data[0];
  int flag = 0;
  int i, j;
  for(i = 1; i < sizeof(data) / sizeof(data[0]); i++)
  {
    for(j = flag; j >= 0 && flag < sizeof(data) / sizeof(data[0]); j--)
    {
      if(data[i] >= tmp[flag])
      {
        flag++;
        tmp[flag] = data[i];
      }
      else
      {
        flag++;
        int counter = flag;
        while(tmp[counter] > data[i] && counter >= 0)
        {
          tmp[counter] = tmp[counter - 1];
          counter--;
        }        
      }
    }
  }

  int t;
  for(t = 0; t <= sizeof(data) / sizeof(data[0]); t++)
  {
    printf("%d ", tmp[t]);
  }

  printf("\n");
}

void main(void)
{
  int data[] = {10,875,5654,85,856,44,54,58,6522,2};

  sort(data);
}