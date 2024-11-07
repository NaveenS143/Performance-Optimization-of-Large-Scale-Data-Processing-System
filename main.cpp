#include <iostream>
#include "TransactionProcessor.h"

int main() {
    // Create an instance of TransactionProcessor
    TransactionProcessor processor;

    // Load transactions from CSV
    processor.loadTransactionsFromCSV("financial_transactions.csv");

    // Filter transactions for a specific city (e.g., "New York")
    std::string city = "New York";
    std::vector<Transaction> filteredTransactions = processor.filterTransactionsByCity(city);

    // Sort the filtered transactions by amount (in descending order)
    processor.sortTransactionsByAmount(filteredTransactions);

    // Group the sorted transactions by currency
    std::map<std::string, std::vector<Transaction>> groupedByCurrency = processor.groupTransactionsByCurrency(filteredTransactions);

    // Display the grouped and sorted transactions
    std::cout << "\nFinal grouped transactions by currency:\n";
    for (const auto& group : groupedByCurrency) {
        for (const auto& transaction : group.second) {
            std::cout << "Currency: " << group.first 
                      << ", ID: " << transaction.transactionID
                      << ", Amount: " << transaction.amount
                      << ", Status: " << transaction.status
                      << ", Location: " << transaction.location << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
