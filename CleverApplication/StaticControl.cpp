#include "StaticControl.h"
#include <iostream>

using namespace std;

/* if wants to use static local variable, please remind of multi-thread issue. */
char StaticControl::oneChar(const char* charArray)
{
	static const char* s;
	if (charArray)
	{
		s = charArray;
		return *s;
	}
	else
	{
		// TODO
	}

	if (*s == '\0')
	{
		return 0;
	}

	return *s++;
}