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
        // printf("ttttttttttttttttt\n");
        // printf("stackNumber->top: %d\n", stackNumber->top);
        
      }

      // printf("asdfsdafsdfsdfsadfsdfsadfsdfsdaf\n");

      if(*p == '(')
      {
        pushString(stackLabel, "(");
      }

      // printf("111111111111111\n");

      if(*p == ')')
      {
        while(getTopString(stackLabel)[0] != '(')
        {
          pushString(stackNumber, popString(stackLabel));
          // printf("aaaaaaaaaaaa\n");
          // printf("stackNumber->top: %d\n", stackNumber->top);
        }

        popString(stackLabel);
      }
      // printf("22222222222222222222\n");

      if(*p == '*')
      {
        printf("tttttttttt\n");
        pushString(stackLabel, "*");
        printf("ssssssssssssss\n");
      }

      // printf("333333333333333333\n");

      if(*p == '/')
      {
        pushString(stackLabel, "/");
      }

      // printf("4444444444444444444444444\n");

      if(*p == '+')
      {
        if(getTopString(stackLabel)[0] == '*' || getTopString(stackLabel)[0] == '/')
        {
          pushString(stackNumber, popString(stackLabel));
          // printf("bbbbbbbbbbbbbbbbbbb\n");
          // printf("stackNumber->top: %d\n", stackNumber->top);
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
          // printf("ccccccccccccccccccccc\n");
          // printf("stackNumber->top: %d\n", stackNumber->top);
        }
        else
        {
          pushString(stackLabel, "-");
        }   
      }
    }

    p++;
  }

  // printf("ddddddddddddddd\n");

  if(counter != 0)
  {
    number[counter] = '\0';
    counter = 0;

    // printf("number: %s\n", number);

    pushString(stackNumber, number);
  }


  
  // // int i = 0;
  while((stackNumber->top) != 0)
  {
    printf("Member: %s\n", popString(stackNumber));
  }
}