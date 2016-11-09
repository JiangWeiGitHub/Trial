#include <iostream>

using namespace std;

enum PRODUCT_TYPE
{
    TYPE_A,
    TYPE_B
};

class product
{
public:
    virtual void show() = 0;
};

class productA: public product
{
public:
    void show(void)
    {
        cout<<"I'm product A!"<<endl;
    }
};

class productB: public product
{
public:
    void show(void)
    {
        cout<<"I'm product B!"<<endl;
    }
};

class factory
{
public:
    product *create_product(PRODUCT_TYPE type)
    {
        switch (type)
        {
            case TYPE_A:
                return new productA();

            case TYPE_B:
                return new productB();

            default:
                return NULL;
        }
    }
};

