#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include "..\include\Customer.h"
#include "..\include\Transaction.h"
#include <vector>

using std::vector;

class BankSystem
{
private:
    vector<Customer> customers;
    vector<Transaction> transactions;
    static int totalAccounts;

public:
    void addCustomer(const Customer &c);
    bool transfer(Account &from, Account &to, double amount);
    void processDeposit(Account &acc, double amount);
    void processWithdraw(Account &acc, double amount);

    void showGlobalReport() const;

    static int getTotalAccounts();
    static void incrementAccounts();
};

#endif