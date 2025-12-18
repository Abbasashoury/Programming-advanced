#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "..\include\Account.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class Customer
{
private:
    int id;
    string name;
    vector<Account> accounts;

public:
    Customer(int id, string name);
    void addAccount(const Account &acc);
    void printCustomerReport() const;
    const vector<Account> &getAccounts() const { return accounts; }
};

#endif