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

namespace
{
	void test_func_within_annoymous_ns()
	{
		std::cout << "test_func_within_annoymous_ns()" << std::endl;
	}
}

namespace FriendInjection
{
	void Us::us_member()
	{	
		++counter;
		std::cout << "FriendInjection::Us::us_member()" << std::endl;
	}
}

FriendInjection::Us::Us(int counter)
	: counter(counter)
{
	this->counter++;
}

FriendInjection::Us::~Us()
{
	counter = 0;
}

// friend function in namespace can only be defined in one place where 
// uses it. so we've defined it in the CleverApplication.cpp, can't be 
// defined here again.
// void FriendInjection::tell_you()
// {
// 	 std::cout << "FriendInjection::tell_you()" << std::endl;
// }