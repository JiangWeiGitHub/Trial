


#include "./calculator.h"



int calculator(char *string)
{
  char tmp[32];
  int number[32];

  char *tmpP = tmp;
  int *numberP = number;

  char *p = string;

  char number[32];
  int counter = 0;

  while(*p != '\0')
  {
    if(*p >= '0' && *p <= '9')
    {
      number[counter++] = *p;

      continue;
    }
    else if(*p == ' ')
    {
      if(counter != 0)
      {
        number[counter] = '\0';
        counter = 0;

        
      }

      continue;
    }

    p++;
  }
}