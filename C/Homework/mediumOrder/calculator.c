#include "./calculator.h"

void calculator(char *string)
{
  char *p = string;

  char number[32];
  int counter = 0;

  struct stringStack *stackLabel = intiStringStack();
  struct stringStack *stackNumber = intiStringStack();

  while(*p != '\0')
  {
    if(*p >= '0' && *p <= '9')
    {
      number[counter++] = *p;
    }
    else
    {
      if(counter != 0)
      {
        number[counter] = '\0';
        counter = 0;

        pushString(stackNumber, number);
      }

      if(*p == '(')
      {
        pushString(stackLabel, "(");
      }

      if(*p == ')')
      {
        while(getTopString(stackLabel)[0] != '(')
        {
          pushString(stackNumber, popString(stackLabel));          
        }

        popString(stackLabel);
      }

      if(*p == '*')
      {
        pushString(stackLabel, "*");
      }

      if(*p == '/')
      {
        pushString(stackLabel, "/");
      }

      if(*p == '+')
      {
        if(getTopString(stackLabel)[0] == '*' || getTopString(stackLabel)[0] == '/')
        {
          pushString(stackNumber, popString(stackLabel));
        }
        else
        {
          pushString(stackLabel, "+");
        }        
      }

      if(*p == '-')
      {
        if(getTopString(stackLabel)[0] == '*' || getTopString(stackLabel)[0] == '/')
        {
          pushString(stackNumber, popString(stackLabel));
        }
        else
        {
          pushString(stackLabel, "-");
        }   
      }
    }

    p++;
  }

  if(counter != 0)
  {
    number[counter] = '\0';
    counter = 0;

    pushString(stackNumber, number);
  }

  // int i = 0;
  while((stackNumber->top) != 0)
  {
    printf("Member: %s\n", popString(stackNumber));
  }
}