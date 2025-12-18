#include "..\include\Transaction.h"
using namespace std;
using std::string;

Transaction::Transaction(int id, TransactionType type, double amount, string timestamp)
    : id(id), type(type), amount(amount), timestamp(timestamp) {}

bool Transaction::operator==(const Transaction &other) const
{
    return (this->amount == other.amount && this->type == other.type);
}

Transaction Transaction::operator+(const Transaction &other) const
{
    return Transaction(0, this->type, this->amount + other.amount, "combined");
}

void Transaction::display() const
{
    string tStr = (type == TransactionType::DEPOSIT) ? "Deposit" : (type == TransactionType::WITHDRAWAL) ? "Withdrawal"
                                                                                                         : "Transfer";
    cout << "Transaction [" << id << "] | Type: " << tStr
         << " | Amount: " << amount << " | Date: " << timestamp << "\n";
}