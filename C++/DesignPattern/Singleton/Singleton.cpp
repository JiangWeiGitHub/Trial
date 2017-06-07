#include "./Singleton.h"

Singleton* Singleton::_instance = NULL;

Singleton::Singleton()
{
  this->_number = 0;
}

Singleton::~Singleton()
{
  this->_number = 0;
}

int Singleton::getNumber()
{
  return this->_number;
}

bool Singleton::setNumber(int number)
{
  this->_number = number;

  return true;
}

Singleton* Singleton::getInstance()
{
  if(!Singleton::_instance)
  {
    Singleton::_instance = new Singleton();
  }

  return Singleton::_instance;
}