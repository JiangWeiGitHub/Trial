#include "./stack.h"

struct stringStack *intiStringStack()
{
  struct stringStack *tmp = (struct stringStack *)malloc(sizeof(struct stringStack));
  
  int i, j;
  for(i = 0; i < 32; i++)
  {
    for(j = 0; j < 32; j++)
    {
      (tmp->string)[i][j] = 0;
    }
  }

  tmp->top = -1;

  return tmp;
}

void pushString(struct stringStack *stack, char *string)
{
  strcpy((stack->string)[(stack->top)++], string);
  printf("top: %d\n", stack->top);
}

char *popString(struct stringStack *stack)
{
  printf("top before: %d\n", stack->top);
  memset((stack->string)[(stack->top)--], 0, strlen((stack->string)[stack->top]));
  printf("top after: %d\n", stack->top);
}

char *getTopString(struct stringStack *stack)
{
  if(stack->top <= -1)
  {
    return NULL;
  }

  return (stack->string)[stack->top];
}

// char *intiStringStack()
// {
//   char *stringStack = (char *)malloc(char * 32 * 32);
  
//   int i, j;
//   for(i = 0; i < 32; i++)
//   {
//     for(j = 0; j < 32; j++)
//     {
//       stringStack[i][j] = 0;
//     }
//   }

//   return stringStack;
// }

// void intiIntStack()
// {
//   int i;
//   for(i = 0; i < 32; i++)
//   {
//     intStack[i] = 0;
//   }

//   intStackTop = 0;
// }

// void pushString(char *stack, char *string, int stringStackTop)
// {
//   strcpy(stack[stringStackTop++], string);
// }

// void pushInt(int number)
// {
//   intStack[intStackTop] = number;
// }

// char *popString(char *stack, int stringStackTop)
// {
//   memset(stack[stringStackTop--], 0, strlen(stack[stringStackTop--]));
// }

// int popInt()
// {
//   intStack[intStackTop--] = 0;
// }