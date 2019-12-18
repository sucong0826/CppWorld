#include "Person.h"
#include <iostream>

Person::Person(std::string name, int age) 
	: name(name)
	, age(age)
{
	std::cout << "Person class constructor() called. and addr=" << this << std::endl;
}

Person::~Person()
{
	std::cout << "Person class deconstructor() called. and addr=" << this << std::endl;
}

Person::Person(const Person& person)
{
	this->age = person.age;
	this->name = person.name;
	std::cout << "Person class copy constructor() called. and addr=" << this << std::endl;
}

Person& Person::operator=(const Person& person)
{
	std::cout << "Person class copy operator() called." << std::endl;
	this->age = person.age;
	this->name = person.name;
	return *this;
}