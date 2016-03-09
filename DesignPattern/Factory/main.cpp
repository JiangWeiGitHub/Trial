#include "factory.h"

int main(void)
{
    factory *ProductFactory = new factory();

    product *productA = ProductFactory->create_product(TYPE_A);
    if(productA != NULL)
        productA->show();

    product *productB = ProductFactory->create_product(TYPE_B);
    if(productB != NULL)
        productB->show();

    delete ProductFactory;
    ProductFactory = NULL;

    delete productA;
    productA = NULL;

    delete productB;
    productB = NULL;        

    return 0;
}
