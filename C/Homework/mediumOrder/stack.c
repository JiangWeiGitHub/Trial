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

  tmp->top = 0;

  return tmp;
}

void pushString(struct stringStack *stack, char *string)
{
  (stack->top)++;
  memset((stack->string)[stack->top], 0, strlen((stack->string)[stack->top]));
  strcpy((stack->string)[stack->top], string);
}

char *popString(struct stringStack *stack)
{
  (stack->top)--;

  return (stack->string)[stack->top + 1];
}

char *getTopString(struct stringStack *stack)
{
  if(stack->top <= -1)
  {
    return NULL;
  }

  return (stack->string)[stack->top];
}