#include <iostream>

class PrivateClass;

class Pimpl
{
  public:
    Pimpl();
    ~Pimpl();

    template <typename _DATA_TYPE_>
    void echoNumber(_DATA_TYPE_ number)
    {
      std::cout << this->addWithPrivateNumber(number) << std::endl;
    };

    int addWithPrivateNumber(int number);

  private:
    PrivateClass* _privateClass;
};