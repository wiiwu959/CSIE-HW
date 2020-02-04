/*****************************************************************
    CS4001301 Programming Languages                   
    
    Programming Assignment #1
    
    Java programming using subtype, subclass, and exception handling
    
    To compile: %> javac Application.java
    
    To execute: %> java Application

******************************************************************/

import java.util.*;

class BankingException extends Exception {
    BankingException () { super(); }
    BankingException (String s) { super(s); }
} 

interface BasicAccount {
    String name();
    double balance();	
}

interface WithdrawableAccount extends BasicAccount {
    double withdraw(double amount) throws BankingException;	
}

interface DepositableAccount extends BasicAccount {
    double deposit(double amount) throws BankingException;	
}

interface InterestableAccount extends BasicAccount {
    double computeInterest() throws BankingException;	
}

interface FullFunctionalAccount extends WithdrawableAccount,
                                        DepositableAccount,
                                        InterestableAccount {
}

public abstract class Account {
	
    // protected variables to store commom attributes for every bank accounts	
    protected String accountName;
    protected double accountBalance;
    protected double accountInterestRate;
    protected Date openDate;
    protected Date lastInterestDate;
    
    // public methods for every bank accounts
    public String name() {
    	return(accountName);	
    }	
    
    public double balance() {
        return(accountBalance);
    }
    
    public double deposit(double amount) throws BankingException{
        accountBalance += amount;
        return(accountBalance);
    } 

    public double deposit(double amount, Date depositDate) throws BankingException{
        accountBalance += amount;
        return(accountBalance);
    } 
    
    abstract double withdraw(double amount, Date withdrawDate) throws BankingException;
    
    public double withdraw(double amount) throws BankingException {
        Date withdrawDate = new Date();
        return(withdraw(amount, withdrawDate));
    }
    
    abstract double computeInterest(Date interestDate) throws BankingException;
    
    public double computeInterest() throws BankingException {
        Date interestDate = new Date();
        return(computeInterest(interestDate));
    }
}

/*
 *  Derived class: CheckingAccount
 *
 *  Description:
 *      Interest is computed daily; there's no fee for
 *      withdraw; there is a minimum balance of $1000.
 */
                          
class CheckingAccount extends Account implements FullFunctionalAccount {

    CheckingAccount(String s, double firstDeposit) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;	
    }
    
    CheckingAccount(String s, double firstDeposit, Date firstDate) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;	
    }	
    
    public double withdraw(double amount, Date withdrawDate) throws BankingException {
    // minimum balance is 1000, raise exception if violated
        if ((accountBalance  - amount) < 1000) {
            throw new BankingException ("Underfraft from checking account name:" +
                                         accountName);
        } else {
            accountBalance -= amount;	
            return(accountBalance); 	
        }                                        	
    }
    
    public double computeInterest (Date interestDate) throws BankingException {
        if (interestDate.before(lastInterestDate)) {
            throw new BankingException ("Invalid date to compute interest for account name" +
                                        accountName);                            	
        }
        
        int numberOfDays = (int) ((interestDate.getTime() 
                                   - lastInterestDate.getTime())
                                   / 86400000.0);
        System.out.println("Number of days since last interest is " + numberOfDays);
        double interestEarned = (double) numberOfDays / 365.0 *
                                      accountInterestRate * accountBalance;
        System.out.println("Interest earned is " + interestEarned); 
        lastInterestDate = interestDate;
        accountBalance += interestEarned;
        return(accountBalance);                            
    }  	
}

/*
 *  Derived class: SavingAccount
 *
 *  Description:
 *      Monthly interest; 
 *      fee of $1 for every transaction,
 *      except the first three per month are free;
 *      no minimum balance.
 */
                          
class SavingAccount extends Account implements InterestableAccount {

    int transactionTimes = 0;
    Date lastTransactionDate = null;

    SavingAccount(String s, double firstDeposit) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;	
    }
    
    SavingAccount(String s, double firstDeposit, Date firstDate) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;	
    }	
    
    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        if (amount > accountBalance){
            throw new BankingException ("No enough money.");
        }
        
        Calendar cal = Calendar.getInstance();
        cal.setTime(withdrawDate);
        int withdrawMonth = cal.get(Calendar.MONTH);
        int withdrawYear = cal.get(Calendar.YEAR);
        int lastTransactionMonth;
        int lastTransactionYear;
        if (lastTransactionDate == null){
            lastTransactionMonth = 0;
            lastTransactionYear = 0;
        }
        else{
            cal.setTime(lastTransactionDate);
            lastTransactionMonth = cal.get(Calendar.MONTH);
            lastTransactionYear = cal.get(Calendar.YEAR);
        }
        
        if (withdrawMonth == lastTransactionMonth && withdrawYear == lastTransactionYear){
            transactionTimes++;
        }
        else{
            transactionTimes = 1;
        }
        lastTransactionDate = withdrawDate;
        
        if (transactionTimes > 3){
            accountBalance -= 1;
        }
        return accountBalance -= amount;
    }

    public double deposit(double amount, Date depositDate) throws BankingException{
        
        Calendar cal = Calendar.getInstance();
        cal.setTime(depositDate);
        int depositMonth = cal.get(Calendar.MONTH);
        int depositYear = cal.get(Calendar.YEAR);
        int lastTransactionMonth;
        int lastTransactionYear;
        if (lastTransactionDate == null){
            lastTransactionMonth = 0;
            lastTransactionYear = 0;
        }
        else{
            cal.setTime(lastTransactionDate);
            lastTransactionMonth = cal.get(Calendar.MONTH);
            lastTransactionYear = cal.get(Calendar.YEAR);
        }

        if (depositMonth == lastTransactionMonth && depositYear == lastTransactionYear){
            transactionTimes++;
        }
        else{
            transactionTimes = 1;
        }
        lastTransactionDate = depositDate;

        if (transactionTimes > 3){
            accountBalance -= 1;
        }
        return accountBalance += amount;
    }
    
    public double computeInterest (Date interestDate) throws BankingException {
        if (interestDate.before(lastInterestDate)) {
            throw new BankingException ("Invalid date to compute interest for account name" +
                                        accountName);                            	
        }

        int numberOfMonths = (int) ((interestDate.getTime() 
                                   - lastInterestDate.getTime())
                                   / (30 * 86400000.0));
        System.out.println("Number of months since last interest is " + numberOfMonths);
        double interestEarned = (double) numberOfMonths / 12.0 *
                                      accountInterestRate * accountBalance;
        System.out.println("Interest earned is " + interestEarned); 
        lastInterestDate = interestDate;
        accountBalance += interestEarned;
        return(accountBalance);                            
    }  	
}


