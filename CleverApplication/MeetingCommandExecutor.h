#pragma once

#include "IMeetingCommandExecutor.h"
#include "IMeetingCommandDispatcher.h"

class MeetingCommandExecutor : public IMeetingCommandExecutor
{
public:
	MeetingCommandExecutor(IMeetingCommandDispatcher* commandDispatcher);
	virtual ~MeetingCommandExecutor();
	virtual void ExecuteCommand(int command, MeetingCommandArgument& argument);

private:
	IMeetingCommandDispatcher* pCommandDispatcher;
};