#pragma once
#include <iostream>
#include "Bank.h"

/**
 * @file BankWrapper.h
 * @brief This file contains the declarations of various banking functions.
 */

 /**
  * @brief Displays the welcome screen.
  */
void welcome_screen();

/**
 * @brief Creates a new account in the bank.
 *
 * @param bank The bank where the account will be created.
 * @param count The count of accounts in the bank.
 * @return The updated bank with the new account.
 */
Bank create_account(Bank bank, int count);

/**
 * @brief Deposits funds into an existing account.
 *
 * @param bank The bank where the deposit will be made.
 * @return The updated bank with the deposit.
 */
Bank deposit(Bank bank);

/**
 * @brief Withdraws funds from an existing account.
 *
 * @param bank The bank from which the withdrawal will be made.
 * @return The updated bank after the withdrawal.
 */
Bank withdraw(Bank bank);

/**
 * @brief Checks the account information and displays them with all transactions
 *
 * @param bank The bank containing the account to be checked.
 */
void check_acc(Bank bank);

/**
 * @brief Displays customer information.
 *
 * @param customer The customer to be displayed.
 */
void display_customer(Customer customer);

/**
 * @brief Displays account information.
 *
 * @param account The account to be displayed.
 */
void display_account_info(Account account);

/**
 * @brief Displays a list of transactions.
 *
 * @param transactions The list of transactions to be displayed.
 */
void display_transactions(vector<Transaction> transactions);

/**
 * @brief Converts a Date object to a string.
 *
 * @param date The Date object to be converted to a string.
 * @return The string representation of the Date.
 */
string get_string_date(Date date);