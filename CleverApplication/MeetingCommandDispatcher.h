#pragma once

#include "IMeetingCommandDispatcher.h"
#include "IMeetingCommandChannel.h"

class MeetingCommandDispatcher : public IMeetingCommandDispatcher
{
public:
	MeetingCommandDispatcher(IMeetingCommandChannel* commandChannel);
	virtual ~MeetingCommandDispatcher();
	virtual void DispatchCommandResult(int command, void* payload);

private:
	IMeetingCommandChannel* pCommandChannel;
};