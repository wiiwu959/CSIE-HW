/*****************************************************************
    CS4001301 Programming Languages                   
    
    Programming Assignment #1
    
    Java programming using subtype, subclass, and exception handling
    
    To compile: %> javac Application.java
    
    To execute: %> java Application

******************************************************************/

import java.util.*;
import java.text.ParseException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class Application {
	
    public static void main( String args []) throws ParseException{        
        Account[] accountList;
        accountList = new Account[4];
        
        // Using SimpleDateFormat Class parse date format
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd");
        Date openDate = dateFormat.parse("2019/07/29"), testDate;
        System.out.println("Four testing accounts are open at " + openDate + "\n");

        // buid 4 different accounts in the same array
        accountList[0] = new CheckingAccount("John Smith", 1500.0, openDate);
        accountList[1] = new SavingAccount("William Hurt", 1200.0, openDate);
        accountList[2] = new CDAccount("Woody Allison", 1000.0, openDate);
        accountList[3] = new LoanAccount("Judi Foster", -1500.0, openDate);

        // test Checking Account
        System.out.println("-----Test CheckingAccount.-----");
        testDate = openDate;
        System.out.println("Initial amount in Account :");
        try{
            double newBalance = accountList[0].computeInterest(testDate);
            System.out.println ("Account <" + accountList[0].name() + "> now has $" + newBalance + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[0].balance());
        }

        System.out.println("Withdraw $300 :");
        try{
            double ret = accountList[0].withdraw(300.00, testDate);
    	    System.out.println ("Account <" + accountList[0].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[0].balance());	
        }

        System.out.println("Withdraw $500 :");
        try{
            double ret = accountList[0].withdraw(500.00, testDate);
    	    System.out.println ("Account <" + accountList[0].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[0].balance());	
        }

        System.out.println("Deposit $1000 :");
        try{
            double ret = accountList[0].deposit(1000.00, testDate);
    	    System.out.println ("Account <" + accountList[0].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[0].balance());	
        }

        testDate = dateFormat.parse("2019/08/29");
        System.out.println("Interest after 1 month : ");
        try{
            double newBalance = accountList[0].computeInterest(testDate);
            System.out.println ("Account <" + accountList[0].name() + "> now has $" + newBalance + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[0].balance());	
        }

        // test SavingAccount
        System.out.println("-----Test SavingAccount.-----");
        testDate = openDate;
        System.out.println("Initial amount in Account :");
        try{
            double newBalance = accountList[1].computeInterest(testDate);
            System.out.println ("Account <" + accountList[1].name() + "> now has $" + newBalance + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[1].balance());
        }

        System.out.println("Withdraw $600 :");
        try{
            double ret = accountList[1].withdraw(600.00, testDate);
    	    System.out.println ("Account <" + accountList[1].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[1].balance());	
        }

        System.out.println("Withdraw $100 :");
        try{
            double ret = accountList[1].withdraw(100.00, testDate);
    	    System.out.println ("Account <" + accountList[1].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[1].balance());	
        }

        System.out.println("Deposit $1000 :");
        try{
            double ret = accountList[1].deposit(1000.00, testDate);
    	    System.out.println ("Account <" + accountList[1].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[1].balance());	
        }

        System.out.println("Withdraw $100 : (should fee for $1)");
        try{
            double ret = accountList[1].withdraw(100.00, testDate);
    	    System.out.println ("Account <" + accountList[1].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[1].balance());	
        }

        testDate = dateFormat.parse("2019/09/29");
        System.out.println("Interest after 2 months :");
        try{
            double newBalance = accountList[1].computeInterest(testDate);
            System.out.println ("Account <" + accountList[1].name() + "> now has $" + newBalance + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[1].balance());	
        }

        // test CDAccount
        System.out.println("-----Test CDAccount.-----");
        testDate = openDate;
        System.out.println("Initial amount in Account :");
        try{
            double newBalance = accountList[2].computeInterest(testDate);
            System.out.println ("Account <" + accountList[2].name() + "> now has $" + newBalance + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[2].balance());
        }

        System.out.println("Withdraw $600 :(fee for $250)");
        try{
            double ret = accountList[2].withdraw(600.00, testDate);
    	    System.out.println ("Account <" + accountList[2].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[2].balance());	
        }

        System.out.println("Deposit $1000 :(Not able)");
        try{
            double ret = accountList[2].deposit(1000.00, testDate);
    	    System.out.println ("Account <" + accountList[2].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[2].balance());	
        }

        testDate = dateFormat.parse("2020/08/29");
        System.out.println("Deposit $1000 :");
        try{
            double ret = accountList[2].deposit(1000.00, testDate);
    	    System.out.println ("Account <" + accountList[2].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[2].balance());	
        }

        System.out.println("Withdraw $600 :");
        try{
            double ret = accountList[2].withdraw(600.00, testDate);
    	    System.out.println ("Account <" + accountList[2].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[2].balance());	
        }

        System.out.println("Interest after 13 months :");
        try{
            double newBalance = accountList[2].computeInterest(testDate);
            System.out.println ("Account <" + accountList[2].name() + "> now has $" + newBalance + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[2].balance());	
        }


        // test LoanAccount
        System.out.println("-----Test LoanAccount.-----");
        testDate = openDate;
        System.out.println("Initial amount in Account :");
        try{
            double newBalance = accountList[3].computeInterest(testDate);
            System.out.println ("Account <" + accountList[3].name() + "> now has $" + newBalance + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[3].balance());
        }

        System.out.println("Withdraw $600 :(not able)");
        try{
            double ret = accountList[3].withdraw(600.00, testDate);
    	    System.out.println ("Account <" + accountList[3].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[3].balance());	
        }

        System.out.println("Deposit $1000 :");
        try{
            double ret = accountList[3].deposit(1000.00, testDate);
    	    System.out.println ("Account <" + accountList[3].name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[3].balance());	
        }

        testDate = dateFormat.parse("2019/08/29");
        System.out.println("Interest after 1 months :");
        try{
            double newBalance = accountList[3].computeInterest(testDate);
            System.out.println ("Account <" + accountList[3].name() + "> now has $" + newBalance + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, accountList[3].balance());	
        }

    }

    static void stdExceptionPrinting(Exception e, double balance) {
        System.out.println("EXCEPTION: Banking system throws a " + e.getClass() +
                        " with message: \n\t" +
                        "MESSAGE: " + e.getMessage());
        System.out.println("\tAccount balance remains $" + balance + "\n");
    }
}          
