#include "..\include\Account.h"
#include <iostream>

Account::Account(int id, std::string owner, double initialBalance, AccountType type)
    : id(id), ownerName(owner), balance(initialBalance), type(type) {}

void Account::deposit(double amount)
{
}

bool Account::withdraw(double amount)
{
}

void Account::printBalance() const
{
}