import csv
import random
import uuid
from datetime import datetime, timedelta

# Configuration for random data generation
NUM_TRANSACTIONS = 6_002_000
ACCOUNTS_RANGE = 20000  # Number of unique accounts
CURRENCIES = ['USD', 'EUR', 'GBP', 'JPY', 'AUD']
TRANSACTION_TYPES = ['Deposit', 'Withdrawal', 'Transfer', 'Payment']
STATUSES = ['Completed', 'Pending', 'Failed']
LOCATIONS = ['New York', 'London', 'Tokyo', 'Sydney', 'Berlin']

def generate_random_timestamp():
    """Generate a random timestamp within the past 5 years."""
    start_date = datetime.now() - timedelta(days=5*365)
    random_days = random.randint(0, 5*365)
    random_seconds = random.randint(0, 24*3600)
    return start_date + timedelta(days=random_days, seconds=random_seconds)

def generate_transaction():
    """Generate a single financial transaction record."""
    transaction_id = str(uuid.uuid4())
    timestamp = generate_random_timestamp().strftime('%Y-%m-%d %H:%M:%S')
    account_id = random.randint(1, ACCOUNTS_RANGE)
    transaction_type = random.choice(TRANSACTION_TYPES)
    amount = round(random.uniform(1, 5000), 2)  # Amount between 1 and 5000
    currency = random.choice(CURRENCIES)
    status = random.choice(STATUSES)
    location = random.choice(LOCATIONS)
    
    return [
        transaction_id, timestamp, account_id, transaction_type,
        amount, currency, status, location
    ]

# Generate and save transactions to a CSV file
with open('financial_transactions.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    # Write header
    writer.writerow([
        'TransactionID', 'Timestamp', 'AccountID', 'TransactionType', 
        'Amount', 'Currency', 'Status', 'Location'
    ])
    
    # Generate rows
    for _ in range(NUM_TRANSACTIONS):
        writer.writerow(generate_transaction())

print("Data generation complete: 'financial_transactions.csv' created with 1,000,000 transactions.")
