#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int number[1024];
  int top;
};

void init(struct stack *name)
{
  name->top = 0;
}

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
  if(name->top < 1023 && name->top >= 0)
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
  if(name->top > 0)
  {
    return (name->number)[name->top];
  }
  else
  {
    return 65535;
  }
}

struct stack *one;
struct stack *two;

int main(void)
{
  one = (struct stack *)malloc(sizeof(struct stack));
  two = (struct stack *)malloc(sizeof(struct stack));
  init(one);
  init(two);

  int tmp[] = {5,4,3,6,8,9,2,14};
  int i;
  for(i = 0; i < (sizeof(tmp) / sizeof(tmp[0])); i ++)
  {
    push(one, tmp[i]);
    if(tmp[i] < getMini(two))
    {
      push(two, tmp[i]);
    }
  }

  printf("one: ");
  for(i = 0; i <= one->top; i ++)
  {
    printf("%d ", (one->number)[i]);
  }
  printf("\n");

  printf("two: ");
  for(i = 0; i <= two->top; i ++)
  {
    printf("%d ", (two->number)[i] );
  }

  printf("\n");

  printf("******************************************\n");
  
  if( getMini(two) == (one->number)[one->top] )
  {
    pop(one);
    pop(two);
  }
  else
  {
    pop(one);
  }

  if( getMini(two) == (one->number)[one->top] )
  {
    pop(one);
    pop(two);
  }
  else
  {
    pop(one);
  }

  printf("one: ");
  for(i = 0; i <= one->top; i ++)
  {
    printf("%d ", (one->number)[i]);
  }
  printf("\n");

  printf("two: ");
  for(i = 0; i <= two->top; i ++)
  {
    printf("%d ", (two->number)[i] );
  }

  printf("\n");

  return 0;
}