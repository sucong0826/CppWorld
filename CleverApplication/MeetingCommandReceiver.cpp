#include "MeetingCommandReceiver.h"
#include <iostream>

#define TAG "MeetingCommandReceiver::ReceiveCommand()"

MeetingCommandReceiver::MeetingCommandReceiver(IMeetingCommandExecutor* commandExecutor)
	: pCommandExecutor(nullptr)
{
	pCommandExecutor = commandExecutor;
}

MeetingCommandReceiver::~MeetingCommandReceiver()
{
	pCommandExecutor = nullptr;
}

void MeetingCommandReceiver::ReceiveCommand(int command, MeetingCommandArgument& argument)
{
	// you can pre-handle the command and argument if need
	// if no need to pre-handle, deliever the command to the CommandExecutor.
	std::cout << TAG << ", command=" << command << std::endl;
	pCommandExecutor->ExecuteCommand(command, argument);
}