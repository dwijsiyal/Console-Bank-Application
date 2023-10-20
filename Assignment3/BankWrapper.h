#pragma once
#include <iostream>
#include "Bank.h"

void welcome_screen();

Bank create_account(Bank bank,int count);

Bank deposit(Bank bank);

Bank withdraw(Bank bank);

void check_acc(Bank bank);

void display_customer(Customer customer);

void display_account_info(Account account);

void display_transactions(vector<Transaction> transactions);

string get_string_date(Date date);
