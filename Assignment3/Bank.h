#pragma once
#ifndef H__BANK_H
#define H__BANK_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Date.h"

/**
 * @file Bank.h
 * @brief This file contains the declaration and implementations classses required to perform all banking functions..
 */

using namespace std;

// the usual method of constant declaration didnt worked with maps (dictionary in cpp) hence used a normal class for constants.
/**
 * @class Constants
 * @brief A class containing constant values and mappings.
 * @details This class defines various constant values and maps for account numbers,
 * customer numbers, customer types, account types, and transaction types.
 */
class Constants {
public:
	/**
	 * @brief Prefix for account numbers.
	 */
	string AccountNumberPrefix = "2004";

	/**
	 * @brief Prefix for customer numbers.
	 */
	string CustomerNumberPrefix = "1002";

	/**
	 * @brief Map of customer types.
	 */
	map<int, string> customer_type = {
		{0 , "Adult"},
		{1, "Student"},
		{2, "Senior"}
	};

	/**
	 * @brief Map of account types.
	 */
	map<int, string> account_type = {
		{0 , "Checking"},
		{1, "Savings"}
	};

	/**
	 * @brief Map of transaction types.
	 */
	map<int, string> transaction_type = {
		{0, "DEP"},
		{1, "WD"},
		{2, "INT CR"},
		{3, "CHK CHRG"},
		{4, "OVRDFT PNLTY"},
		{5, "INVLD TRANSACTION"}
	};
};

/**
 * @class Customer
 * @brief A class representing a bank customer.
 * @details This class includes data members for customer information and provides
 * accessor and modifier functions to manage that information.
 */
class Customer {
public:
	/**
	 * @brief Creates a new customer with the given information.
	 *
	 * @param name The name of the customer.
	 * @param address The address of the customer.
	 * @param age The age of the customer.
	 * @param telephone_number The telephone number of the customer.
	 * @param customer_num The customer number of the customer.
	 * @param customer_type The type of the customer.
	 * @return A newly created customer object with the provided information.
	 */
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

	// Accessors

	/**
	 * @brief Get the name of the customer.
	 * @return The name of the customer.
	 */
	string get_name() {
		return name;
	}

	/**
	 * @brief Get the address of the customer.
	 * @return The address of the customer.
	 */
	string get_address() {
		return address;
	}

	/**
	 * @brief Get the age of the customer.
	 * @return The age of the customer.
	 */
	int get_age() {
		return age;
	}

	/**
	 * @brief Get the telephone number of the customer.
	 * @return The telephone number of the customer.
	 */
	string get_telephone_number() {
		return telephone_number;
	}

	/**
	 * @brief Get the customer number of the customer.
	 * @return The customer number of the customer.
	 */
	int get_customer_number() {
		return customer_number;
	}

	/**
	 * @brief Get the customer type of the customer.
	 * @return The customer type of the customer.
	 */
	int get_customer_type() {
		return customer_type;
	}

	// Modifiers

	/**
	 * @brief Set the name of the customer.
	 * @param name The new name of the customer.
	 */
	void set_name(string name) {
		this->name = name;
	}

	/**
	 * @brief Set the address of the customer.
	 * @param address The new address of the customer.
	 */
	void set_address(string address) {
		this->address = address;
	}

	/**
	 * @brief Set the age of the customer.
	 * @param age The new age of the customer.
	 */
	void set_age(int age) {
		this->age = age;
	}

	/**
	 * @brief Set the telephone number of the customer.
	 * @param telephone_number The new telephone number of the customer.
	 */
	void set_telephone_number(string telephone_number) {
		this->telephone_number = telephone_number;
	}

	/**
	 * @brief Set the customer number of the customer.
	 * @param customer_number The new customer number of the customer.
	 */
	void set_customer_number(int customer_number) {
		this->customer_number = customer_number;
	}

	/**
	 * @brief Set the customer type of the customer.
	 * @param customer_type The new customer type of the customer.
	 */
	void set_customer_type(int customer_type) {
		this->customer_type = customer_type;
	}

private:
	string name; ///< The name of the customer.
	string address; ///< The address of the customer.
	int age = 0; ///< The age of the customer.
	string telephone_number; ///< The telephone number of the customer.
	int customer_number = 0; ///< The customer number of the customer.
	int customer_type = 0; ///< The type of the customer.
};

