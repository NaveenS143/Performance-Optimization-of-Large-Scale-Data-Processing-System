// Transaction.h
#pragma once
#include <string>

class Transaction {
public:
    std::string transactionID;
    std::string timestamp;
    int accountID;
    std::string transactionType;
    double amount;
    std::string currency;
    std::string status;
    std::string location;

    Transaction(
        const std::string& id, const std::string& time, int account,
        const std::string& type, double amt, const std::string& curr,
        const std::string& stat, const std::string& loc)
        : transactionID(id), timestamp(time), accountID(account),
          transactionType(type), amount(amt), currency(curr),
          status(stat), location(loc) {}
};
