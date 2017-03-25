#pragma once
#include "Customer.h"
#include <queue>

class Account
{
	int _accountNumber;
	int _balance = 0;
	Customer _accountOwner;
	std::queue<std::string> *_transactionLog = new std::queue<std::string>();
public:
	Account(int accountNumber, Customer accountOwner);
	~Account();

	std::string GetAccountInfo();
	bool Deposit(int pennies);
	bool Withdraw(int pennies);
	int GetBalanceInPennies();
	std::string ShowTransactionLog();
};
