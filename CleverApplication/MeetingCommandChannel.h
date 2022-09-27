#pragma once

#include "IMeetingCommandChannel.h"

class MeetingCommandChannel : public IMeetingCommandChannel
{
public:
	MeetingCommandChannel();
	virtual ~MeetingCommandChannel();

	virtual void OnCommandExecuted(int command, void* payload);
	virtual void OnCommandReceived(int command, MeetingCommandArgument& arg);
};