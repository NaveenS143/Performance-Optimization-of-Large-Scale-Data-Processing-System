// TransactionProcessor.h
#pragma once
#include<iostream>
#include <fstream>     
#include <vector>      
#include <sstream>  
#include "Transaction.h"

class TransactionProcessor {
public:
    std::vector<Transaction> transactions;

    void loadTransactionsFromCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        std::string line;
        // Skip the header line
        std::getline(file, line);

        // Read each line and create a Transaction object
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string id, timestamp, type, currency, status, location;
            int accountID;
            double amount;

            std::getline(ss, id, ',');
            std::getline(ss, timestamp, ',');
            ss >> accountID;
            ss.ignore(1);  // Ignore comma
            std::getline(ss, type, ',');
            ss >> amount;
            ss.ignore(1);  // Ignore comma
            std::getline(ss, currency, ',');
            std::getline(ss, status, ',');
            std::getline(ss, location, ',');

            transactions.emplace_back(id, timestamp, accountID, type, amount, currency, status, location);
        }

        file.close();
        std::cout << "Loaded " << transactions.size() << " transactions.\n";
    }

    double aggregateAmountByType(const std::vector<Transaction>& transactions, const std::string& type) {
        double total = 0.0;
        for (const auto& transaction : transactions) {
            if (transaction.transactionType == type) {
                total += transaction.amount;
            }
        }
        return total;
    }
    
    std::vector<Transaction> filterTransactionsByStatus(const std::vector<Transaction>& transactions, const std::string& status) {
        std::vector<Transaction> filtered;
        for (const auto& transaction : transactions) {
            if (transaction.status == status) {
                filtered.push_back(transaction);
            }
        }
        return filtered;
    }

};

