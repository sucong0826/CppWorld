#pragma once
#include "TheSecondHeader.h"

class TheSecondHeader;

class TheFirstHeader
{
public:
	TheFirstHeader();
	virtual ~TheFirstHeader();

	TheSecondHeader* secondHeader;
};