#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"

using namespace std;

/*
* @brief class of customer for Bank.
*/
class Customer {
public:
    Customer(string name, string address, int age, string telephone_number, int customer_number)
        : name(name), address(address), age(age), telephone_number(telephone_number), customer_number(customer_number) {
    }

    // Accessors and modifiers for data fields can be added here

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    int getAge() {
        return age;
    }

    string getTelephoneNumber() {
        return telephone_number;
    }

    int getCustomerNumber() {
        return customer_number;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAddress(string address) {
        this->address = address;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setTelephoneNumber() {
        this->telephone_number = telephone_number;
    }

    void setCustomerNumber() {
        this->customer_number = customer_number;
    }

private:
    string name;
    string address;
    int age;
    string telephone_number;
    int customer_number;
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

    string getTransactionType() {
        return transaction_type;
    }

    double getAmount() {
        return amount;
    }

    double getBalance() {
        return balance;
    }

    Date getDate() {
        return date;
    }

    string setTransactionType(string transaction_type) {
        this->transaction_type = transaction_type;
    }

    double setAmount(double amount) {
        this->amount = amount;
    }

    double setBalance(double balance) {
        this->balance = balance;
    }

    Date setDate(string date) {
        this->date = 
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
    Account(Customer customer, double balance, int account_number)
        : customer(customer), balance(balance), account_number(account_number) {
    }

    void create_account() {
        // Add logic to create an account here
    }

    int get_account_number() {
        return account_number;
    }

    double get_balance() {
        return balance;
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

private:
    Customer customer;
    double balance;
    int account_number;
    vector<Transaction> transactions;
};

/*
* @breif Savings Account class for Bank operations
*/
class Savings_Account : public Account {
public:
    void deposit(double amount) {
        // Add logic to deposit money into savings account
    }

    void withdraw(double amount) {
        // Add logic to withdraw money from savings account
    }

    void add_interest() {
        // Add logic to add interest to savings account
    }
};

/*
* @breif Checking Account class for Bank operations
*/
class Checking_Account : public Account {
public:
    void deposit(double amount) {
        // Add logic to deposit money into checking account
    }

    void withdraw(double amount) {
        // Add logic to withdraw money from checking account
    }

    void add_interest() {
        // Add logic to add interest to checking account
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
        // Add logic to retrieve an account by account number
    }

private:
    vector<Account> accounts;
};
