#pragma once
#include <string>

class Customer
{
private:
	int _id;
	std::string _firstName;
	std::string _lastName;
public:
	Customer(std::string firstName, std::string lastName);
	~Customer();

	std::string GetName();
};