

// input string just like 11 * 8 - (10 / 2) + 7

// out put 11 8 * - 10 2 / + 7

// out put 90

#include "./calculator.h"

void main(void)
{
  // calculator("9+(3-1)*3+10/2"); // 9 3 1 - 3 * + 10 2 / +
  // calculator("10-(5*6+2)*3+4"); // 10 5 6 * 2 + 3 * - 4 +
  // calculator("(5+2)*3-8"); // 5 2 + 3 * 8 -
  calculator("354+(41-48*8-24/1)*5+81-8"); // 354 41 48 8 * - 24 1 / - 5 * + 81 + 8 -
}