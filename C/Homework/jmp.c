#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

void a()
{
  printf("I'm TRUE!\n");
}

void b()
{
  printf("I'm FALSE!\n");
  longjmp(env, 999);
}

int main(int argc, char** argv)
{
  int tmp = setjmp(env);

  printf("setjmp: %d\n", tmp);

  if(argc != 3)
  {
    return -1;
  }

  if(tmp != 0)
  {
    printf("Something Wrong!\n");

    return -2;
  }

  if(atoi(argv[1]) + atoi(argv[2]) >= 0)
  {
    a();
  }
  else
  {
    b();
  }

  return 0;
}