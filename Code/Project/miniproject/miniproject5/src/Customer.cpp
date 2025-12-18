#include "..\include\Customer.h"
#include <iostream>
using namespace std;
using std::string;

Customer::Customer(int id, string name) : id(id), name(name) {}

void Customer::addAccount(const Account &acc)
{
}

void Customer::printCustomerReport() const
{
}