#pragma once

#include "MeetingCommandArgument.h"

class IMeetingCommandChannel
{
public:
	virtual void OnCommandExecuted(int command, void* payload) = 0;
	virtual void OnCommandReceived(int command, MeetingCommandArgument& arg) = 0;
};