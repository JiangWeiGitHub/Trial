#include "./Pimpl.h"
#include "./PrivateClass.h"

Pimpl::Pimpl()
{
  this->_privateClass = new PrivateClass(100);
}

Pimpl::~Pimpl()
{
  delete this->_privateClass;
  this->_privateClass = NULL;
}

int Pimpl::addWithPrivateNumber(int number)
{
  int tmp = this->_privateClass->get() + number;

  return tmp;
}