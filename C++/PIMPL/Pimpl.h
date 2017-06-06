#include <iostream>

// template <typename _DATA_TYPE_>

class Pimpl
{
  public:
    Pimpl();
    ~Pimpl();

    // template <typename _DATA_TYPE_>
    int addWithPrivateNumber(int number);

  private:
    class PrivateClass;
    PrivateClass* _privateClass;
};