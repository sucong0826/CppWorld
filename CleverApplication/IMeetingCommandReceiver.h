#pragma once

#include "MeetingCommandArgument.h"

class IMeetingCommandReceiver
{
public:
	virtual void ReceiveCommand(int command, MeetingCommandArgument& argument) = 0;
};