/**
 * @class Senior
 * @brief A class representing senior customers.
 * @details This class inherits from the Customer class and defines constant values
 * related to savings, checking, and overdraft for senior customers.
 */
class Senior : public Customer {
public:
	/**
	* @brief The savings interest rate for senior customers.
	*/
	static const double SAVINGS_INTEREST;
	/**
	* @brief The checking interest rate for senior customers.
	*/
	static const double CHECK_INTEREST;

	/**
	 * @brief The checking charge for senior customers.
	 */
	static const double CHECK_CHARGE;

	/**
	 * @brief The overdraft penalty for senior customers.
	 */
	static const int OVERDRAFT_PENALTY;
};

/**
 * @class Adult
 * @brief A class representing adult customers.
 * @details This class inherits from the Customer class and defines constant values
 * related to savings, checking, and overdraft for adult customers.
 */
class Adult : public Customer {
public:
	/**
	* @brief The savings interest rate for adult customers.
	*/
	static const double SAVINGS_INTEREST;

	/**
	 * @brief The checking interest rate for adult customers.
	 */
	static const double CHECK_INTEREST;

	/**
	 * @brief The checking charge for adult customers.
	 */
	static const double CHECK_CHARGE;

	/**
	 * @brief The overdraft penalty for adult customers.
	 */
	static const int OVERDRAFT_PENALTY;
};

/**
 * @class Student
 * @brief A class representing student customers.
 * @details This class inherits from the Customer class and defines constant values
 * related to savings, checking, and overdraft for student customers.
 */
class Student : public Customer {
public:
	/**
	* @brief The savings interest rate for student customers.
	*/
	static const double SAVINGS_INTEREST;

	/**
	 * @brief The checking interest rate for student customers.
	 */
	static const double CHECK_INTEREST;

	/**
	 * @brief The checking charge for student customers.
	 */
	static const double CHECK_CHARGE;

	/**
	 * @brief The overdraft penalty for student customers.
	 */
	static const int OVERDRAFT_PENALTY;
};


/**
 * @class Transaction
 * @brief A class representing a financial transaction.
 * @details This class includes data members for transaction details and provides
 * accessor and modifier functions to manage that information.
 */
class Transaction {
public:
	/**
	 * @brief Creates a new transaction with the given information.
	 *
	 * @param transaction_type The type of the transaction.
	 * @param balance The balance after the transaction.
	 * @param amount The transaction amount.
	 * @param date The transaction date (default: "-").
	 * @param comments Transaction comments (default: "-").
	 * @return A newly created transaction object with the provided information.
	 */
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

	/**
	 * @brief Get the type of the transaction.
	 * @return The type of the transaction.
	 */
	int get_transaction_type() {
		return transaction_type;
	}

	/**
	 * @brief Get the transaction amount.
	 * @return The transaction amount.
	 */
	double get_amount() {
		return amount;
	}

	/**
	 * @brief Get the balance after the transaction.
	 * @return The balance after the transaction.
	 */
	double get_balance() {
		return balance;
	}

	/**
	 * @brief Get the transaction date.
	 * @return The transaction date.
	 */
	Date get_date() {
		return date;
	}

	/**
	 * @brief Get the transaction comments.
	 * @return The transaction comments.
	 */
	string get_comment() {
		return comments;
	}

	/**
	 * @brief Set the type of the transaction.
	 * @param transaction_type The new type of the transaction.
	 */
	void set_transaction_type(int transaction_type) {
		this->transaction_type = transaction_type;
	}

	/**
	 * @brief Set the transaction amount.
	 * @param amount The new transaction amount.
	 */
	void set_amount(double amount) {
		this->amount = amount;
	}

	/**
	 * @brief Set the balance after the transaction.
	 * @param balance The new balance after the transaction.
	 */
	void set_balance(double balance) {
		this->balance = balance;
	}

	/**
	 * @brief Set the transaction date.
	 * @param date The new transaction date as a string.
	 */
	void set_date(string date) {
		Date newDate;
		this->date = newDate.convertToDate(date);
	}

private:
	int transaction_type; ///< The type of the transaction.
	double amount; ///< The transaction amount.
	double balance; ///< The balance after the transaction.
	Date date; ///< The transaction date.
	string comments; ///< Transaction comments.
};

