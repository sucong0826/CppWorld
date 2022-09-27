#include "MeetingCommandShell.h"
#include "MeetingCommandExecutor.h"
#include "MeetingCommandDispatcher.h"
#include "MeetingCommandChannel.h"
#include "MeetingCommandReceiver.h"

MeetingCommandShell::MeetingCommandShell() 
	: mCommandDispatcher(nullptr)
	, mCommandChannel(nullptr)
	, mCommandReceiver(nullptr)
	, mCommandExecutor(nullptr)
{
	
	mCommandChannel = new MeetingCommandChannel;
	mCommandDispatcher = new MeetingCommandDispatcher(mCommandChannel);
	mCommandExecutor = new MeetingCommandExecutor(mCommandDispatcher);
	mCommandReceiver = new MeetingCommandReceiver(mCommandExecutor);
}

MeetingCommandShell::~MeetingCommandShell()
{
	if (mCommandDispatcher)
	{
		delete mCommandDispatcher;
		mCommandDispatcher = nullptr;
	}

	if (mCommandChannel)
	{
		delete mCommandChannel;
		mCommandChannel = nullptr;
	}

	if (mCommandReceiver)
	{
		delete mCommandReceiver;
		mCommandReceiver = nullptr;
	}

	if (mCommandExecutor)
	{
		delete mCommandExecutor;
		mCommandExecutor = nullptr;
	}
}

void MeetingCommandShell::OnCommandExecuted(int command, void* payload)
{
	if (mCommandChannel) 
	{
		mCommandChannel->OnCommandExecuted(command, payload);
	}
}

void MeetingCommandShell::OnCommandReceived(int command, MeetingCommandArgument& arg)
{
	if (mCommandChannel)
	{
		mCommandChannel->OnCommandReceived(command, arg);
	}
}

void MeetingCommandShell::ExecuteCommand(int command, MeetingCommandArgument& arg)
{
	if (mCommandExecutor)
	{
		mCommandExecutor->ExecuteCommand(command, arg);
	}
}

void MeetingCommandShell::DispatchCommandResult(int command, void* payload)
{
	if (mCommandDispatcher)
	{
		mCommandDispatcher->DispatchCommandResult(command, payload);
	}
}

void MeetingCommandShell::ReceiveCommand(int command, MeetingCommandArgument& arg)
{
	if (mCommandReceiver)
	{
		mCommandReceiver->ReceiveCommand(command, arg);
	}
}
