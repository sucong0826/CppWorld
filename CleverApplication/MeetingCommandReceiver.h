#pragma once

#include "IMeetingCommandReceiver.h"
#include "IMeetingCommandExecutor.h"

class MeetingCommandReceiver : public IMeetingCommandReceiver
{
public:
	MeetingCommandReceiver(IMeetingCommandExecutor* commandExecutor);
	virtual ~MeetingCommandReceiver();
	virtual void ReceiveCommand(int command, MeetingCommandArgument& argument);

private:
	IMeetingCommandExecutor* pCommandExecutor;
};