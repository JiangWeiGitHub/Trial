#include "./Product.h"

int main(){
	// simple usage
	Product p1 = Product::Builder().setI(2).setF(0.5f).setC('x').build();
	p1.print(); // test p1

	// advanced usage
	Product::Builder b;
	b.setProductP();
	Product p2 = b.build(); // get Product P object
	b.setC('!'); // customize Product P
	Product p3 = b.build();
	p2.print(); // test p2
	p3.print(); // test p3
}