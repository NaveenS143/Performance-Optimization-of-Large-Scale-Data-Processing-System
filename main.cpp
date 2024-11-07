// main.cpp
#include <iostream>
#include "TransactionProcessor.h"




int main() {
    TransactionProcessor processor;

    // Load transactions from CSV
    processor.loadTransactionsFromCSV("financial_transactions.csv");

    // Aggregate amount for "Deposit" transactions
    double totalDeposits = processor.aggregateAmountByType(processor.transactions, "Deposit");
    std::cout << "Total amount for deposits: " << totalDeposits << "\n";

    // Filter transactions with status "Completed"
    auto completedTransactions = processor.filterTransactionsByStatus(processor.transactions, "Completed");
    std::cout << "Number of completed transactions: " << completedTransactions.size() << "\n";

    return 0;
}
