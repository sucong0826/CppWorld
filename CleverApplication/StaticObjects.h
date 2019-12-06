#pragma once
#include <iostream>

using namespace std;

class StaticObjects
{
	int i;
public:
	StaticObjects(int ii = 0) : i(ii) {}
	~StaticObjects() { cout << "StaticObjects::~StaticObjects()" << endl; }

	void printProperites() const;
};

