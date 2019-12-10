#pragma once
#include <iostream>

namespace
{
	void test_func_within_annoymous_ns();
}

namespace FriendInjection
{
	class Us
	{
		friend void print_counter(const FriendInjection::Us &rUs);
	public:
		Us(int counter);
		~Us();
		void us_member();
	
	private:
		int counter;
	};
}

class LocalStaticExtern
{
};

// an extern method can be accessed in another transfering unit.
// that is, can be called in other files when header file is included
extern void outer_test_func();

// an static method can't be accessed in another transtering unit.
// that is, can't be called in other files when header file is included
static void inner_test_func();
