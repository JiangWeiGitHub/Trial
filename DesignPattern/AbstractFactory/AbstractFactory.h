#include <iostream>

using namespace std;

class ProductA
{
public:
    virtual void Show() = 0;
};

class ProductA1 : public ProductA
{
public:
    void Show()
    {
        cout<<"I'm ProductA1"<<endl;
    }
};

class ProductA2 : public ProductA
{
public:
    void Show()
    {
        cout<<"I'm ProductA2"<<endl;
    }
};

class ProductB
{
public:
    virtual void Show() = 0;
};

class ProductB1 : public ProductB
{
public:
    void Show()
    {
        cout<<"I'm ProductB1"<<endl;
    }
};

class ProductB2 : public ProductB
{
public:
    void Show()
    {
        cout<<"I'm ProductB2"<<endl;
    }
};

class Factory
{
public:
    virtual ProductA *CreateProductA() = 0;
    virtual ProductB *CreateProductB() = 0;
};

class Factory1 : public Factory
{
public:
    ProductA *CreateProductA()
    {
        return new ProductA1();
    }

    ProductB *CreateProductB()
    {
        return new ProductB1();
    }
};

class Factory2 : public Factory
{
    ProductA *CreateProductA()
    {
        return new ProductA2();
    }

    ProductB *CreateProductB()
    {
        return new ProductB2();
    }
};
