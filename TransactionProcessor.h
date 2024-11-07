#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>  // To group by currency
#include <algorithm>  // For sorting
#include <cctype>  // For tolower()
#include <string>
#include "Transaction.h"

class TransactionProcessor {
public:
    std::vector<Transaction> transactions;

    // Helper function to trim leading/trailing spaces
    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t\n\r\f\v");
        size_t last = str.find_last_not_of(" \t\n\r\f\v");
        return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
    }

    // Load transactions from a CSV file
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

            // Trim and normalize location before adding it to transactions
            location = trim(location);
            transactions.emplace_back(id, timestamp, accountID, type, amount, currency, status, location);
        }

        file.close();
        std::cout << "Loaded " << transactions.size() << " transactions.\n";
    }

    // Filter transactions by city (location), trim and normalize both city and location
    std::vector<Transaction> filterTransactionsByCity(const std::string& city) {
        std::vector<Transaction> filtered;
        std::string normalizedCity = trim(city);  // Normalize the input city name

        for (const auto& transaction : transactions) {
            std::string normalizedLocation = trim(transaction.location);  // Normalize the location field

            if (normalizedLocation == normalizedCity) {
                filtered.push_back(transaction);
            }
        }

        // Debugging: Show the number of filtered transactions
        std::cout << "Found " << filtered.size() << " transactions for city: " << city << "\n";
        
        return filtered;
    }

    // Sort transactions by transaction amount in descending order
    void sortTransactionsByAmount(std::vector<Transaction>& filteredTransactions) {
        std::sort(filteredTransactions.begin(), filteredTransactions.end(), 
                  [](const Transaction& a, const Transaction& b) {
                      return a.amount > b.amount;  // Sort in descending order
                  });
    }

    // Group transactions by currency
    std::map<std::string, std::vector<Transaction>> groupTransactionsByCurrency(const std::vector<Transaction>& filteredTransactions) {
        std::map<std::string, std::vector<Transaction>> groupedByCurrency;

        for (const auto& transaction : filteredTransactions) {
            groupedByCurrency[transaction.currency].push_back(transaction);
        }

        return groupedByCurrency;
    }
};