/**
 * @class Account
 * @brief A class representing a bank account.
 * @details This class includes data members for account information, such as customer,
 * balance, account number, account type, and transactions. It also provides accessors
 * and modifiers to manage this information.
 */
class Account {
public:
	/**
	 * @brief Creates a new account with the given information.
	 *
	 * @param customer The customer associated with the account.
	 * @param account_num The account number.
	 * @param account_type The account type.
	 * @param balance The initial account balance (default: 0).
	 * @return A newly created account object with the provided information.
	 */
	Account create_account(Customer customer, int account_num, int account_type, double balance = 0) {
		Account account;
		account.customer = customer;
		account.balance = balance;
		account.account_number = account_num;
		account.account_type = account_type;
		return account;
	}

	// Accessors

	/**
	 * @brief Get the account number.
	 * @return The account number.
	 */
	int get_account_number() {
		return account_number;
	}

	/**
	 * @brief Get the account balance.
	 * @return The account balance.
	 */
	double get_balance() {
		return balance;
	}

	/**
	 * @brief Get the account type.
	 * @return The account type.
	 */
	int get_account_type() {
		return account_type;
	}

	/**
	 * @brief Get the customer associated with the account.
	 * @return The customer associated with the account.
	 */
	Customer get_customer() {
		return customer;
	}

	/**
	 * @brief Get the list of transactions associated with the account.
	 * @return The list of transactions.
	 */
	vector<Transaction> get_transactions() {
		return transactions;
	}

	// Modifiers

	/**
	 * @brief Set the customer associated with the account.
	 * @param customer The new customer associated with the account.
	 */
	void set_customer(Customer customer) {
		this->customer = customer;
	}

	/**
	 * @brief Set the account balance.
	 * @param balance The new account balance.
	 */
	void set_balance(double balance) {
		this->balance = balance;
	}

	/**
	 * @brief Set the account type.
	 * @param account_type The new account type.
	 */
	void set_account_type(int account_type) {
		this->account_type = account_type;
	}

	/**
	 * @brief Set the account number.
	 * @param account_num The new account number.
	 */
	void set_account_number(int account_num) {
		this->account_number = account_num;
	}

	/**
	 * @brief Add a transaction to the account's transaction list.
	 * @param transaction The transaction to add.
	 */
	void add_transaction(Transaction transaction) {
		transactions.push_back(transaction);
	}

	/**
	 * @brief Set the list of transactions associated with the account.
	 * @param transactions The new list of transactions.
	 */
	void set_transactions(vector<Transaction> transactions) {
		this->transactions = transactions;
	}

private:
	Customer customer; ///< The customer associated with the account.
	double balance; ///< The account balance.
	int account_number; ///< The account number.
	int account_type; ///< The account type.
	Date date; ///< The account's creation date.
	vector<Transaction> transactions; ///< The list of transactions associated with the account.
};

/**
 * @class Savings_Account
 * @brief A class representing a savings bank account.
 * @details This class extends the Account class and provides specific functions for
 * depositing, withdrawing, and adding interest to a savings account.
 */
class Savings_Account : public Account {
public:
	/**
	 * @brief Deposit the specified amount into the savings account.
	 *
	 * @param amount The amount to deposit.
	 * @param date The date of the deposit.
	 */
	void deposit(double amount, string date) {
		try {
			Transaction transaction;

			this->set_balance(this->get_balance() + amount);
			this->add_transaction(transaction.create_transaction(0, this->get_balance(), amount, date));
			this->add_interest();
			cout << "Amount $" << amount << " added to account '" << this->get_account_number() << "'" << endl;
			cout << "Your current balance is now: $" << this->get_balance() << endl;
		}
		catch (exception e) {
			cout << "Exception occurred: " << e.what() << endl;
		}
	}

