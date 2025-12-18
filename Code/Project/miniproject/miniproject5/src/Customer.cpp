#include "..\include\Customer.h"
#include <iostream>
using namespace std;
using std::string;

Customer::Customer(int id, string name) : id(id), name(name) {}

void Customer::addAccount(const Account &acc)
{
    accounts.push_back(acc);
}

void Customer::printCustomerReport() const
{
    cout << "Customer: " << name << " (ID: " << id << ")" << "\n";
    for (int i = 0; i < accounts.size(); i++)
    {
        accounts[i].printBalance();
    }
}