#include "BankWrapper.h"
#include "Date.h"
#include <iostream>
/**
 * @file BankWrapper.cpp
 * @brief This file contains the implementations of various banking functions.
 */

using namespace std;

void welcome_screen() {
	try {

		int input;
		bool flag = true;
		int count = 0;
		Bank bank;
		while (flag) {
			cout << "\n---------------------------------- ASSIGNMENT 3 -----------------------------------------" << endl;

			cout << "Please Select an operation to perform in Bank" << endl;
			cout << "1) Add new Account" << endl;
			cout << "2) Deposit in Account" << endl;
			cout << "3) Withdraw from Account" << endl;
			cout << "4) Check Account" << endl;
			cout << "5) Exit Application" << endl;

			cout << "Your selection: ";
			cin >> input;

			switch (input) {
			case 1: bank = create_account(bank, count);
				count++;
				break;
			case 2: bank = deposit(bank);
				break;
			case 3: bank = withdraw(bank);
				break;
			case 4: check_acc(bank);
				break;
			case 5: flag = false;
				break;
			default: cout << "Invalid Selection. Select a vaild functionality." << endl;
				break;
			}
		}
	}
	catch (exception e) {
		cout << "Exception occured: " << e.what() << endl;
	}
}

Bank create_account(Bank bank, int count) {
	try {
		Customer customer;
		string string_input;
		int int_input;
		double double_input;
		int account_type;
		int account_number;
		cout << "Input Customer Information as asked then press enter." << endl;
		cout << "Name: ";
		cin >> string_input;
		customer.set_name(string_input);
		cin.ignore();
		cout << "Age: ";
		cin >> int_input;
		customer.set_age(int_input);
		cout << "Address: ";
		cin >> string_input;
		customer.set_address(string_input);
		cin.ignore();
		cout << "Telephone Number: ";
		cin >> string_input;
		customer.set_telephone_number(string_input);
		cout << "Select Customer Type: " << endl;
		cout << "0) Adult, 1) Student, 2) Senior" << endl;
		cin >> int_input;
		if (int_input > 2) {
			cout << "invalid Input";
			return bank;
		}
		customer.set_customer_type(int_input);

		cout << "Select Account Type: " << endl;
		cout << "0) Checking, 1) Savings" << endl;
		cin >> account_type;
		if (account_type > 1) {
			cout << "invalid Input";
			return bank;
		}

		cout << "Do you want to make an inital Deposit? (Y/N)" << endl;
		cin >> string_input;

		account_number = bank.create_account_number(count);
		customer.set_customer_number(bank.create_customer_number(count));

		if (string_input == "Y") {
			cout << "Please Enter Deposit Amount: $";
			cin >> double_input;
			bank.create_account(customer, account_number, account_type, double_input);
		}
		else {
			bank.create_account(customer, account_number, account_type);

		}
		cout << "Your account number is: '" << account_number << "'" << endl;
	}
	catch (exception e) {
		cout << "Exception occured: " << e.what() << endl;
	}
	return bank;
}

Bank deposit(Bank bank) {
	try {
		double amount;
		int account_num;

		cout << "Enter Account Number: ";
		cin >> account_num;

		cout << "Enter Amount to Deposit: ";
		cin >> amount;

		bank.make_deposit(account_num, amount);
	}
	catch (exception e) {
		cout << "Exception occured: " << e.what() << endl;
	}
	return bank;
}

Bank withdraw(Bank bank) {
	try {
		double amount;
		int account_num;

		cout << "Enter Account Number: ";
		cin >> account_num;

		cout << "Enter Amount Withdraw: ";
		cin >> amount;

		bank.make_withdrawal(account_num, amount);
	}
	catch (exception e) {
		cout << "Exception occured: " << e.what() << endl;
	}
	return bank;
}

void check_acc(Bank bank) {
	try {
		int account_num;
		cout << "Enter Account Number: ";
		cin >> account_num;

		Account account = bank.get_account(account_num);
		if (account.get_account_number() > 0) {
			display_account_info(account);
		}
	}
	catch (exception e) {
		cout << "Exception occured: " << e.what() << endl;
	}
}

void display_customer(Customer customer) {
	try {
		Constants constants;
		cout << "\nCustoemr Information: " << endl;
		cout << left << setw(20) << "Name: " << setw(20) << customer.get_name() << endl;
		cout << left << setw(20) << "Age: " << setw(20) << customer.get_age() << endl;
		cout << left << setw(20) << "Address: " << setw(20) << customer.get_address() << endl;
		cout << left << setw(20) << "Customer Number: " << setw(20) << customer.get_customer_number() << endl;
		cout << left << setw(20) << "Customer Type: " << setw(20) << constants.customer_type[customer.get_customer_type()] << endl;
	}
	catch (exception e) {
		cout << "Exception occured: " << e.what() << endl;
	}
}

void display_account_info(Account account) {
	try {
		Constants constants;
		display_customer(account.get_customer());

		cout << "\nAccount Information: " << endl;
		cout << left << setw(20) << "Accont No.: " << setw(20) << account.get_account_number() << endl;
		cout << left << setw(20) << "Account Type: " << setw(20) << constants.account_type[account.get_account_type()] << endl;
		cout << left << setw(20) << "Current Balance: $" << setw(20) << account.get_balance() << endl;
		cout << left << "\nTransactions: \n" << endl;

		display_transactions(account.get_transactions());
	}
	catch (exception e) {
		cout << "Exception occured: " << e.what() << endl;
	}
}

void display_transactions(vector <Transaction> transactions) {
	try {
		Constants constants;
		Date date;
		cout << left << setw(20) << "Date" << setw(20) << "Transaction Type" << setw(20) << "Amount" << setw(20) << "Balance" << setw(20) << "Comment" << endl;
		for (auto transaction : transactions) {
			date = transaction.get_date();
			cout << left << setw(20) << get_string_date(date) << setw(20) << constants.transaction_type[transaction.get_transaction_type()] << setw(20) << transaction.get_amount() << setw(20) << transaction.get_balance() << setw(20) << transaction.get_comment() << endl;
		}
	}
	catch (exception e) {
		cout << "Exception occured: " << e.what() << endl;
	}
}

string get_string_date(Date date) {
	return to_string(date.Day()) + "-" + to_string(date.Month()) + "-" + to_string(date.Year());
}