	/**
	 * @brief Withdraw the specified amount from the savings account.
	 *
	 * @param amount The amount to withdraw.
	 * @param date The date of the withdrawal.
	 */
	void withdraw(double amount, string date) {
		try {
			Transaction transaction;
			Constants constants;
			int overdraft_penalty;
			double check_charge;
			string customer_type = constants.customer_type[this->get_customer().get_customer_type()];

			if (customer_type == constants.customer_type[0]) {
				overdraft_penalty = Adult::OVERDRAFT_PENALTY;
				check_charge = Adult::CHECK_CHARGE;
			}
			else if (customer_type == constants.customer_type[1]) {
				overdraft_penalty = Student::OVERDRAFT_PENALTY;
				check_charge = Student::CHECK_CHARGE;
			}
			else if (customer_type == constants.customer_type[2]) {
				overdraft_penalty = Senior::OVERDRAFT_PENALTY;
				check_charge = Senior::CHECK_CHARGE;
			}

			if (this->get_balance() > amount) {
				this->set_balance(this->get_balance() - amount);
				this->add_transaction(transaction.create_transaction(1, this->get_balance(), amount, date));
				cout << "As you are withdrawing from a Savings account, a check charge of $" << check_charge << " will be imposed." << endl;
				this->set_balance(this->get_balance() - check_charge);
				this->add_transaction(transaction.create_transaction(3, this->get_balance(), check_charge, date));
				cout << "Withdrawal successful! Your new balance is: $" << this->get_balance() << endl;
			}
			else {
				if (this->get_balance() <= 5) {
					cout << "Minimum Balance in Account must be $5, an overdraft penalty will be imposed of $" << overdraft_penalty << endl;
					this->set_balance(this->get_balance() - overdraft_penalty);
					this->add_transaction(transaction.create_transaction(4, this->get_balance(), amount, date, "overdraft penalty"));
				}
				else {
					string comment = "Insufficient balance!";
					this->add_transaction(transaction.create_transaction(5, this->get_balance(), amount, date, comment));
					cout << comment << endl;
				}
			}
		}
		catch (exception e) {
			cout << "Exception occurred: " << e.what() << endl;
		}
	}

	/**
	 * @brief Add interest to the savings account based on the customer type.
	 */
	void add_interest() {
		try {
			Constants constants;
			Transaction transaction;
			string customer_type = constants.customer_type[this->get_customer().get_customer_type()];
			double interest = 0;

			if (customer_type == constants.customer_type[0]) {
				interest = Adult::SAVINGS_INTEREST;
				this->set_balance(this->get_balance() + interest);
			}
			else if (customer_type == constants.customer_type[1]) {
				interest = Student::SAVINGS_INTEREST;
				this->set_balance(this->get_balance() + interest);
			}
			else if (customer_type == constants.customer_type[2]) {
				interest = Senior::SAVINGS_INTEREST;
				this->set_balance(this->get_balance() + interest);
			}

			this->add_transaction(transaction.create_transaction(2, this->get_balance(), interest));
		}
		catch (exception e) {
			cout << "Exception occurred: " << e.what() << endl;
		}
	}
};

/**
 * @class Checking_Account
 * @brief A class representing a checking bank account.
 * @details This class extends the Account class and provides specific functions for depositing,
 * withdrawing, and adding interest to a checking account.
 */
class Checking_Account : public Account {
public:
	/**
	 * @brief Deposit the specified amount into the checking account.
	 *
	 * @param amount The amount to deposit.
	 * @param date The date of the deposit.
	 */
	void deposit(double amount, string date) {
		try {
			Transaction transaction;
			if (amount <= 0) {
				cout << "Deposit of 0 or less than zero is not allowed. Please try again with a valid deposit." << endl;
				return;
			}
			this->set_balance(this->get_balance() + amount);
			this->add_transaction(transaction.create_transaction(0, this->get_balance(), amount, date));
			this->add_interest();
			cout << "Amount $" << amount << " added to account '" << this->get_account_number() << "'" << endl;
			cout << "Your current balance is now: $" << this->get_balance() << endl;
		}
		catch (exception e) {
			cout << "Exception occurred: " << e.what() << endl;
		}
	}

