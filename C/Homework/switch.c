#include <stdio.h>
#include <stdlib.h>

void main(int argc, char** argv)
{
  if(argc != 3)
  {
    printf("Wrong Input!\n");

    return;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  printf("First One: %d\n", a);
  printf("Second One: %d\n", b);

  a += b;
  b = a - b;
  a = a - b;

  printf("First One After Switch: %d\n", a);
  printf("Second One After Switch: %d\n", b);
}