#include <iostream>

class Observer
{
public:
  Observer();
  ~Observer();

  void callMe(void);

private:
  std::string _name;
};