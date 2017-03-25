#include <iostream>
#include "Bank.h"
using namespace std;

void CreateAccountSubsystem();
void ViewAccountsSubsystem();
void DeleteAccountSubsystem();
void ShowTransactionLog();
void Transact();

Bank bank = Bank("Awesome Bank");
int main()
{
	//Create the bank
	auto choice = 0;
	do
	{
		system("cls");
		cout << "Welcome to " << bank.GetName() << endl;
		cout << "1) Create Account" << endl;
		cout << "2) View Accounts" << endl;
		cout << "3) Delete Account" << endl;
		cout << "4) Transact" << endl;
		cout << "5) Show Transaction Log" << endl;
		cout << "6) Exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: CreateAccountSubsystem(); break;
		case 2: ViewAccountsSubsystem(); break;
		case 3: DeleteAccountSubsystem(); break;
		case 4: Transact(); break;
		case 5: ShowTransactionLog(); break;
		default: break;
		}
	} while (choice != 6);

	system("pause");
	return 0;
}

void Transact() {
	system("cls");
	cout << "Which customer?" << endl;
	int i = 0;
	for (auto account : bank.GetAccounts()) {
		i++;
		cout << i << ") " << account.GetAccountInfo() << endl;
	}
	int choice = 0;
	cin >> choice;

	auto account = bank.GetAccounts()[choice - 1];
	system("cls");

	cout << "1) Deposit" << endl;
	cout << "2) Withdraw" << endl;
	int typeChoice;
	cin >> typeChoice;

	cout << "How Many Pennies? ";
	int pennies;
	cin >> pennies;

	if (typeChoice == 1) {
		account.Deposit(pennies);
	}
	else if (typeChoice == 2) {
		account.Withdraw(pennies);
	}
	else {
		//Bad input
	}

	system("pause");
}

void ShowTransactionLog() {
	system("cls");
	cout << "Which customer?" << endl;
	int i = 0;
	for (auto account : bank.GetAccounts()) {
		i++;
		cout << i << ") " << account.GetAccountInfo() << endl;
	}
	int choice = 0;
	cin >> choice;

	auto account = bank.GetAccounts()[choice - 1];
	system("cls");
	cout << account.ShowTransactionLog() << endl;
	system("pause");
}

void CreateAccountSubsystem()
{
	system("cls");
	string firstName, lastName;
	cout << "Customer FirstName: ";
	cin >> firstName;
	cout << endl << "Customer LastName: ";
	cin >> lastName;
	auto customer = Customer(firstName, lastName);

	int accountNumber;
	cout << endl << "Account Number: ";
	cin >> accountNumber;

	auto account = Account(accountNumber, customer);
	bank.OpenAccount(account, 0);
}

void ViewAccountsSubsystem()
{
	system("cls");
	auto accounts = bank.GetAccounts();
	for (auto account : accounts)
	{
		cout << account.GetAccountInfo() << endl;
	}
	system("pause");
}

void DeleteAccountSubsystem()
{
	return;
}