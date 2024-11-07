# Performance-Optimization-of-Large-Scale-Data-Processing-System

This project processes financial transactions simulated by a Python script that generates random data. It allows users to filter transactions based on a specific city, sort them by transaction amount, and group them by currency.

## Features

- **Generate Data**: Generates synthetic financial transaction data with customizable parameters.
- **Filter by City**: Filters transactions based on the city (location).
- **Sort by Amount**: Sorts transactions by the transaction amount in descending order.
- **Group by Currency**: Groups transactions by the currency used.
- **Data Output**: Outputs the results after filtering, sorting, and grouping.

## Project Overview

The project simulates the processing of financial transactions in a system, such as a banking or payment application. Each transaction includes details such as:

- Transaction ID
- Timestamp
- Account ID
- Transaction Type
- Amount
- Currency
- Status
- Location (City)

### Features Explained:

1. **Generate Data**: A Python script generates random transactions, creating synthetic data for testing the C++ transaction processor. You can specify the number of transactions and the cities to be included in the generated data.

2. **Filter Transactions by City**: You can filter transactions by city (location). This is useful for analyzing transactions specific to a region.
   
3. **Sort Transactions by Amount**: Once filtered by city, transactions can be sorted by amount in descending order. This helps to see the largest transactions first.

4. **Group Transactions by Currency**: After filtering and sorting, transactions are grouped by currency, which can be helpful in financial analysis to assess transactions in different currencies.

## Requirements

- **Python**: Used to generate synthetic financial data.
- **C++**: Used to process and analyze the generated transaction data.
- **C++17 or higher compiler**: For building and running the transaction processor.
- **Standard C++ library**: For file handling, data processing, etc.

## Setup

1. **Clone the repository**:
    ```bash
    git clone https://github.com/NaveenS143/Performance-Optimization-of-Large-Scale-Data-Processing-System.git
    cd Performance-Optimization-of-Large-Scale-Data-Processing-System
    ```

2. **Generate Data**:
    - Run the Python script to generate a CSV file of synthetic financial transactions.
    ```bash
    python data_generator.py
    ```

    This will create a `financial_transactions.csv` file in the repository with the specified number of transactions and cities.

3. **Compile the C++ project**:
   - Use `g++` or any C++ compiler to build the transaction processor.
    ```bash
    g++ main.cpp 
    ```

4. **Sample Output**:
    The program will output filtered, sorted, and grouped transaction data based on the given city.

    Example:
    ```
    Comparing city: new york with location: new york
    Comparing city: new york with location: london
    Found 10 transactions for city: New York
    Transactions for city: New York
    Currency: USD
    ID: 12345, Amount: 500.75, Status: completed, Location: New York
    ...
    ```

## How It Works

1. **Generate Data**: The `data_generator.py` Python script generates synthetic financial transactions. The generated data includes random transaction amounts, account IDs, locations, transaction types, and other details.

2. **Loading Transactions**: The `TransactionProcessor` class loads the generated financial transaction data from the CSV file into a vector of `Transaction` objects.

3. **Filtering**: The `filterTransactionsByCity` function filters transactions by city, using case-insensitive and whitespace-trimmed comparisons to ensure accurate filtering.

4. **Sorting**: The `sortTransactionsByAmount` function sorts the filtered transactions by transaction amount in descending order.

5. **Grouping**: The `groupTransactionsByCurrency` function groups transactions by their currency and outputs the results.

## Files Structure

- **data_generator.py**: Python script that generates synthetic transaction data in CSV format.
- **main.cpp**: Contains the entry point of the program and handles user interaction with the `TransactionProcessor`.
- **TransactionProcessor.h**: Implements the `TransactionProcessor` class, which handles reading, filtering, sorting, and grouping transactions.
- **Transaction.h**: Defines the `Transaction` class with the fields representing a transaction.
- **financial_transactions.csv**: The generated CSV file containing the transaction data (created by the Python script).

## Contributing

Feel free to fork this repository, open issues, or submit pull requests to contribute.
