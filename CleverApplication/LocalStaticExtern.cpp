#include "LocalStaticExtern.h"
#include <iostream>
#include "NamespaceHeader_F.h"

using namespace NamespaceHeader;

void outer_test_func()
{
	NamespaceHeader::y = 2;
	std::cout << "outer_test_func() and y=" << y << std::endl;
}

void inner_test_func()
{
	std::cout << "inner_test_func()" << std::endl;
}