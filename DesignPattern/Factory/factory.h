#include <iostream>

using namespace std;

class product
{
public:
    virtual void show() = 0;
};

class productA: public product
{
public:
    void show(){cout<<"I'm Product A!"<<endl;}
};

class productB: public product
{
public:
    void show(){cout<<"I'm Product B!"<<endl;}
};

class factory
{
public:
    virtual product* createProduct() = 0;
};

class factoryA: public factory
{
public:
    product* createProduct()
    {
        return new productA();
    }
};

class factoryB: public factory
{
public:
    product* createProduct()
    {
        return new productB();
    }
};




