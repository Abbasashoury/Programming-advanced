#include "..\include\Account.h"
#include <iostream>
using namespace std;

Account::Account(int id, std::string owner, double initialBalance, AccountType type)
    : id(id), ownerName(owner), balance(initialBalance), type(type) {}

void Account::deposit(double amount)
{
    if (amount > 0)
        balance += amount;
}

bool Account::withdraw(double amount)
{
    if (amount > 0 && balance >= amount)
    {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::printBalance() const
{
    cout << "Account ID: " << id << " | Owner: " << ownerName
         << " | Current Balance: " << balance << "\n";
}