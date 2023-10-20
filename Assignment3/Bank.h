#pragma once
#ifndef H__BANK_H
#define H__BANK_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Date.h"

using namespace std;

// the usual method of constant declaration didnt worked with maps (dictionary in cpp) hence used a normal class for constants.
class Constants {

public:

	string AccountNumberPrefix = "2004";
	string CustomerNumberPrefix = "1002";
	map<int, string> customer_type = {
			{0 , "Adult"},
			{1, "Student"},
			{2, "Senior"}
	};
	map<int, string> account_type = {
		{0 , "Checking"},
		{1, "Savings"}
	};
	map<int, string> transaction_type = {
		{0, "DEP"},
		{1, "WD"},
		{2, "INT CR"},
		{3, "CHK CHRG"},
		{4, "OVRDFT PNLTY"},
		{5, "INVLD TRANSACTION"}
	};
};

/*
* @brief class of customer for Bank.
*/
class Customer {
public:

	Customer create_customer(string name, string address, int age, string telephone_number, int customer_num, int customer_type) {
		Customer customer;
		customer.name = name;
		customer.address = address;
		customer.age = age;
		customer.telephone_number = telephone_number;
		customer.customer_number = customer_num;
		customer.customer_type;

		return customer;
	}

	// Accessors and modifiers 

	string get_name() {
		return name;
	}

	string get_address() {
		return address;
	}

	int get_age() {
		return age;
	}

	string get_telephone_number() {
		return telephone_number;
	}

	int get_customer_number() {
		return customer_number;
	}

	int get_customer_type() {
		return customer_type;
	}

	void set_name(string name) {
		this->name = name;
	}

	void set_address(string address) {
		this->address = address;
	}

	void set_age(int age) {
		this->age = age;
	}

	void set_telephone_number(string telephone_number) {
		this->telephone_number = telephone_number;
	}

	void set_customer_number(int customer_number) {
		this->customer_number = customer_number;
	}

	void set_customer_type(int customer_type) {
		this->customer_type = customer_type;
	}

private:
	string name;
	string address;
	int age;
	string telephone_number;
	int customer_number;
	int customer_type;
};

class Senior : public Customer {
public:
	static const double SAVINGS_INTEREST;
	static const double CHECK_INTEREST;
	static const double CHECK_CHARGE;
	static const int OVERDRAFT_PENALTY;
};

class Adult : public Customer {
public:
	static const double SAVINGS_INTEREST;
	static const double CHECK_INTEREST;
	static const double CHECK_CHARGE;
	static const int OVERDRAFT_PENALTY;
};

class Student : public Customer {
public:
	static const double SAVINGS_INTEREST;
	static const double CHECK_INTEREST;
	static const double CHECK_CHARGE;
	static const int OVERDRAFT_PENALTY;
};

/*
* @breif class of Transaction for Bank
*/
class Transaction {
public:
	Transaction create_transaction(int transaction_type, double balance, double amount, string date = "-", string comments = "-") {
		Transaction transaction;
		Date new_date;
		transaction.transaction_type = transaction_type;
		transaction.balance = balance;
		transaction.amount = amount;
		transaction.date = date == "-" ? new_date.getCurrentDate() : new_date.convertToDate(date);
		transaction.comments = comments;

		return transaction;
	}
	int get_transaction_type() {
		return transaction_type;
	}

	double get_amount() {
		return amount;
	}

	double get_balance() {
		return balance;
	}

	Date get_date() {
		return date;
	}

	string get_comment() {
		return comments;
	}

	int set_transaction_type(int transaction_type) {
		this->transaction_type = transaction_type;
	}

	double set_amount(double amount) {
		this->amount = amount;
	}

	double set_balance(double balance) {
		this->balance = balance;
	}

	Date set_date(string date) {
		Date newDate;
		this->date = newDate.convertToDate(date);
	}

private:
	int transaction_type;
	double amount;
	double balance;
	Date date;
	string comments;
};

/*
* @breif Account class for Bank operations
*/
class Account {
public:

