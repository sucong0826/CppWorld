#pragma once
#include <string>

class Person
{
public:
	Person(std::string name, int age);
	~Person();
	Person(const Person& person);
	Person& operator=(const Person& person);

private:
	int age;
	std::string name;
};

