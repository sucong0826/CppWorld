#include "Urand.h"
#include <iostream>

int main()
{
	Urand<10> u;
	for (int i = 0; i < 20; ++i)
	{
		std::cout << u() << ' ';
	}
}