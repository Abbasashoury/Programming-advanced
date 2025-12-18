#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H
using std::vector;

#include "..\include\Customer.h"
#include "..\include\Transaction.h"
#include <vector>

class BankSystem
{
private:
    vector<Customer> customers;
    vector<Transaction> transactions;

public:
    void addCustomer(const Customer &c);
    bool transfer(Account &from, Account &to, double amount);
    void showGlobalReport() const;

    static int getTotalAccounts();
    static void incrementAccounts();
};

#endif