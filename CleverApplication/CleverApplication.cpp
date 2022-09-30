// CleverApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "StaticControl.h"
#include "StaticObjects.h"
#include "LocalStaticExtern.h"
#include "NamespaceHeader_S.h"
#include "NamespaceHeader_F.h"
#include "Person.h"
#include "StaticInt.h"
#include "TestHelper.h"
#include "EnumConst.h"
#include "CustomizedQueue.h"
#include "TheFirstHeader.h"
#include "TheSecondHeader.h"
#include "MeetingCommandShell.h"
#include "MeetingVideoCommandArgument.h"
#include "ValistTemplate.h"
#include "FastCommandShell.h"

using namespace NamespaceHeader;
namespace NHeader = NamespaceHeader;

int NHeader::x = 2;
int NHeader::y = 3;

void FriendInjection::print_counter(const FriendInjection::Us &rUs)
{	
	std::cout << "FriendInjection::print_counter() counter=" << rUs.counter << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";

	// 10.1 - static local variable
	std::shared_ptr<StaticControl> pStcControl = std::make_shared<StaticControl>();
	if (pStcControl)
	{	
		// if we don't type 'const', IDE will report an error.
		// this is because "abcdefg" is an literal value, compiler will regard it as a const character array.
		// so if I don't type 'const', the IDE will report an error.
		// a const character array can't be modified or updated while running.
		// if we really want to create a value of char array that needed to change sometimes, we can
		// -----------------------
		// char cp[] = "abcdef";
		// -----------------------
		
		const char* test_char = "abcdefg";	// const char test_char[] = "abcdefg";
		pStcControl->oneChar(test_char);
		char c;
		while ((c = pStcControl->oneChar()) != 0)
		{	
			// pStcControl->oneChar() to reset the char array ...
			std::cout << c << std::endl;
		}
	}

	// 10.2 - static objects
	static StaticObjects so1(19);
	static StaticObjects so2;		// default constructor required.
	so1.printProperites();
	so2.printProperites();

	outer_test_func();
	// inner_test_func(); can't be used because the method is static.

	// test_func_within_annoymous_ns() function can't be called
	// because it is included in an annoymous namespace, any method
	// in it will be static, that is, link inside. so it can't be accessed.
	// test_func_within_annoymous_ns();

	FriendInjection::Us rUs(0);
	rUs.us_member();
	FriendInjection::print_counter(rUs);

	// how to create a person
	// here are the ways:
	Person normal("Clever", 12);
	Person* person = new Person("Damn", 15);
	Person& copy = *person;

	std::cout << "person addr=" << person << std::endl;
	std::cout << "copy addr=" << &copy << std::endl;
	
	TestHelper::fcn(person, copy);
	delete person;

	UserType userType = BACKGROUND;
	if (userType == BACKGROUND)
	{
		std::cout << "user type is background user" << std::endl;
	}
	else if (userType == NORMAL)
	{
		std::cout << "user type is a normal user" << std::endl;
	}

	unsigned int a = 1;
	a = 4294967296;
	std::cout << "the unsigned int a = " << a << std::endl;

	CustomizedQueue<int, 3> queue;
	bool is_last_node_added = queue.add_last(0);
	queue.add_last(1);
	queue.add_last(2);
	queue.add_last(3);
	bool is_empty = queue.is_empty();
	size_t size = queue.size();
	std::cout << "is_last_node_added = " << is_last_node_added << ", is_empty=" << is_empty << ", size=" << size << std::endl;
	
	// queue.remove_last();
	// queue.remove_last();
	// queue.remove_all();
	int* last_val = queue.get_last();
	int* first_val = queue.get_first();
	int* value = queue.get(10);
	bool is_set = queue.set(0, 4);
	is_set = queue.set(1, 5);
	is_set = queue.set(2, 6);
	is_set = queue.set(5, 10);
	
	// static fields are shared by all instances
	// verified!
	// StaticInt static_int, static_int_copy;
	// static_int.print();
	// static_int_copy.print();

	// command shell test cases:
	MeetingCommandShell* cmdShell = new MeetingCommandShell();
	if (cmdShell)
	{
		MeetingVideoCommandArgument arg;
		arg.videoFeatureType = 2;
		cmdShell->ReceiveCommand(1, (MeetingCommandArgument&)arg);

		FastCommandShell::NewFastCommand(1)
			->ExecuteCommand(
				[](int command) -> void
				{
					std::cout << "ExecuteCommand() command=" << command << std::endl;
				})
			->OnCommandExecuted(
				[](int command) -> void
				{
					std::cout << "OnCommandExecuted() command=" << command << std::endl;
				})
			->Run();

		FastCommandShell::NewFastCommand<MeetingVideoCommandArgument>(1, &arg)
			->ExecuteCommand(
				[](int command, MeetingVideoCommandArgument* input) -> void
				{
					std::cout << "ExecuteCommand() command=" << command << ", input=" << input->videoFeatureType << std::endl;
				})
			->OnCommandExecuted(
				[](int command) -> void
				{
					std::cout << "OnCommandExecuted() command=" << command << std::endl;
				})
					->Run();


		FastCommandShell::NewFastCommandInputOutput<MeetingVideoCommandArgument, int>(1, &arg)
			->ExecuteCommand([](int command, MeetingVideoCommandArgument* input) -> int*
				{
					int sum = 0;
					if (command == 1)
					{
						sum = input->videoFeatureType + command;
					}

					return &sum;
				})
			->OnCommandExecuted([](int command, int* output) -> void 
				{
					if (command == 1 && output)
					{
						int sum = *output;
						std::cout << "OnCommandExecuted() output=" << sum << std::endl;
					}
				})->Run();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
