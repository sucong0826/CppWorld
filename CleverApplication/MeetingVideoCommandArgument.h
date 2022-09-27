#pragma once

#include "MeetingCommandArgument.h"

class MeetingVideoCommandArgument : public MeetingCommandArgument
{
public:
	MeetingVideoCommandArgument();
	virtual ~MeetingVideoCommandArgument();
	int videoFeatureType = -1;
};