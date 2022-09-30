#pragma once

template<typename I>
class FastCommandInput
{
public:
	FastCommandInput(int command, I input)
		: command(-1)
	{
		this->command = command;
		this->input = input;
	}

	FastCommandInput(int command)
	{
		this->command = command;
	}

	I GetInput() { return input; }
	void SetInput(I input) { this->input = input; }

	virtual ~FastCommandInput()
	{
	}

private:
	int command;
	I input;
};