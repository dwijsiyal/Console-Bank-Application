#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Date.h"

using namespace std;

/*
* @brief class of customer for Bank.
*/
class Customer {
public:
    Customer(string name, string address, int age, string telephone_number, int customer_number, int customer_type)
        : name(name), address(address), age(age), telephone_number(telephone_number), customer_number(customer_number), customer_type(customer_type){
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
    static const double OVERDRAFT_PENALTY;
};

const double Senior::SAVINGS_INTEREST = 0.04;
const double Senior::CHECK_INTEREST = 0.01;
const double Senior::CHECK_CHARGE = 0.01;
const double Senior::OVERDRAFT_PENALTY = 25;

class Adult : public Customer {
public:
    static const double SAVINGS_INTEREST;
    static const double CHECK_INTEREST;
    static const double CHECK_CHARGE;
    static const double OVERDRAFT_PENALTY;
};

const double Adult::SAVINGS_INTEREST = 0.03;
const double Adult::CHECK_INTEREST = 0.01;
const double Adult::CHECK_CHARGE = 0.03;
const double Adult::OVERDRAFT_PENALTY = 25;

class Student : public Customer {
public:
    static const double SAVINGS_INTEREST;
    static const double CHECK_INTEREST;
    static const double CHECK_CHARGE;
    static const double OVERDRAFT_PENALTY;
};

const double Student::SAVINGS_INTEREST = 0.04;
const double Student::CHECK_INTEREST = 0.01;
const double Student::CHECK_CHARGE = 0.02;
const double Student::OVERDRAFT_PENALTY = 25;

/*
* @breif class of Transaction for Bank
*/
class Transaction {
public:
    Transaction(string transaction_type, double amount, double balance, Date date)
        : transaction_type(transaction_type), amount(amount), balance(balance), date(date) {
    }

    string get_transaction_type() {
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

    string set_transaction_type(string transaction_type) {
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
        this->date = newDate.converToDate(date);
    }


private:
    string transaction_type;
    double amount;
    double balance;
    Date date;
};

/*
* @breif Account class for Bank operations
*/
class Account {
public:

    Account(Customer customer, double balance, int account_number, int account_type)
        : customer(customer), balance(balance), account_number(account_number), account_type(account_type){
    }

    Account create_account(Customer customer, double balance, int account_num, int account_type) {
        return Account(customer, balance, account_num, account_type);
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

    void set_customer(Customer customer) {
        this->customer = customer;
    }

    void set_balance(double balance) {
        this->balance = balance;
    }

    void set_account_type(int account_type) {
        this->account_type = account_type;
    }

private:
    Customer customer;
    double balance;
    int account_number;
    int account_type;
    vector<Transaction> transactions;
};

/*
* @breif Savings Account class for Bank operations
*/
class Savings_Account : public Account {
public:
    void deposit(double amount) {
        this->set_balance(this->get_balance() + amount);
        cout << "Your current balance is now: $" << this->get_balance() << endl;
    }

    void withdraw(double amount) {
        if (this->get_balance() > amount) {
            this->set_balance(this->get_balance() - amount);
        }
        else {
            cout << "Insuffcient balance!" << endl;
        }
    }

    void add_interest() {
        Constants constants;
        string customer_type = constants.customer_type[this->get_customer().get_customer_type()];
        if (customer_type == constants.customer_type[0]) {
            this->set_balance(this->get_balance() + Adult::SAVINGS_INTEREST);
        }
        else if (customer_type == constants.customer_type[1]) {
            this->set_balance(this->get_balance() + Student::SAVINGS_INTEREST);
        }
        else if (customer_type == constants.customer_type[2]) {
            this->set_balance(this->get_balance() + Senior::SAVINGS_INTEREST);
        }
};

/*
* @breif Checking Account class for Bank operations
*/
class Checking_Account : public Account {
public:
    void deposit(double amount) {
        this->set_balance(this->get_balance() + amount);
        cout << "Your current balance is now: $" << this->get_balance() << endl;
    }

    void withdraw(double amount) {
        if (this->get_balance() > amount) {
            this->set_balance(this->get_balance() - amount);
        }
        else {
            cout << "Insuffcient balance!" << endl;
        }
    }

    void add_interest() {
        Constants constants;
        string customer_type = constants.customer_type[this->get_customer().get_customer_type()];
        if (customer_type == constants.customer_type[0]) {
            this->set_balance(this->get_balance() + Adult::CHECK_INTEREST);
        }
        else if (customer_type == constants.customer_type[1]) {
            this->set_balance(this->get_balance() + Student::CHECK_INTEREST);
        }
        else if (customer_type == constants.customer_type[2]) {
            this->set_balance(this->get_balance() + Senior::CHECK_INTEREST);
        }
    }
};

/*
* @breif Bank class for Bank operations
*/
class Bank {
public:
    void add_account(Account account) {
        accounts.push_back(account);
    }

    void make_deposit(Account account, double amount) {
        // Add logic to make a deposit
    }

    void make_withdrawal(Account account, double amount) {
        // Add logic to make a withdrawal
    }

    Account get_account(int account_number) {
        for (auto account : accounts) {
            if (account.get_account_number() == account_number) {
                return account;
            }
            else {
                cout << "Account number does not exixt please check the number and try again." << endl;
                return;
            }
        }
    }

private:
    vector<Account> accounts;
};

// the previous method of constant declaration didnt worked with maps (dictionary in cpp) hence used a normal class for constants.
class Constants {

public:
    string AccountNumberPrefix = "2004";
    map<int, string> customer_type = {
            {0 , "Adult"},
            {1, "Student"},
            {2, "Senior"}
    };
    map<int, string> account_type = {
        {0 , "Checking"},
        {1, "Savings"}
    };
};