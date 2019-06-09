#include "BankAccount.h"

// initialize the static varieble.
long long int BankAccount::allMoneyInBank = 0;

// default constructor that set balance with initial 0.
BankAccount::BankAccount()
{
	balence = 0;
	allMoneyInBank += 0;
}


BankAccount::~BankAccount()
{
}

// that set the balance with initial value x.
BankAccount::BankAccount(long long int x)
{
	balence = x;
	allMoneyInBank += x;
}

// save money in the bank with an amount by the argument.
void BankAccount::save(long long int x)
{
	balence += x;
	allMoneyInBank += x;
}

// withdraw money in the bank with an amount by the argument.
void BankAccount::withdraw(long long int x)
{
	balence -= x;
	allMoneyInBank -= x;
}

// a const inspector functions to retrieve the current balance of the bank.
long long int BankAccount::getBalance()
{
	return balence;
}

