#pragma once

class IMeetingCommandDispatcher
{
public:
	virtual void DispatchCommandResult(int command, void* payload) = 0;
};
