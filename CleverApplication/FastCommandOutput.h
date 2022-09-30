#pragma once

template<typename O>
class FastCommandOutput
{
public:
	FastCommandOutput(int command)
		: command(-1)
	{
		this->command = command;
	}

	virtual ~FastCommandOutput()
	{
	}

	O GetOutput() { return output; }
	void SetOutput(O output) { this->output = output; }

private:
	int command;
	O output;
};