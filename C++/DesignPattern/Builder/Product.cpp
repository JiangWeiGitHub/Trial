#include <iostream>
#include "./Product.h"

void Product::print(){
	using namespace std;

	cout << "Product internals dump:" << endl;
	cout << "i: " << this->i << endl;
	cout << "f: " << this->f << endl;
	cout << "c: " << this->c << endl;
}

void Product::doSomething(){}
void Product::doSomethingElse(){}