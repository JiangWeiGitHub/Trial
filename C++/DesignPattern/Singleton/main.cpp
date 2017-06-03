#include "./Singleton.h"

int main(void)
{
  Singleton* tmp1 = Singleton::getInstance();
  Singleton* tmp2 = Singleton::getInstance();
  Singleton* tmp3 = Singleton::getInstance();

  int tmpNumber1 = tmp1->getNumber();
  int tmpNumber2 = tmp2->getNumber();
  int tmpNumber3 = tmp3->getNumber();

  std::cout<<"Number 1: "<<tmpNumber1<<std::endl;
  std::cout<<"Number 2: "<<tmpNumber2<<std::endl;
  std::cout<<"Number 3: "<<tmpNumber3<<std::endl;

  tmp1->setNumber(1);

  tmpNumber1 = tmp1->getNumber();
  tmpNumber2 = tmp2->getNumber();
  tmpNumber3 = tmp3->getNumber();

  std::cout<<"Number 1: "<<tmpNumber1<<std::endl;
  std::cout<<"Number 2: "<<tmpNumber2<<std::endl;
  std::cout<<"Number 3: "<<tmpNumber3<<std::endl;

  tmp2->setNumber(22);

  tmpNumber1 = tmp1->getNumber();
  tmpNumber2 = tmp2->getNumber();
  tmpNumber3 = tmp3->getNumber();

  std::cout<<"Number 1: "<<tmpNumber1<<std::endl;
  std::cout<<"Number 2: "<<tmpNumber2<<std::endl;
  std::cout<<"Number 3: "<<tmpNumber3<<std::endl;

  tmp3->setNumber(333);

  tmpNumber1 = tmp1->getNumber();
  tmpNumber2 = tmp2->getNumber();
  tmpNumber3 = tmp3->getNumber();

  std::cout<<"Number 1: "<<tmpNumber1<<std::endl;
  std::cout<<"Number 2: "<<tmpNumber2<<std::endl;
  std::cout<<"Number 3: "<<tmpNumber3<<std::endl;

  return 0;
}