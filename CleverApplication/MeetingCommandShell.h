#pragma once

#include "IMeetingCommandChannel.h"
#include "IMeetingCommandDispatcher.h"
#include "IMeetingCommandExecutor.h"
#include "IMeetingCommandReceiver.h"
#include <functional>

class MeetingCommandShell : public IMeetingCommandChannel, public IMeetingCommandDispatcher, 
	public IMeetingCommandReceiver, public IMeetingCommandExecutor
{
public:
	explicit MeetingCommandShell();
	virtual ~MeetingCommandShell();

	virtual void OnCommandExecuted(int command, void* payload);
	virtual void OnCommandReceived(int command, MeetingCommandArgument& arg);
	virtual void ExecuteCommand(int command, MeetingCommandArgument& arg);
	virtual void DispatchCommandResult(int command, void* payload);
	virtual void ReceiveCommand(int command, MeetingCommandArgument& arg);

private:
	IMeetingCommandDispatcher* mCommandDispatcher;
	IMeetingCommandReceiver* mCommandReceiver;
	IMeetingCommandChannel* mCommandChannel;
	IMeetingCommandExecutor* mCommandExecutor;
};

class FastCommand;

class FastCommand
{
public:
	friend class FastCommandShell;

	FastCommand()
		: command(-1)
		, arg(nullptr)
		, exeCmd(nullptr)
		, onCmdExe(nullptr)
	{

	}

	virtual ~FastCommand()
	{
		command = -1;
		if (arg)
		{
			delete arg;
			arg = nullptr;
		}
	}

	FastCommand* ReceiveCommand(int command, MeetingCommandArgument* arg)
	{
		this->command = command;
		this->arg = arg;
		return this;
	}

	FastCommand* ExecuteCommand(std::function<void* (int, MeetingCommandArgument*)> executeCommandLmd)
	{
		this->exeCmd = executeCommandLmd;
		return this;
	}

	FastCommand* OnCommandExecuted(std::function<void(int, void*)> onCommandExecutedLmd)
	{
		this->onCmdExe = onCommandExecutedLmd;
		return this;
	}

	void Run()
	{
		int cmd = this->command;
		MeetingCommandArgument* arg = this->arg;
		std::function<void* (int, MeetingCommandArgument*)> exeCmd = this->exeCmd;
		void* exeCmdResult = exeCmd(cmd, arg);

		// return result to java layer via JNI

		std::function<void(int, void*)> onCmdExe = this->onCmdExe;
		onCmdExe(cmd, exeCmdResult);
	}

private:
	int command;
	MeetingCommandArgument* arg;
	std::function<void* (int, MeetingCommandArgument*)> exeCmd;
	std::function<void(int, void*)> onCmdExe;
};

class FastCommandShell
{
public:
	
	static FastCommandShell& GetInstance()
	{
		FastCommandShell shell;
		return shell;
	}

	FastCommand* ReceiveCommand(int command, MeetingCommandArgument* arg)
	{
		FastCommand* fastCmd = new FastCommand;
		fastCmd->command = command;
		fastCmd->arg = arg;
		return fastCmd;
	}

private:
	FastCommandShell() : currentFastCommand(nullptr)
	{

	}

	virtual ~FastCommandShell()
	{
		if (currentFastCommand)
		{
			delete currentFastCommand;
			currentFastCommand = nullptr;
		}
	}

	FastCommand* currentFastCommand;
};