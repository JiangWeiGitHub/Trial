#include <stdio.h>

int dynamicProgrammming(int stepNumber)
{
  if(stepNumber == 0)
  {
    return 0;
  }
  else if(stepNumber == 1)
  {
    return 1;
  }
  else if(stepNumber == 2)
  {
    return 2;
  }
  else if(stepNumber < 0)
  {
    return -65535;
  }

  int i, tmp;
  int stepOne = 1;
  int stepTwo = 2;
  for(i = 3; i <= stepNumber; i++)
  {
    tmp = stepOne + stepTwo;
    stepOne = stepTwo;
    stepTwo = tmp;
  }

  return tmp;
}

void main(void)
{
  int result = dynamicProgrammming(44);
  printf("Result: %d\n", result);
}