	Account create_account(Customer customer, int account_num, int account_type, double balance = 0) {
		Account account;
		account.customer = customer;
		account.balance = balance;
		account.account_number = account_num;
		account.account_type = account_type;
		return account;
	}

	// Accessors and Modifiers

	int get_account_number() {
		return account_number;
	}

	double get_balance() {
		return balance;
	}

	int get_account_type() {
		return account_type;
	}

	Customer get_customer() {
		return customer;
	}

	vector<Transaction> get_transactions() {
		return transactions;
	}

	void set_customer(Customer customer) {
		this->customer = customer;
	}

	void set_balance(double balance) {
		this->balance = balance;
	}

	void set_account_type(int account_type) {
		this->account_type = account_type;
	}

	void set_account_number(int account_num) {
		this->account_number = account_num;
	}

	void add_transaction(Transaction transaction) {
		transactions.push_back(transaction);
	}

	void set_transactions(vector<Transaction> transactions) {
		this->transactions = transactions;
	}

private:
	Customer customer;
	double balance;
	int account_number;
	int account_type;
	Date date;
	vector<Transaction> transactions;
};

/*
* @breif Savings Account class for Bank operations
*/
class Savings_Account : public Account {
public:
	void deposit(double amount, string date) {
		Transaction transaction;

		this->set_balance(this->get_balance() + amount);
		this->add_transaction(transaction.create_transaction(0, this->get_balance(), amount, date));
		this->add_interest();
		cout << "Amount $" << amount << "added to account '" << this->get_account_number() << "'" << endl;
		cout << "Your current balance is now: $" << this->get_balance() << endl;
	}

	void withdraw(double amount, string date) {
		Transaction transaction;
		Constants constants;
		int overdraft_penealty;
		double check_charge;
		string customer_type = constants.customer_type[this->get_customer().get_customer_type()];

		if (customer_type == constants.customer_type[0]) {
			overdraft_penealty = Adult::OVERDRAFT_PENALTY;
			check_charge = Adult::CHECK_CHARGE;
		}
		else if (customer_type == constants.customer_type[1]) {
			overdraft_penealty = Student::OVERDRAFT_PENALTY;
			check_charge = Student::CHECK_CHARGE;
		}
		else if (customer_type == constants.customer_type[2]) {
			overdraft_penealty = Senior::OVERDRAFT_PENALTY;
			check_charge = Senior::CHECK_CHARGE;
		}

		if (this->get_balance() > amount) {
			this->set_balance(this->get_balance() - amount);
			this->add_transaction(transaction.create_transaction(1, this->get_balance(), amount, date));
			cout << "As you are withdrawing from Savings account a check charge of $" << check_charge << " will be imposed." << endl;
			this->set_balance(this->get_balance() - check_charge);
			this->add_transaction(transaction.create_transaction(3, this->get_balance(), check_charge, date));
			cout << "Withdrawal successfull! Your new balance is: $" << this->get_balance() << endl;
		}
		else {
			if (this->get_balance() <= 5) {
				cout << "Minimum Balance in Account must be $5, an overdraft penalty will be imposed of $" << overdraft_penealty << endl;
				this->set_balance(this->get_balance() - overdraft_penealty);
				this->add_transaction(transaction.create_transaction(4, this->get_balance(), amount, date, "overdraft penalty"));
			}
			else {
				string comment = "Insuffcient balance!";
				this->add_transaction(transaction.create_transaction(5, this->get_balance(), amount, date, comment));
				cout << comment << endl;
			}
		}
	}

	void add_interest() {
		Constants constants;
		Transaction transaction;
		string customer_type = constants.customer_type[this->get_customer().get_customer_type()];
		double intrest = 0;
		if (customer_type == constants.customer_type[0]) {
			intrest = Adult::SAVINGS_INTEREST;
			this->set_balance(this->get_balance() + intrest);
		}
		else if (customer_type == constants.customer_type[1]) {
			intrest = Student::SAVINGS_INTEREST;
			this->set_balance(this->get_balance() + intrest);
		}
		else if (customer_type == constants.customer_type[2]) {
			intrest = Senior::SAVINGS_INTEREST;
			this->set_balance(this->get_balance() + intrest);
		}
		this->add_transaction(transaction.create_transaction(2, this->get_balance(), intrest));
	};
};

