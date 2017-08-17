#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int number[1024];
  int top;
  struct stack *miniStack;
};

struct stack *init(void)
{
  struct stack *one = (struct stack *)malloc(sizeof(struct stack));
  struct stack *two = (struct stack *)malloc(sizeof(struct stack));
  
  one->top = 0;
  one->miniStack = two;

  two->top = 0;
  two->miniStack = NULL;
  
  return one;
}

int getMini(struct stack *name)
{
  if(name->miniStack->top > 0)
  {
    return (name->miniStack->number)[name->miniStack->top];
  }
  else
  {
    return 65535;
  }
}

int pop(struct stack *name)
{
  if(name->top > 0)
  {
    name->top -= 1;

    if((name->number)[name->top + 1] == getMini(name))
    {
      name->miniStack->top -= 1;
      (name->miniStack->number)[name->miniStack->top + 1] = 0;
    }

    return (name->number)[name->top + 1];
  }
  else
  {
    return -65535;
  }
}

void push(struct stack *name, int number)
{
  if(name->top < 1023 && name->top >= 0)
  {
    name->top += 1;
    (name->number)[name->top] = number;

    if(number < getMini(name))
    {
      name->miniStack->top += 1;
      (name->miniStack->number)[name->miniStack->top] = number;
    }

  }
  else
  {
    ;
  }
}

int main(void)
{
  struct stack *test = init();

  int tmp[] = {13,455,56,64854,42,5458,21,8,54,4,44,8};
  int i, j;
  for(i = 0; i < (sizeof(tmp) / sizeof(tmp[0])); i ++)
  {
    push(test, tmp[i]);
  }

  printf("\ntest: ");
  for(i = 0; i <= test->top; i ++)
  {
    printf("%d ", (test->number)[i]);
  }
  printf("\n");

  printf("miniStack: ");
  for(i = 0; i <= test->miniStack->top; i ++)
  {
    printf("%d ", (test->miniStack->number)[i] );
  }

  printf("\n\n");

  printf("******************************************");

  printf("\n");

  for(i = 0; i < (sizeof(tmp) / sizeof(tmp[0])); i ++)
  {
    printf("\nPop: %d\n", pop(test));

    printf("test: ");
    for(j = 0; j <= test->top; j ++)
    {
      printf("%d ", (test->number)[j]);
    }
    printf("\n");

    printf("miniStack: ");
    for(j = 0; j <= test->miniStack->top; j ++)
    {
      printf("%d ", (test->miniStack->number)[j] );
    }

    printf("\n");
  }

  return 0;
}