#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
using std::string;

enum class TransactionType
{
    DEPOSIT,
    WITHDRAWAL,
    TRANSFER
};

class Transaction
{
private:
    int id;
    TransactionType type;
    double amount;
    string timestamp;

public:
    Transaction(int id, TransactionType type, double amount, string timestamp);

    bool operator==(const Transaction &other) const;
    Transaction operator+(const Transaction &other) const;

    void display() const;
    double getAmount() const { return amount; }
};

#endif