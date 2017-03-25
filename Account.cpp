#include "Account.h"

Account::Account(int accountNumber, Customer accountOwner) : _accountNumber(accountNumber), _accountOwner(accountOwner)
{

}

Account::~Account()
{
}

std::string Account::GetAccountInfo()
{
	return _accountOwner.GetName();
}

bool Account::Deposit(int pennies)
{
	if (pennies > 0)
	{
		_transactionLog->push(_accountOwner.GetName() + " deposited $" + std::to_string(pennies / 100));
		_balance += pennies;
		return true;
	}
	return false;
}

bool Account::Withdraw(int pennies)
{
	if (pennies > 0) {
		_balance -= pennies;
		_transactionLog->push(_accountOwner.GetName() + " withdrew $" + std::to_string(pennies / 100));
		return true;
	}
	return false;
}

int Account::GetBalanceInPennies()
{
	return _balance;
}

std::string Account::ShowTransactionLog()
{
	std::string output = "Transaction Log \n";
	while (!_transactionLog->empty()) {
		output += _transactionLog->front() + "\n";
		_transactionLog->pop();
	}
	return output;
}