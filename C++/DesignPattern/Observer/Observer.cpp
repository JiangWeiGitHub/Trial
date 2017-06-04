#include "./Observer.h"

Observer::Observer()
{
  this->_name = "Observer";
}

Observer::~Observer()
{
  this->_name = "Observer";
}

void Observer::callMe(void)
{
  std::cout<<this->_name<<std::endl;
}