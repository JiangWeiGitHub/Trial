#include <iostream>

class Singleton
{
  public:
  static Singleton* getInstance();
  int getNumber();
  bool setNumber(int number);

  private:
  Singleton();
  ~Singleton();

  static Singleton* _instance;
  int _number;
};