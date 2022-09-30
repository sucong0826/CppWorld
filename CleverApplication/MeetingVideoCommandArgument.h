#pragma once

#include "MeetingCommandArgument.h"

class MeetingVideoCommandArgument : public MeetingCommandArgument
{
public:
	MeetingVideoCommandArgument();
	virtual ~MeetingVideoCommandArgument();

	MeetingVideoCommandArgument(const MeetingVideoCommandArgument& arg)
	{
		videoFeatureType = arg.videoFeatureType;
	}

	int videoFeatureType = -1;
};