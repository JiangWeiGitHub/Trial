#include <iostream>

bool Enclidean(int small, int remainder)
{
  remainder ?
  ( small > remainder ? Enclidean(remainder, small % remainder) : Enclidean(small, remainder % small) )
            :
  ( std::cout << "The Greatest Common Divisor is: " << small << std::endl );

  return true;
}

int main(void)
{
  int a = 78;
  int b = 54;

  a > b ? Enclidean(b, a % b) : Enclidean(a, b % a);

  return 0;
}
