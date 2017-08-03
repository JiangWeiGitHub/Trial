#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stringStack
{
  char string[32][32];
  int top;
};

// char stringStack[32][32];
// int stringStackTop;

// int intStack[32];
// int intStackTop;

struct stringStack *intiStringStack();
// void intiIntStack();

void pushString(struct stringStack *stack, char *string);
// int pushInt(int number);

char *popString(struct stringStack *stack);
// int popInt();

char *getTopString(struct stringStack *stack);