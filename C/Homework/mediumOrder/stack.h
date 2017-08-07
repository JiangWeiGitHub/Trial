#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stringStack
{
  char string[32][32];
  int top;
};

struct stringStack *intiStringStack();

void pushString(struct stringStack *stack, char *string);

char *popString(struct stringStack *stack);

char *getTopString(struct stringStack *stack);