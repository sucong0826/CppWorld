#pragma once
#include <string>

class Person
{
public:
	Person(std::string name, int age);
	~Person();
	Person(const Person& person);
	Person& operator=(const Person& person);
	int getAge() const { return age; }

private:
	int age;
	std::string name;
};

