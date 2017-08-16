#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int number[1024];
  int top;
};

int pop(struct stack *name)
{
  if(name->top > 1)
  {
    name->top -= 1;
    return (name->number)[name->top + 1];
  }
  else
  {
    return -1;
  }
}

void push(struct stack *name, int number)
{
  if(name->top < 1023 && name->top > 0)
  {
    name->top += 1;
    (name->number)[name->top] = number;
  }
  else
  {
    ;
  }
}

int getMini(struct stack *name)
{
  return (name->number)[name->top];
}

struct stack *one = (struct stack *)malloc(sizeof(struct stack));
struct stack *two = (struct stack *)malloc(sizeof(struct stack));

int main(void)
{
  int tmp[3] = {5,4,3};
  int i;
  for(i = 0; i < (sizeof(tmp) / sizeof(tmp[0])); i ++)
  {
    push(one, tmp[i]);
    if(tmp[i] < getMini(two))
    {
      push(two, tmp[i]);
    }
  }

  for(i = 0; i < (sizeof(tmp) / sizeof(tmp[0])); i ++)
  {
    printf("one: %d, two: %d\n", (one->number)[i], (two->number)[i] );
  }

  return 0;
}