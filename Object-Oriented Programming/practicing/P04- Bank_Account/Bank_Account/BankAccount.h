#pragma once
class BankAccount
{
public:
	BankAccount();
	~BankAccount();

	BankAccount(long long int x);
	void save(long long int x);
	void withdraw(long long int x);
	long long int getBalance();

	// track the total amount of BankAccounts have store.
	long long int static getAllMoneyInBank() { return allMoneyInBank; }

private:
	long long int balence;
	long long int static allMoneyInBank;
};

