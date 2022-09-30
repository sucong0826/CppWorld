#pragma once

#include "FastCommand.h"

class FastCommandShell
{
public:
	virtual ~FastCommandShell()
	{
	}

	static FastCommandOnly* NewFastCommand(int command)
	{
		/*bool noInput = std::is_void<I>::value;
		bool noOutput = std::is_void<O>::value;*/

		FastCommandOnly* fastCommandOnly = new FastCommandOnly(command);
		return fastCommandOnly;
	}

	template<typename I>
	static FastCommandWithInputOnly<I>* NewFastCommand(int command, I* input)
	{
		FastCommandWithInputOnly<I>* fastCommand = new FastCommandWithInputOnly<I>(command, input);
		return fastCommand;
	}

	template<typename I, typename O>
	static FastCommandWithInputOutput<I, O>* NewFastCommandInputOutput(int command, I* input)
	{
		/*FastCommandWithInputOutput<I, O>* fastCommand = new FastCommandWithInputOutput<I, O>(command, input);
		return fastCommand;*/
		return nullptr;
	}

private:
	FastCommandShell()
	{
	}
};