	/**
	 * @brief Withdraw the specified amount from the checking account.
	 *
	 * @param amount The amount to withdraw.
	 * @param date The date of the withdrawal.
	 */
	void withdraw(double amount, string date) {
		try {
			Transaction transaction;
			Constants constants;
			int overdraft_penalty;
			string customer_type = constants.customer_type[this->get_customer().get_customer_type()];
			if (amount <= 0) {
				cout << "Withdrawal of 0 or less than zero is not allowed. Please try again with a valid withdrawal." << endl;
				return;
			}
			if (customer_type == constants.customer_type[0]) {
				overdraft_penalty = Adult::OVERDRAFT_PENALTY;
			}
			else if (customer_type == constants.customer_type[1]) {
				overdraft_penalty = Student::OVERDRAFT_PENALTY;
			}
			else if (customer_type == constants.customer_type[2]) {
				overdraft_penalty = Senior::OVERDRAFT_PENALTY;
			}

			if (this->get_balance() > amount) {
				this->set_balance(this->get_balance() - amount);
				this->add_transaction(transaction.create_transaction(1, this->get_balance(), amount, date));
				cout << "Withdrawal successful! Your new balance is: $" << this->get_balance() << endl;
			}
			else {
				string comment;
				if (this->get_balance() <= 5) {
					comment = "overdraft penalty";
					cout << "Minimum Balance in Account must be $5. An overdraft penalty will be imposed of $" << overdraft_penalty << endl;
					this->set_balance(this->get_balance() - overdraft_penalty);
					this->add_transaction(transaction.create_transaction(4, this->get_balance(), amount, date, comment));
				}
				else {
					comment = "Insufficient balance!";
					this->add_transaction(transaction.create_transaction(5, this->get_balance(), amount, date, comment));
					cout << comment << endl;
				}
			}
		}
		catch (exception e) {
			cout << "Exception occurred: " << e.what() << endl;
		}
	}

	/**
	 * @brief Add interest to the checking account based on the customer type.
	 */
	void add_interest() {
		try {
			Constants constants;
			Transaction transaction;
			string customer_type = constants.customer_type[this->get_customer().get_customer_type()];
			double interest = 0;

			if (customer_type == constants.customer_type[0]) {
				interest = Adult::SAVINGS_INTEREST;
				this->set_balance(this->get_balance() + interest);
			}
			else if (customer_type == constants.customer_type[1]) {
				interest = Student::SAVINGS_INTEREST;
				this->set_balance(this->get_balance() + interest);
			}
			else if (customer_type == constants.customer_type[2]) {
				interest = Senior::SAVINGS_INTEREST;
				this->set_balance(this->get_balance() + interest);
			}

			this->add_transaction(transaction.create_transaction(2, this->get_balance(), interest));
		}
		catch (exception e) {
			cout << "Exception occurred: " << e.what() << endl;
		}
	}
};

/**
 * @class Bank
 * @brief A class representing a bank and its operations.
 * @details This class provides functions to create and manage accounts, make deposits and withdrawals,
 * and perform conversions between different types of bank accounts.
 */
class Bank {
public:

	/**
	* Create a new account for a customer in the bank.
	* @param customer The customer for whom the account is created.
	* @param account_num The account number for the new account.
	* @param account_type The type of the new account (0 for Checking, 1 for Savings).
	* @param initial_deposit The initial deposit for the new account.
	* @return The created account.
	*/
	Account create_account(Customer customer, int account_num, int account_type, double initial_deposit = 0) {
		Account account;
		try {
			Transaction transaction;
			account = account.create_account(customer, account_num, account_type);
			if (initial_deposit > 0) {
				account.set_balance(initial_deposit);
				account.add_transaction(transaction.create_transaction(0, account.get_balance(), initial_deposit));
			}
		}
		catch (exception e) {
			cout << "Exception occured: " << e.what() << endl;
		}
		return account;
	}

