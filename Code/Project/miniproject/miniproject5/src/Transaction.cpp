#include "..\include\Transaction.h"
using namespace std;
using std::string;

Transaction::Transaction(int id, TransactionType type, double amount, string timestamp)
    : id(id), type(type), amount(amount), timestamp(timestamp) {}

bool Transaction::operator==(const Transaction &other) const
{
}

Transaction Transaction::operator+(const Transaction &other) const
{
}

void Transaction::display() const
{
}