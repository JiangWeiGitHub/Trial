#include "./PrivateClass.h"

PrivateClass::PrivateClass(int number)
{
  this->_number = number;
}

PrivateClass::~PrivateClass()
{
  this->_number = 0;
}

int PrivateClass::get()
{
  return this->_number;
}