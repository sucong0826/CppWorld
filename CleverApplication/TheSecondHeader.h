#pragma once

#include "TheFirstHeader.h"

class TheFirstHeader;

class TheSecondHeader
{
public:
	TheSecondHeader();
	virtual ~TheSecondHeader();

	TheFirstHeader* firstHeader;
};