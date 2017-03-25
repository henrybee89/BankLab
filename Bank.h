#pragma once
#include <vector>
#include "Account.h"
class Bank
{
private:
	std::string _name;
	std::vector<Account> _accounts;
public:
	Bank(std::string name);
	~Bank();

	std::string GetName();
	std::vector<Account> GetAccounts();
	bool OpenAccount(Account account, int startingPennies);
};