#include "MeetingCommandExecutor.h"
#include <vector>

MeetingCommandExecutor::MeetingCommandExecutor(IMeetingCommandDispatcher* commandDispatcher)
	: pCommandDispatcher(nullptr)
{
	pCommandDispatcher = commandDispatcher;
}

MeetingCommandExecutor::~MeetingCommandExecutor()
{
	pCommandDispatcher = nullptr;
}

void MeetingCommandExecutor::ExecuteCommand(int command, MeetingCommandArgument& argument)
{
	// in MeetingCommandDispatcher, you can call any module to handle the specific log
	if (command == 1)
	{
		// command == 1 means to generate a list of random numbers from 0-10.
		std::vector<int> randomNumbers{1, 3, 5, 6};
		if (pCommandDispatcher) pCommandDispatcher->DispatchCommandResult(command, &randomNumbers);
	}
}