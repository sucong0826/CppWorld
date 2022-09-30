#pragma once

#include <functional>
#include <type_traits>
#include "FastCommandInput.h"

class FastCommand
{
protected:
	FastCommand()
		: command(-1)
		, needInput(false)
		, needOutput(false){}
	virtual ~FastCommand() {}

protected:
	int command;
	bool needInput;
	bool needOutput;
};

class FastCommandOnly : protected FastCommand
{
public:
	FastCommandOnly(int command)
		: mExeCmdOnly(nullptr)
		, mOnCmdExeOnly(nullptr)
	{
		this->command = command;
		this->needInput = false;
		this->needOutput = false;
	}

	virtual ~FastCommandOnly()
	{

	}

	FastCommandOnly* ExecuteCommand(std::function<void(int)> executeCommandLmd)
	{
		this->mExeCmdOnly = executeCommandLmd;
		return this;
	}

	FastCommandOnly* OnCommandExecuted(std::function<void(int)> onCommandExecutedLmd)
	{
		this->mOnCmdExeOnly = onCommandExecutedLmd;
		return this;
	}

	void Run()
	{
		mExeCmdOnly(command);
		mOnCmdExeOnly(command);
	}

private:
	std::function<void(int)> mExeCmdOnly;
	std::function<void(int)> mOnCmdExeOnly;
};

template<typename I, typename O>
class FastCommandWithInputOutput : protected FastCommand
{
public:
	FastCommandWithInputOutput(int command, I* input)
		: mExeCmd(nullptr)
		, mOnCmdExe(nullptr)
		, input(nullptr)
		, output(nullptr)
	{
		this->command = command;
		this->needInput = true;
		this->needOutput = true;
		this->input = input;
	}

	virtual ~FastCommandWithInputOutput()
	{
		mExeCmd = nullptr;
		mOnCmdExe = nullptr;
		input = nullptr;
		output = nullptr;
	}

	FastCommandWithInputOutput* ExecuteCommand(std::function<O*(int, I*)> executeCommandLmd)
	{
		this->mExeCmd = executeCommandLmd;
		return this;
	}

	FastCommandWithInputOutput* OnCommandExecuted(std::function<void(int, O*)> onCommandExecutedLmd)
	{
		this->mOnCmdExe = onCommandExecutedLmd;
		return this;
	}

	O* Run()
	{
		O* output = mExeCmd(command, input);
		mOnCmdExe(command, output);
		return output;
	}

private:
	I* input;
	O* output;
	std::function<O*(int, I*)> mExeCmd;
	std::function<void(int, O*)> mOnCmdExe;
};

template<typename I>
class FastCommandWithInputOnly : protected FastCommand
{
public:
	FastCommandWithInputOnly(int command, I* input)
		: mExeCmd(nullptr)
		, mOnCmdExe(nullptr)
		, input(nullptr)
	{
		this->command = command;
		this->needInput = true;
		this->needOutput = false;
		this->input = input;
	}

	virtual ~FastCommandWithInputOnly()
	{
		mExeCmd = nullptr;
		mOnCmdExe = nullptr;
		input = nullptr;
	}

	FastCommandWithInputOnly* ExecuteCommand(std::function<void(int, I*)> executeCommandLmd)
	{
		this->mExeCmd = executeCommandLmd;
		return this;
	}

	FastCommandWithInputOnly* OnCommandExecuted(std::function<void(int)> onCommandExecutedLmd)
	{
		this->mOnCmdExe = onCommandExecutedLmd;
		return this;
	}

	void Run()
	{
		mExeCmd(command, input);
		mOnCmdExe(command);
	}

private:
	std::function<void(int, I*)> mExeCmd;
	std::function<void(int)> mOnCmdExe;
	I* input;
};