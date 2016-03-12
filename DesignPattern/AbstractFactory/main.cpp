#include "AbstractFactory.h"

int main(void)
{
    Factory *factoryObj1 = new Factory1();
    ProductA *productObjA1 = factoryObj1->CreateProductA();
    ProductB *productObjB1 = factoryObj1->CreateProductB();

    productObjA1->Show();
    productObjB1->Show();

    Factory *factoryObj2 = new Factory2();
    ProductA *productObjA2 = factoryObj2->CreateProductA();
    ProductB *productObjB2 = factoryObj2->CreateProductB();

    productObjA2->Show();
    productObjB2->Show();

    if (factoryObj1 != NULL)
    {
        delete factoryObj1;
        factoryObj1 = NULL;
    }

    if (productObjA1 != NULL)
    {
        delete productObjA1;
        productObjA1= NULL;
    }

    if (productObjB1 != NULL)
    {
        delete productObjB1;
        productObjB1 = NULL;
    }

    if (factoryObj2 != NULL)
    {
        delete factoryObj2;
        factoryObj2 = NULL;
    }

    if (productObjA2 != NULL)
    {
        delete productObjA2;
        productObjA2 = NULL;
    }

    if (productObjB2 != NULL)
    {
        delete productObjB2;
        productObjB2 = NULL;
    }

    return 0;
}
