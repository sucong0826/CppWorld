#include "TestHelper.h"
#include <iostream>

namespace TestHelper
{
	bool fcn(Person* p1, Person p2)
	{	
		Person oP1(*p1);
		Person oP2(p2);
		
		std::cout << "p1 addr=" << &p1 << std::endl;
		std::cout << "p1 host addr=" << &(*p1) << std::endl;
		std::cout << "p2 addr=" << &p2 << std::endl;
		std::cout << "op1 addr=" << &oP1 << std::endl;
		std::cout << "op2 addr=" << &oP2 << std::endl;
		
		return oP1.getAge() == oP2.getAge();
	}
}