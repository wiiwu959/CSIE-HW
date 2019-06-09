#include <iostream>

using namespace std;

// two class caught when exception happened.
class NegativeDeposit
{
public:
	NegativeDeposit() {	}
};

class InsufficientFunds
{
public:
	InsufficientFunds() {	}
};

class Account
{
private:
	double balance;
public:

	Account()
	{
		balance = 0;
	}

	Account(double initialDeposit)
	{
		balance = initialDeposit;
	}

	double getBalance()
	{
		return balance;
	}

	//returns new balance or class NegativeDeposit object if error 
	double deposit(double amount)
	{
		if (amount > 0)
		{
			balance += amount;
		}
		else
		{
			throw NegativeDeposit();
		}
		return balance;
	}
	//return new balance or class InsufficientFunds object if invalid amount 
	double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0))
		{
			throw InsufficientFunds();
		}
		else
		{
			balance -= amount;
		}
		return balance;
	}
};


//Main
#include<iostream>
int main()
{
	Account a(100);
	try
	{
		cout << "Depositing 50" << endl;
		cout << "New balance: " << a.deposit(50) << endl;
		cout << "Withdraw 25" << endl;
		cout << "New balance: " << a.withdraw(25) << endl;
		cout << "Withdraw 250" << endl;
		cout << "New balance: " << a.withdraw(250) << endl;
	}
	catch (InsufficientFunds)
	{
		cout << "Not enough money to withdraw that amount." << endl;
	}
	catch (NegativeDeposit)
	{
		cout << "You may only deposit a positive amount." << endl;
	}
	cout << "Enter a character to exit" << endl;
	char wait;
	cin >> wait;
	return 0;
}