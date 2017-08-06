#include "./calculator.h"

void calculator(char *string)
{
  char *p = string;

  char number[32];
  int counter = 0;

  int flagBracket = 0;

  struct stringStack *stackLabel = intiStringStack();
  struct stringStack *stackNumber = intiStringStack();

  struct stringStack *stackOpera = intiStringStack();
  struct stringStack *stackResult = intiStringStack();

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
        flagBracket = 1;
        pushString(stackLabel, "(");
      }

      if(*p == ')')
      {
        while(getTopString(stackLabel)[0] != '(')
        {
          // // printf("111getTopString(stackLabel)[0]: %c\n",getTopString(stackLabel)[0]);
          // if(getTopString(stackLabel)[0] == '+' || getTopString(stackLabel)[0] == '-')
          // {

          // }
          // pushString(stackNumber, popString(stackLabel));
          // // printf("222getTopString(stackLabel)[0]: %c\n",getTopString(stackLabel)[0]);
          pushString(stackNumber, popString(stackLabel));
        }

        popString(stackLabel);

        flagBracket = 0;
      }

      if(*p == '*')
      {
        // pushString(stackLabel, "*");
        if(getTopString(stackLabel)[0] == '*' || getTopString(stackLabel)[0] == '/')
        {
          if(flagBracket == 1)
          {
            while(getTopString(stackLabel)[0] != '(')
            {
              pushString(stackNumber, popString(stackLabel));
            }
          }
          else
          {
            while((stackLabel->top) > 0)
            {
              pushString(stackNumber, popString(stackLabel));
            }
          }
        }

        pushString(stackLabel, "*");
      }

      if(*p == '/')
      {
        // pushString(stackLabel, "*");
        if(getTopString(stackLabel)[0] == '*' || getTopString(stackLabel)[0] == '/')
        {
          if(flagBracket == 1)
          {
            while(getTopString(stackLabel)[0] != '(')
            {
              pushString(stackNumber, popString(stackLabel));
            }
          }
          else
          {
            while((stackLabel->top) > 0)
            {
              pushString(stackNumber, popString(stackLabel));
            }
          }
        }

        pushString(stackLabel, "/");
      }

      if(*p == '+')
      {
        if(flagBracket == 1)
        {
          while(getTopString(stackLabel)[0] != '(')
          {
            pushString(stackNumber, popString(stackLabel));
          }
        }
        else
        {
          while((stackLabel->top) > 0)
          {
            pushString(stackNumber, popString(stackLabel));
          }
        }

        pushString(stackLabel, "+");
      }

      if(*p == '-')
      {
        if(flagBracket == 1)
        {
          while(getTopString(stackLabel)[0] != '(')
          {
            pushString(stackNumber, popString(stackLabel));
          }
        }
        else
        {
          while((stackLabel->top) > 0)
          {
            pushString(stackNumber, popString(stackLabel));
          }
        }

        pushString(stackLabel, "-");
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

  while((stackLabel->top) > 0)
  {
    pushString(stackNumber, popString(stackLabel));
  }

  while((stackNumber->top) > 0)
  {
    printf("Member: %s\n", (stackNumber->string)[stackNumber->top]);
    pushString(stackOpera, popString(stackNumber));
  }

  int left = 0;
  int right = 0;
  int result = 0;
  int flagLeft = 0;
  int flagRight = 0;
  int flagResult = 0;

  while((stackOpera->top) > 0)
  {
    if(getTopString(stackOpera)[0] == '*')
    {
      right = atoi(popString(stackResult));
      left = atoi(popString(stackResult));
      result = left * right;

      // printf("Result: %d\n", result);

      char tmp[32] = {0};
      sprintf(tmp,"%d",result);
      pushString(stackResult, tmp);
    }
    else if(getTopString(stackOpera)[0] == '/')
    {
      right = atoi(popString(stackResult));
      left = atoi(popString(stackResult));
      result = left / right;

      // printf("Result: %d\n", result);

      char tmp[32] = {0};
      sprintf(tmp,"%d",result);
      pushString(stackResult, tmp);
    }
    else if(getTopString(stackOpera)[0] == '+')
    {
      right = atoi(popString(stackResult));
      left = atoi(popString(stackResult));
      result = left + right;

      // printf("Result: %d\n", result);

      char tmp[32] = {0};
      sprintf(tmp,"%d",result);
      pushString(stackResult, tmp);
    }
    else if(getTopString(stackOpera)[0] == '-')
    {
      right = atoi(popString(stackResult));
      left = atoi(popString(stackResult));
      result = left - right;

      // printf("Result: %d\n", result);

      char tmp[32] = {0};
      sprintf(tmp,"%d",result);
      pushString(stackResult, tmp);
    }
    else
    {
      pushString(stackResult, getTopString(stackOpera));
    }

    (stackOpera->top)--;
  }

  printf("Result: %s\n", getTopString(stackResult));
}