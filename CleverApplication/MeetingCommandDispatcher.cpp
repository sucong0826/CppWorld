#include "MeetingCommandDispatcher.h"
#include <iostream>

MeetingCommandDispatcher::MeetingCommandDispatcher(IMeetingCommandChannel* commandChannel)
	: pCommandChannel(nullptr)
{
	pCommandChannel = commandChannel;
}

MeetingCommandDispatcher::~MeetingCommandDispatcher()
{
	pCommandChannel = nullptr;
}

void MeetingCommandDispatcher::DispatchCommandResult(int command, void* payload)
{
	std::cout << "MeetingCommandDispatcher::DispatchCommandResult() command=" << command << ", payload=" << payload << std::endl;
	if (pCommandChannel)
	{
		pCommandChannel->OnCommandExecuted(command, payload);
	}
}

