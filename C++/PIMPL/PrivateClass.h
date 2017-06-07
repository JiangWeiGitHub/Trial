class PrivateClass
{
  public:
    PrivateClass(int number);
    ~PrivateClass();

    int get(void);

  private:
    int _number;
};