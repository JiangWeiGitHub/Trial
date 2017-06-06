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

// template <typename _DATA_TYPE_>
int Pimpl::addWithPrivateNumber(int number)
{
  int tmp = this->_privateClass->get() + number;

  std::cout << tmp << std::endl;

  return tmp;
}