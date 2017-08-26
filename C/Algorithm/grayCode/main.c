#include <stdio.h>

int gray(int content, int number)
{
  if(0 != number)
  {
    content ^= 1 << (number - 1);
    printf("Content: %x\n", content);
    return gray(content, --number);
  }
  else
  {
    return content;
  }
}

void run(int number)
{
  gray(0, number);
}

void main(void)
{
  run(8);
}