/*
 *  Derived class: CDAccount
 *
 *  Description:
 *      Monthly interest; 
 *      fixed amount and duration 
 *      (e.g., you can open 1 12-month CD for $5000; 
 *      for the next 12 months you can't deposit 
 *      anything and withdrawals cost a  $250 fee);
 *      at the end of the duration the interest 
 *      payments stop and you can withdraw w/o fee.
 */
                          
class CDAccount extends Account implements WithdrawableAccount {

    int duration;

    CDAccount(String s, double firstDeposit) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;
        duration = 12;	
    }
    
    CDAccount(String s, double firstDeposit, int durationMonth) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;
        duration = durationMonth;	
    }

    CDAccount(String s, double firstDeposit, Date firstDate) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;
        duration = 12;
    }	
    
    CDAccount(String s, double firstDeposit, Date firstDate, int durationMonth) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;
        duration = durationMonth;
    }	
    
    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        if (amount > accountBalance){
            throw new BankingException ("No enough money to withdraw for " + accountName);
        }
        
        Calendar cal = Calendar.getInstance();
        cal.setTime(withdrawDate);
        int withdrawMonth = cal.get(Calendar.MONTH);
        int withdrawYear = cal.get(Calendar.YEAR);
        cal.setTime(openDate);
        int openMonth = cal.get(Calendar.MONTH);
        int openYear = cal.get(Calendar.YEAR);

        if ((withdrawMonth - openMonth) + (withdrawYear - openYear) * 12 < duration){
            if (amount + 250 > accountBalance){
                throw new BankingException ("No enough money to withdraw for " + accountName);
            }
            else{
                accountBalance -= (amount + 250);
            }
        }
        else{
            if (amount > accountBalance){
                throw new BankingException ("No enough money to withdraw for " + accountName);
            }
            else{
                accountBalance -= amount;
            }
        }
        
        return accountBalance;
    }

    public double deposit(double amount, Date depositDate) throws BankingException{

        Calendar cal = Calendar.getInstance();
        cal.setTime(depositDate);
        int depositMonth = cal.get(Calendar.MONTH);
        int depositYear = cal.get(Calendar.YEAR);
        cal.setTime(openDate);
        int openMonth = cal.get(Calendar.MONTH);
        int openYear = cal.get(Calendar.YEAR);

        if ((depositMonth - openMonth) + (depositYear - openYear) * 12 < duration){
            throw new BankingException ("Invalid date to deposit for " + accountName);
        }
        else{
            accountBalance += amount;
            return accountBalance;
        }
    }
    
    public double computeInterest (Date interestDate) throws BankingException {
        if (interestDate.before(lastInterestDate)) {
            throw new BankingException ("Invalid date to compute interest for account name" +
                                        accountName);                            	
        }

        int numberOfMonths = (int) ((interestDate.getTime() 
                                   - lastInterestDate.getTime())
                                   / (30 * 86400000.0));
        System.out.println("Number of months since last interest is " + numberOfMonths);
        double interestEarned = (double) numberOfMonths / 12.0 *
                                      accountInterestRate * accountBalance;
        System.out.println("Interest earned is " + interestEarned); 
        lastInterestDate = interestDate;
        accountBalance += interestEarned;
        return(accountBalance);                            
    }  	
}


/*
 *  Derived class: LoanAccount
 *
 *  Description:
 *      like a saving account, but the balance is "negative" 
 *      (you owe the bank money, so a deposit will reduce the amount of the loan);
 *      you can't withdraw (i.e., loan more money) 
 *      but of course you can deposit (i.e., pay off part of the loan).
 */
class LoanAccount extends Account implements DepositableAccount {
    LoanAccount (String s, double firstDeposit) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;    
    }

    LoanAccount (String s, double firstDeposit, Date firstDate) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;    
    }

    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        throw new BankingException ("It's invalid to withdraw for account name" + accountName);
    }

    public double deposit(double amount) throws BankingException{
        accountBalance += amount;
        return(accountBalance);
    } 

    public double computeInterest (Date interestDate) throws BankingException {
        if (interestDate.before(lastInterestDate)) {
            throw new BankingException ("Invalid date to compute interest for account name" +
                                        accountName);                               
        }

        int numberOfMonths = (int) ((interestDate.getTime() 
                                   - lastInterestDate.getTime())
                                   / (30 * 86400000.0));
        System.out.println("Number of days since last interest is " + numberOfMonths);
        double interestEarned = (double) numberOfMonths / 12.0 *
                                      accountInterestRate * accountBalance;
        System.out.println("Interest earned is " + interestEarned); 
        lastInterestDate = interestDate;
        accountBalance += interestEarned;
        return(accountBalance);                            
    }

}