#include "StaticInt.h"
#include <iostream>

int StaticInt::x = 1;
int StaticInt::y = x + 1;

void StaticInt::print() const
{	
	using namespace std;
	cout << "StaticInt::x = " << x << endl;
	cout << "StaticInt::y = " << y << endl;
}