/*
* @breif Checking Account class for Bank operations
*/
class Checking_Account : public Account {
public:
	void deposit(double amount, string date) {
		Transaction transaction;
		if (amount <= 0) {
			cout << "Deposit of 0 or less than zero is not allowed pls try again with a vaild deposit." << endl;
			return;
		}
		this->set_balance(this->get_balance() + amount);
		this->add_transaction(transaction.create_transaction(0, this->get_balance(), amount, date));
		this->add_interest();
		cout << "Amount $" << amount << " added to account '" << this->get_account_number() << "'" << endl;
		cout << "Your current balance is now: $" << this->get_balance() << endl;
	}

	void withdraw(double amount, string date) {
		Transaction transaction;
		Constants constants;
		int overdraft_penealty;
		string customer_type = constants.customer_type[this->get_customer().get_customer_type()];
		if (amount <= 0) {
			cout << "Withdrawal of 0 or less than zero is not allowed pls try again with a vaild deposit." << endl;
			return;
		}
		if (customer_type == constants.customer_type[0]) {
			overdraft_penealty = Adult::OVERDRAFT_PENALTY;
		}
		else if (customer_type == constants.customer_type[1]) {
			overdraft_penealty = Student::OVERDRAFT_PENALTY;
		}
		else if (customer_type == constants.customer_type[2]) {
			overdraft_penealty = Senior::OVERDRAFT_PENALTY;
		}

		if (this->get_balance() > amount) {
			this->set_balance(this->get_balance() - amount);
			this->add_transaction(transaction.create_transaction(1, this->get_balance(), amount, date));
			cout << "Withdrawl successful! Your new balance is: $" << this->get_balance() << endl;
		}
		else {
			string comment;
			if (this->get_balance() <= 5) {
				comment = "overdraft penalty";
				cout << "Minimum Balance in Account must be $5, an overdraft penalty will be imposed of $" << overdraft_penealty << endl;
				this->set_balance(this->get_balance() - overdraft_penealty);
				this->add_transaction(transaction.create_transaction(4, this->get_balance(), amount, date, comment));
			}
			else {
				comment = "Insuffcient balance!";
				this->add_transaction(transaction.create_transaction(5, this->get_balance(), amount, date, comment));
				cout << comment << endl;
			}
		}
	}

	void add_interest() {
		Constants constants;
		Transaction transaction;
		string customer_type = constants.customer_type[this->get_customer().get_customer_type()];
		double intrest = 0;
		if (customer_type == constants.customer_type[0]) {
			intrest = Adult::SAVINGS_INTEREST;
			this->set_balance(this->get_balance() + intrest);
		}
		else if (customer_type == constants.customer_type[1]) {
			intrest = Student::SAVINGS_INTEREST;
			this->set_balance(this->get_balance() + intrest);
		}
		else if (customer_type == constants.customer_type[2]) {
			intrest = Senior::SAVINGS_INTEREST;
			this->set_balance(this->get_balance() + intrest);
		}
		this->add_transaction(transaction.create_transaction(2, this->get_balance(), intrest));
	}
};

/*
* @breif Bank class for Bank operations
*/
class Bank {
public:
	Account create_account(Customer customer, int account_num, int account_type, double initial_deposit = 0) {
		Account account;
		Transaction transaction;
		account = account.create_account(customer, account_num, account_type);
		if (initial_deposit > 0) {
			account.set_balance(initial_deposit);
			account.add_transaction(transaction.create_transaction(0, account.get_balance(), initial_deposit));
		}
		return account;
	}

