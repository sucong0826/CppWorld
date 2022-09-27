#pragma once

#include "MeetingCommandArgument.h"

class IMeetingCommandExecutor
{
public:
	virtual void ExecuteCommand(int command, MeetingCommandArgument& argument) = 0;
};