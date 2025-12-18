#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "..\include\Transaction.h"

using std::string;

enum class AccountType
{
    SAVINGS,
    CHECKING,
    CREDIT
};

class Account
{
private:
    int id;
    string ownerName;
    double balance;
    AccountType type;

public:
    Account(int id, string owner, double initialBalance, AccountType type);

    void deposit(double amount);
    bool withdraw(double amount);
    void printBalance() const;

    friend class BankSystem;

    int getId() const { return id; }
    double getBalance() const { return balance; }
};

#endif