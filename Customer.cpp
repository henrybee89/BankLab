#include "Customer.h"

Customer::Customer(std::string firstName, std::string lastName) : _firstName(firstName), _lastName(lastName)
{
}

Customer::~Customer()
{
}

std::string Customer::GetName()
{
	return _lastName + ", " + _firstName;
}