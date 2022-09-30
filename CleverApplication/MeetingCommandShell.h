#pragma once

#include "IMeetingCommandChannel.h"
#include "IMeetingCommandDispatcher.h"
#include "IMeetingCommandExecutor.h"
#include "IMeetingCommandReceiver.h"
#include <functional>
#include <type_traits>

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

//template<typename I, typename O>
//class FastCommand
//{
//public:
//	template<typename O>
//	class FastCommandOutput
//	{
//	public:
//		FastCommandOutput(int command)
//		{
//			this->command = command;
//		}
//
//		virtual ~FastCommandOutput()
//		{
//
//		}
//
//		int command;
//		O output;
//	};
//
//	static FastCommand<I, O>* NewFastCommand(int command)
//	{
//		return new FastCommand<I, O>(command);
//	}
//
//	FastCommand(int command)
//		: needInput(false)
//		, needOutput(false)
//		, command(-1)
//		, input(nullptr)
//		, exeCmdWithInputOutput(nullptr)
//		, exeCmdWithInputOnly(nullptr)
//		, exeCmdWithOutputOnly(nullptr)
//		, exeCmdOnly(nullptr)
//		, onCmdExecuted(nullptr)
//		, onCmdExecutedWithOutput(nullptr)
//	{
//		this->needInput = std::is_void<I>::value;
//		this->needOutput = std::is_void<O>::value;
//		this->command = command;
//		input = new FastCommandInput<I>(command);
//	}
//
//	virtual ~FastCommand()
//	{
//		if (input)
//		{
//			delete input;
//			input = nullptr;
//		}
//	}
//
//	FastCommand* SetArgument(I arg)
//	{
//		if (needInput && input)
//		{
//			input->arg = arg;
//		}
//
//		return this;
//	}
//
//	FastCommand<I, O>* ExecuteCommand(std::function<O(int, I)> executeCommandLmd)
//	{
//		this->exeCmdWithInputOutput = executeCommandLmd;
//		return this;
//	}
//
//	FastCommand* ExecuteCommand(std::function<O(int)> executeCommandLmd)
//	{
//		this->exeCmdWithOutputOnly = executeCommandLmd;
//		return this;
//	}
//
//	FastCommand* ExecuteCommand(std::function<void(int, I)> executeCommandLmd)
//	{
//		this->exeCmdWithInputOnly = executeCommandLmd;
//		return this;
//	}
//
//	FastCommand* ExecuteCommand(std::function<void(int)> executeCommandLmd)
//	{
//		this->exeCmdOnly = executeCommandLmd;
//		return this;
//	}
//
//	FastCommand* OnCommandExecuted(std::function<void(int)> onCommandExecutedLmd)
//	{
//		this->onCmdExecuted = onCommandExecutedLmd;
//		return this;
//	}
//
//	FastCommand* OnCommandExecuted(std::function<void(int, O)> onCommandExecutedLmd)
//	{
//		this->onCmdExecutedWithOutput = onCommandExecutedLmd;
//		return this;
//	}
//
//	void Run()
//	{
//		if (needInput)
//		{
//			std::function<void(int, I)> exeCmd = this->exeCmdWithInputOutput;
//			std::function<void(int)> onCmdExecuted = this->onCmdExecuted;
//			if (input)
//			{
//				exeCmd(input->command, input->arg);
//				onCmdExecuted(input->command);
//			}
//		}
//		else
//		{
//			std::function<void(int)> exeCmd = this->exeCmdOnly;
//			std::function<void(int)> onCmdExecuted = this->onCmdExecuted;
//
//			exeCmd(input->command);
//			onCmdExecuted(input->command);
//		}
//	}
//
//	FastCommandOutput<O> RunWithResult()
//	{
//		FastCommandOutput<O> result(input->command);
//		if (needInput)
//		{
//			std::function<O(int, I)> exeCmd = this->exeCmdWithInputOutput;
//			std::function<void(int, O)> onCmdExecuted = this->onCmdExecutedWithOutput;
//			if (input)
//			{
//				O output = exeCmd(input->command, input->arg);
//				onCmdExecuted(input->command, output);
//				result.output = output;
//			}
//		}
//		else
//		{
//			std::function<O(int)> exeCmd = this->exeCmdWithOutputOnly;
//			std::function<void(int, O)> onCmdExecuted = this->onCmdExecutedWithOutput;
//			O output = exeCmd(input->command);
//			onCmdExecuted(input->command, output);
//			result.output = output;
//		}
//
//		return result;
//	}
//
//private:
//	template<typename I>
//	class FastCommandInput
//	{
//	public:
//		FastCommandInput(int command)
//		{
//			this->command = command;
//		}
//
//		virtual ~FastCommandInput()
//		{
//
//		}
//
//		int command;
//		I arg;
//	};
//
//private:
//	bool needInput;
//	bool needOutput;
//	int command;
//	FastCommandInput<I>* input = nullptr;
//
//	std::function<O(int, I)> exeCmdWithInputOutput;
//	std::function<O(int)> exeCmdWithOutputOnly;
//	std::function<void(int, I)> exeCmdWithInputOnly;
//	std::function<void(int)> exeCmdOnly;
//	std::function<void(int)> onCmdExecuted;
//	std::function<void(int, O)> onCmdExecutedWithOutput;
//};
//
//class FastCommandOnly
//{
//
//};
//
//class FastCommandShell
//{
//public:
//	static FastCommandShell& GetInstance()
//	{
//		FastCommandShell shell;
//		return shell;
//	}
//
//	template<typename I, typename O>
//	FastCommand<I, O>* ObtainFastCommand(int command)
//	{
//
//	}
//
//private:
//	FastCommandShell()
//	{
//	}
//};