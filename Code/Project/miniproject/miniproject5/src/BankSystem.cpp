#include "..\include\BankSystem.h"
#include <iostream>
using namespace std;

int BankSystem::totalAccounts = 0;

void BankSystem::addCustomer(const Customer &c)
{
    customers.push_back(c);
}

bool BankSystem::transfer(Account &from, Account &to, double amount)
{
    if (from.withdraw(amount))
    {
        to.deposit(amount);
        transactions.push_back(Transaction(transactions.size() + 1, TransactionType::TRANSFER, amount, "2025/12/18"));
        return true;
    }
    return false;
}
void BankSystem::processDeposit(Account &acc, double amount)
{
    acc.deposit(amount);
    transactions.push_back(Transaction(transactions.size() + 1, TransactionType::DEPOSIT, amount, "2025/12/18"));
}

void BankSystem::processWithdraw(Account &acc, double amount)
{
    if (acc.withdraw(amount))
    {
        transactions.push_back(Transaction(transactions.size() + 1, TransactionType::WITHDRAWAL, amount, "2025/12/18"));
    }
}

int BankSystem::getTotalAccounts() { return totalAccounts; }
void BankSystem::incrementAccounts() { totalAccounts++; }

void BankSystem::showGlobalReport() const
{
    cout << "=====================================================\n";
    cout << "Total Bank Accounts Managed: " << totalAccounts << "\n";
    for (int i = 0; i < transactions.size(); i++)
    {
        transactions[i].display();
    }
}