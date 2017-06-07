#include "./Observer.h"

void a(int a)
{
  if(a == 1)
  {
    Observer* tmp = new Observer();
    tmp->callMe();
  }
}

void b(int b)
{
  if(b == 2)
  {
    Observer* tmp = new Observer();
    tmp->callMe();
  }
}

void c(int c)
{
  if(c == 3)
  {
    Observer* tmp = new Observer();
    tmp->callMe();
  }
}

int main(void)
{
  a(1);
  b(3);
  c(3);

  return 0;
}