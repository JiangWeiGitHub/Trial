#include "factory.h"

int main(void)
{
    factory *facA = new factoryA();
    product *proA = facA->createProduct();
    proA->show();

    factory *facB = new factoryB();
    product *proB = facB->createProduct();
    proB->show();

    if(facA != NULL)
    {
        delete facA;
        facA = NULL;
    }

    if(facB != NULL)
    {
        delete facB;
        facB = NULL;
    }

    if(proA != NULL)
    {
        delete proA;
        proA = NULL;
    }

    if(proA != NULL)
    {
        delete proA;
        proA = NULL;
    }

    return 0;
}