	void make_deposit(int account_num, double amount, string date = "-") {
		Constants constants;
		Account account = get_account(account_num);
		if (account.get_account_number() != 0) {

			if (constants.account_type[account.get_account_type()] == constants.account_type[0]) {
				Checking_Account check_account = convert_to_check_account(account);
				check_account.deposit(amount, date);
				account = convert_to_account(check_account);
			}
			else if (constants.account_type[account.get_account_type()] == constants.account_type[1]) {
				Savings_Account savings_acc = convert_to_savings_account(account);
				savings_acc.deposit(amount, date);
				account = convert_to_account(savings_acc);
			}
			this->set_account(account);
		}
	}

	void make_withdrawal(int account_num, double amount, string date = "-") {
		Constants constants;
		Account account = get_account(account_num);
		if (account.get_account_number() != 0) {

			if (constants.account_type[account.get_account_type()] == constants.account_type[0]) {
				Checking_Account check_account = convert_to_check_account(account);
				check_account.withdraw(amount, date);
				account = convert_to_account(check_account);
			}
			else if (constants.account_type[account.get_account_type()] == constants.account_type[1]) {
				Savings_Account savings_acc = convert_to_savings_account(account);
				savings_acc.withdraw(amount, date);
				account = convert_to_account(savings_acc);
			}
			this->set_account(account);
		}
	}

	Account get_account(int account_number) {
		try {
			if (this->accounts.size() > 0) {

				for (auto account : accounts) {
					if (account.get_account_number() == account_number) {
						return account;
					}
				}

				cout << "Account number does not exixt please check the number and try again." << endl;
				Account account;
				return account;
			}
			else {
				cout << "Account number does not exixt please check the number and try again." << endl;
				Account account;
				return account;
			}
		}
		catch (exception e) {
			cout << "Exception occured : " << e.what() << endl;
		}
		Account account;
		return account;
	}

	void set_account(Account account) {
		if (this->accounts.size() > 0) {
			for (int i = 0; i < this->accounts.size(); i++) {
				if (this->accounts[i].get_account_number() == account.get_account_number()) {
					this->accounts[i] = account;
				}
			}
		}
	}

	Checking_Account convert_to_check_account(Account account) {
		Checking_Account check_acc;
		check_acc.set_balance(account.get_balance());
		check_acc.set_customer(account.get_customer());
		check_acc.set_account_type(account.get_account_type());
		check_acc.set_account_number(account.get_account_number());
		check_acc.set_transactions(account.get_transactions());
		return check_acc;
	}

	Savings_Account convert_to_savings_account(Account account) {
		Savings_Account savings_acc;
		savings_acc.set_balance(account.get_balance());
		savings_acc.set_customer(account.get_customer());
		savings_acc.set_account_type(account.get_account_type());
		savings_acc.set_account_number(account.get_account_number());
		savings_acc.set_transactions(account.get_transactions());
		return savings_acc;
	}

	Account convert_to_account(Checking_Account child_account) {
		Account account;
		account.set_balance(child_account.get_balance());
		account.set_customer(child_account.get_customer());
		account.set_account_type(child_account.get_account_type());
		account.set_account_number(child_account.get_account_number());
		account.set_transactions(child_account.get_transactions());
		return account;
	}

	Account convert_to_account(Savings_Account child_account) {
		Account account;
		account.set_balance(child_account.get_balance());
		account.set_customer(child_account.get_customer());
		account.set_account_type(child_account.get_account_type());
		account.set_account_number(child_account.get_account_number());
		account.set_transactions(child_account.get_transactions());
		return account;
	}

	int create_account_number(int acc_count) {
		Constants constants;
		return stoi(constants.AccountNumberPrefix + to_string(acc_count));
	}
	
	int create_customer_number(int acc_count) {
		Constants constants;
		return stoi(constants.CustomerNumberPrefix + to_string(acc_count));
	}

	void add_account(Account account) {
		accounts.push_back(account);
	}

	vector<Account> get_accounts() {
		return accounts;
	}



private:
	vector<Account> accounts;
};
#endif