	/**
	* Make a deposit to an existing account in the bank.
	* @param account_num The account number for which the deposit is made.
	* @param amount The amount to be deposited.
	* @param date The date of the deposit (optional, default is "-").
	*/
	void make_deposit(int account_num, double amount, string date = "-") {
		try {
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
		catch (exception e) {
			cout << "Exception occured: " << e.what() << endl;
		}
	}

	/**
	* Make a withdrawal from an existing account in the bank.
	* @param account_num The account number from which the withdrawal is made.
	* @param amount The amount to be withdrawn.
	* @param date The date of the withdrawal (optional, default is "-").
	*/
	void make_withdrawal(int account_num, double amount, string date = "-") {
		try {
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
		catch (exception e) {
			cout << "Exception occured: " << e.what() << endl;
		}
	}

	/**
	* Get an account by its account number.
	* @param account_number The account number to retrieve.
	* @return The account with the specified account number.
	*/
	Account get_account(int account_number) {
		Account account;
		try {
			if (this->accounts.size() > 0) {

				for (auto acc : accounts) {
					if (acc.get_account_number() == account_number) {
						return acc;
					}
				}

				cout << "Account number does not exixt please check the number and try again." << endl;
			}
			else {
				cout << "No Accounts exisit in Bank. Please create a new Account" << endl;
			}
		}
		catch (exception e) {
			cout << "Exception occured : " << e.what() << endl;
		}
		return account;
	}

	/**
	 * Set the account with updated information.
	 * @param account The account with updated information.
	 */
	void set_account(Account account) {
		try {
			if (this->accounts.size() > 0) {
				for (int i = 0; i < this->accounts.size(); i++) {
					if (this->accounts[i].get_account_number() == account.get_account_number()) {
						this->accounts[i] = account;
					}
				}
			}
		}
		catch (exception e) {
			cout << "Exception occured: " << e.what() << endl;
		}
	}

	/**
	* Convert an Account object to a Checking_Account object.
	* @param account The Account object to be converted.
	* @return The corresponding Checking_Account object.
	*/
	Checking_Account convert_to_check_account(Account account) {
		Checking_Account check_acc;
		try {
			check_acc.set_balance(account.get_balance());
			check_acc.set_customer(account.get_customer());
			check_acc.set_account_type(account.get_account_type());
			check_acc.set_account_number(account.get_account_number());
			check_acc.set_transactions(account.get_transactions());
		}
		catch (exception e) {
			cout << "Exception occured: " << e.what() << endl;
		}
		return check_acc;
	}

	/**
	* Convert an Account object to a Savings_Account object.
	* @param account The Account object to be converted.
	* @return The corresponding Savings_Account object.
	*/
	Savings_Account convert_to_savings_account(Account account) {
		Savings_Account savings_acc;
		try {
			savings_acc.set_balance(account.get_balance());
			savings_acc.set_customer(account.get_customer());
			savings_acc.set_account_type(account.get_account_type());
			savings_acc.set_account_number(account.get_account_number());
			savings_acc.set_transactions(account.get_transactions());
		}
		catch (exception e) {
			cout << "Exception occured: " << e.what() << endl;
		}
		return savings_acc;
	}

	/**
	* Convert a Checking_Account object to an Account object.
	* @param child_account The Checking_Account object to be converted.
	* @return The corresponding Account object.
	*/
	Account convert_to_account(Checking_Account child_account) {
		Account account;
		try {
			account.set_balance(child_account.get_balance());
			account.set_customer(child_account.get_customer());
			account.set_account_type(child_account.get_account_type());
			account.set_account_number(child_account.get_account_number());
			account.set_transactions(child_account.get_transactions());
		}
		catch (exception e) {
			cout << "Exception occured: " << e.what() << endl;
		}
		return account;
	}

	/**
	* Convert a Savings_Account object to an Account object.
	* @param child_account The Savings_Account object to be converted.
	* @return The corresponding Account object.
	*/
	Account convert_to_account(Savings_Account child_account) {
		Account account;
		try {
			account.set_balance(child_account.get_balance());
			account.set_customer(child_account.get_customer());
			account.set_account_type(child_account.get_account_type());
			account.set_account_number(child_account.get_account_number());
			account.set_transactions(child_account.get_transactions());
		}
		catch (exception e) {
			cout << "Exception occured: " << e.what() << endl;
		}
		return account;
	}

	/**
	* Create a unique account number based on the account count.
	* @param acc_count The count of accounts in the bank.
	* @return The newly generated account number.
	*/
	int create_account_number(int acc_count) {
		Constants constants;
		return stoi(constants.AccountNumberPrefix + to_string(acc_count));
	}

	/**
	* Create a unique customer number based on the account count.
	* @param acc_count The count of accounts in the bank.
	* @return The newly generated customer number.
	*/
	int create_customer_number(int acc_count) {
		Constants constants;
		return stoi(constants.CustomerNumberPrefix + to_string(acc_count));
	}

	/**
	* Add an account to the bank's accounts list.
	* @param account The account to be added.
	*/
	void add_account(Account account) {
		accounts.push_back(account);
	}

	/**
	* Get a list of all accounts in the bank.
	* @return A vector of all accounts in the bank.
	*/
	vector<Account> get_accounts() {
		return accounts;
	}

private:

	vector<Account> accounts; ///< The list of account associated with the bank.
};
#endif
