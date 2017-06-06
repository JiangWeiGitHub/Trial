class PrivateClass
{
  public:
    PrivateClass(int number):_number(number){this->_number = 1000;};
    ~PrivateClass(){this->_number = 0;};

    int get(void){return this->_number;};

  private:
    int _number;
};