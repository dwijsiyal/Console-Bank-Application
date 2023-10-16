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
        cout << "Amount $" << amount << "added to account '" << this->get_account_number() << "'" << endl;
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
        cout << "Amount $" << amount << "added to account '" << this->get_account_number() << "'" << endl;
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
    void add_account(Customer customer, int account_num, int account_type) {
        Account account;
        account.create_account(customer, account_num, account_type);
        accounts.push_back(account);
    }

    void make_deposit(int account_num, double amount) {
        Constants constants;
        Account account = get_account(account_num);
        if (constants.account_type[account.get_account_type()] == constants.account_type[0]) {
            Checking_Account check_account = convert_to_check_account(account);
            check_account.deposit(amount);
        }
        else if(constants.account_type[account.get_account_type()] == constants.account_type[1]){
            Savings_Account savings_acc = convert_to_savings_account(account);
            savings_acc.deposit(amount);
        }
    }

    void make_withdrawal(int account_num, double amount) {
        Constants constants;
        Account account = get_account(account_num);
        if (constants.account_type[account.get_account_type()] == constants.account_type[0]) {
            Checking_Account check_account = convert_to_check_account(account);
            check_account.withdraw(amount);
        }
        else if (constants.account_type[account.get_account_type()] == constants.account_type[1]) {
            Savings_Account savings_acc = convert_to_savings_account(account);
            savings_acc.withdraw(amount);
        }
    }

    Account get_account(int account_number) {
        try {
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
        catch (exception e) {
            cout << "Exception occured : " << e.what() << endl;
        }
    }

    Checking_Account convert_to_check_account(Account account) {
        Checking_Account check_acc;
        check_acc.set_balance(account.get_balance());
        check_acc.set_customer(account.get_customer());
        check_acc.set_account_type(account.get_account_type());
        check_acc.set_account_number(account.get_account_number());
    }

    Savings_Account convert_to_savings_account(Account account) {
        Savings_Account savings_acc;
        savings_acc.set_balance(account.get_balance());
        savings_acc.set_customer(account.get_customer());
        savings_acc.set_account_type(account.get_account_type());
        savings_acc.set_account_number(account.get_account_number());
    }
private:
    vector<Account> accounts;
};

// the previous method of constant declaration didnt worked with maps (dictionary in cpp) hence used a normal class for constants.
class Constants {

public:
    static const string AccountNumberPrefix;
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

const string Constants::AccountNumberPrefix = "2004";