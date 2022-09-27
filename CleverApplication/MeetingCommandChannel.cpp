#include "MeetingCommandChannel.h"
#include <vector>

MeetingCommandChannel::MeetingCommandChannel()
{

}

MeetingCommandChannel::~MeetingCommandChannel()
{

}

void MeetingCommandChannel::OnCommandExecuted(int command, void* payload)
{
	// once MeetingCommandChannel#OnCommandExecuted() is called, means you should pass the result to external parts,
	// for instance, you can transform the result to a protobuf message and send it to the controller, or you can
	// deliever the result to the application layer via JNI methods
	if (command == 1)
	{
		// std::vector<int>* pRandomNumbers = reinterpret_cast<std::vector<int>*>(payload);
		std::vector<int>* pRandomNumbers = (std::vector<int>*)payload;
		size_t size = pRandomNumbers->size();
	}
}

void MeetingCommandChannel::OnCommandReceived(int command, MeetingCommandArgument& arg)
{

}