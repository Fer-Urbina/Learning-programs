    # Create a simple 'BankAccount' class:
    
    # Attributes: account_number, account_holder, balance
    # Methods: deposit(amount), withdraw(amount), display_balance()
    # Ensure that the balance does not go negative during withdrawals.

    # Create a 'BankAccount' class:

import datetime

class Customer:
    def __init__(self, customer_id, first_name, last_name, date_of_birth, address, phone_number, email, credit_score):
        self.customer_id = customer_id
        self.first_name = first_name
        self.last_name = last_name
        self.date_of_birth = date_of_birth
        self.address = address
        self.phone_number = phone_number
        self.email = email
        self.credit_score = credit_score

    def update_address(self, update_address):
        self.address = update_address

    def update_phone_number(self, new_update_number):
        self.phone_number = new_update_number

    def update_email(self, new_email):
        self.email = new_email

    def display_customer_details(self):
        print(f"Customer ID: {self.customer_id}")
        print(f"Name: {self.first_name} {self.last_name}")
        print(f"Date of birth: {self.date_of_birth}")
        print(f"Address: {self.address}")
        print(f"Phone Number: {self.phone_number}")
        print(f"Email: {self.email}")

class RecurringTransaction():
    def __init__(self, transaction_type, amount, description):
        self.transaction_type = transaction_type
        self.amount = amount
        self.description = description 

class BankAccount:
    def __init__(self, account_number, customers, balance):
        self.account_number = account_number
        self.customers = customers
        self.balance = balance
        self.transaction_history = []
        self.recurring_transactions = []

    def add_recurring_transactions(self, recurring_transactions):
        self.recurring_transactions.append(recurring_transactions)

    def remove_recurring_transactions(self, recurring_transactions):
        if recurring_transactions in self.recurring_transactions:
            self.recurring_transactions.remove(recurring_transactions)
        else:
            print("Recurring transaction not found.")

    def apply_recurring_transactions(self):
        for transaction in self.recurring_transactions:
            if transaction.transaction_type == "deposit":
                self.deposit(transaction.amount)
            elif transaction.transaction_type == "withdraw":
                self.withdraw(transaction.amount)
            self.transaction_history.append({"type": transaction.transaction_type, "amount": transaction.amount,
                                            "timestamp": datetime.datetime.now(), "description": transaction.description})

    def deposit(self, amount):
        self.balance += amount
        self.transaction_history.append({"type": "deposit", "amount": amount, "timestamp": datetime.datetime.now()})

    def withdraw(self, amount):
        if self.balance - amount < 0:
            print("Insufficient funds")
        else:
            self.balance -= amount
            self.transaction_history.append({"type": "withdraw", "amount": amount, "timestamp": datetime.datetime.now()})

    def display_balance(self):
        print(f"Balance: {self.balance}")

    def display_transaction_history(self):
        print("Transaction History:")
        for transaction in self.transaction_history:
            print(f"{transaction['type'].capitalize()}: {transaction['amount']} on {transaction['timestamp']}")

class CheckingAccount(BankAccount):
    def __init__(self, account_number, customers, balance, limit, monthly_fee, overdraft_fee):
        super().__init__(account_number, customers, balance)
        self.limit = limit
        self.monthly_fee = monthly_fee
        self.overdraft_fee = overdraft_fee
        self.savings_account = None

    def withdraw(self, amount):
        if self.balance - amount < self.limit:
            print("You have reached your limit")
        else:
            self.balance -= amount
            self.apply_overdraft_fee()
        self.transaction_history.append({"type": "withdraw", "amount": amount, "timestamp": datetime.datetime.now()})

    def apply_monthly_fee(self):
        self.balance -= self.monthly_fee
        self.transaction_history.append({"type": "monthly_fee", "amount": self.monthly_fee, "timestamp": datetime.datetime.now()})

    def apply_overdraft_fee(self):
        self.balance -= self.overdraft_fee
        self.transaction_history.append({"type": "monthly_fee", "amount": self.overdraft_fee, "timestamp": datetime.datetime.now()})

    def link_savings_account(self, savings_account):
        self.savings_account = savings_account

    def withdraw_with_overdraft_protection(self, amount):
        if self.balance - amount >= self.limit:
            self.withdraw(amount)
        elif self.savings_account is not None and self.savings_account.balance + self.balance - amount >= 0:
            amount_to_withdraw_from_savings = amount - self.balance
            self.withdraw(self.balance)
            self.savings_account.withdraw(amount_to_withdraw_from_savings)
        else:
            print("Insufficient funds")

class SavingsAccount(BankAccount):
    def __init__(self, account_number, customers, balance, interest_rate_tier):
        super().__init__(account_number, customers, balance)
        self.interest_rate_tier = interest_rate_tier # Dictionary of balance thresholds and corresponding interest rates

    def calculate_interest(self):
        applicable_interest_rate = 0
        for threshold, rate in sorted(self.interest_rate_tier.items(), reverse=True):
            if self.balance >= threshold:
                applicable_interest_rate = rate
                break
        return self.balance * applicable_interest_rate

    def apply_interest(self):
        interest = self.calculate_interest()
        self.deposit(interest)


class Bank:
    def __init__(self, name, address):
        self.name = name
        self.address = address
        self.accounts = {}
    def add_account(self, account):
        if account.account_number in self.accounts:
            print("Account already exists in the bank.")
        else:
            self.accounts[account.account_number] = account
            print(f"Account {account.account_number} added successfully.")
    def remove_account(self, account_number):
        if account_number in self.accounts:
            del self.accounts[account_number]
            print(f"Account {account_number} removed successfully.")
        else:
            print("Account not found.")
    def get_account(self, account_number):
        return self.accounts.get(account_number, None)
    
    def display_accounts(self):
        print(f"Accounts in {self.name}:")
        for account_number, account in self.accounts.items():
            account_holders = ", ".join([f"{customer.first_name} {customer.last_name}" for customer in account.customers])
            print(f"Account Number: {account_number}, Account Holder: {account_holders}, Balance: {account.balance}")

class LoanAccount():
    def __init__(self, account_number, customers, loan_amount, interest_rate, loan_term):
        self.account_number = account_number
        self.customers = customers
        self.loan_amount = loan_amount
        self.interest_rate = interest_rate
        self.loan_term = loan_term
        self.outstanding_balance = loan_amount
        self.loan_approved = False
        self.monthly_payment = self.calculate_monthly_payment()

        # formula to calculate the monthly payment for a loan:

        # M = P * r * (1 + r)^n / ((1 + r)^n - 1)
        # Where:
        # M is the monthly payment
        # P is the loan amount (principal)
        # r is the monthly interest rate (annual interest rate divided by 12)
        # n is the total number of payments (loan term in months)

    def calculate_monthly_payment(self):
        # Convert the annual interest rate to a monthly interest rate
        monthly_interest_rate = self.interest_rate / 12

        # Calculate the total number of payments
        total_payments = self.loan_term * 12

        # Calculate the monthly payment using the formula
        monthly_payment = self.loan_amount * monthly_interest_rate * (1 + monthly_interest_rate)**total_payments / ((1 + monthly_interest_rate)**total_payments - 1)

        return monthly_payment

    def make_payment(self, payment_amount):
        if payment_amount > 0:
            self.outstanding_balance -= payment_amount
            print(f"Payment of {payment_amount} made. Outstanding balance: {self.outstanding_balance}")
        else:
            print("Payment amount should be greater than 0.")

    def display_loan_details(self):
        account_holders = ", ".join([f"{customer.first_name} {customer.last_name}" for customer in self.customers])
        print(f"Account Number: {self.account_number}")
        print(f"Account Holders: {account_holders}")
        print(f"Loan Amount {self.loan_amount}")
        print(f"Interest Rate: {self.interest_rate * 100}%")
        print(f"Loan Term {self.loan_term} years")
        print(f"Monthly Payment: {self.monthly_payment}")
        print(f"Outstanding Balance: {self.outstanding_balance}")

class PersonalLoan(LoanAccount):
    def __init__(self, account_number, customers, loan_amount, interest_interest, loan_term):
        super().__init__(account_number, customers, loan_amount, interest_interest, loan_term)

class MortgageLoan(LoanAccount):
    def __init__(self, account_number, customers, loan_amount, interest_rate, loan_term, property_address):
        super().__init__(self, account_number, customers, loan_amount, interest_rate, loan_term)
        self.property_address = property_address

    def display_loan_details(self):
        super().display_loan_details()
        print(f"Property Address: {self.property_address}")

class Empployee:
    def __init__(self, employee_id, first_name, last_name, title):
        self.employee_id = employee_id
        self.first_name = first_name
        self.last_name = last_name
        self.title = title

    def display_employee_details(self):
        print(f"Employee ID: {self.employee_id}")
        print(f"Name: {self.first_name} {self.last_name}")
        print(f"Title: {self.title}")

class Teller(Empployee):
    def __init__(self, employee_id, first_name, last_name):
        super().__init__(employee_id, first_name, last_name, "Teller")

    def open_account(self, bank, account):
        bank.remove_account(account)
        print(f"Teller {self.first_name} {self.last_name} has opened account {account.account_number} for {', '.join([customer.first_name + ' ' + customer.last_name for customer in account.customers])}.")

    def close_account(self, bank, account_number):
        bank.remove_account(account_number)
        print(f"Teller {self.first_name} {self.last_name} has closed account {account_number}.")

class Manager(Empployee):
    def __init__(self, employee_id, first_name, last_name):
        super().__init__(employee_id, first_name, last_name, "Manager")

    def approve_loan(self, loan_account):
        # Check if all customers have a credit score of 700 or higher
        all_customers_approved = all(customer.credit_score >= 700 for customer in loan_account.customers)

        if all_customers_approved:
            loan_account.loan_approved = True
            print("Loan approved.")
        else:
            loan_account.loan_approved = False
            print("Loan not approved.")

    def review_account(self, account):
        # Implement a method to review an account
        pass

    def hire_employee(self, employee):
        # Implement a method to hire a new employee
        pass

    def fire_employee(self, employee):
        # Implement a method to approve a loan
        pass

import datetime

# Testing all classes and their methods in the following main function:

def main():
    # Create Customer instances
    customer1 = Customer(1, "Fidel", "Urbina", "1990-01-01", "123 Main St", "8683-6896", "fidel.urbina@gmail.com", 750)
    customer2 = Customer(2, "Jasmina", "Bonilla", "1991-02-02", "123 Main St", "8393-9852", "jasmina.bonilla@hotmail.com", 700)
    customer3 = Customer(3, "James", "Urbina", "2019-10-28", "Healieah, Managua", "8481-9788", "james.urbina@gmail.com", 800)
    customer4 = Customer(4, "Greyshell", "Vega", "1980-11-25", "Acahualinca, Managua", "8685-6503", "greyshell.vega@outlook.com", 850)

    interest_rate_tiers = {
        0: 0.01,      # 1% interest for balances between $0 and $999.99
        1000: 0.015,  # 1.5% interest for balances between $1000 and $4999.99
        5000: 0.02    # 2% interest for balances of $5000 or more
    }

    # Create a LoanAccount instance
    loan_account = LoanAccount(3001, [customer1, customer2], 100000, 0.05, 30) # loan_amount = 100000, interest_rate = 5% (0.05), loan_term = 30 years
    loan_account = LoanAccount(3002, [customer3, customer4], 5000, 0.04, 2) # loan_amount = 5000, interest_rate 4% (0.04), loan_term = 2 years

    # Create a Manager instance
    manager = Manager(101, "Alice", "Smith")

    # Display loan details before approval
    print("\nLoan details before approval:")
    loan_account.display_loan_details()

    # Approve the loan
    manager.approve_loan(loan_account)

    # Display loan details
    print("\nLoan account details:")
    loan_account.display_loan_details()

    # Create joint BankAccount instances
    joint_account1 = BankAccount(2001, [customer1, customer2, customer3, customer4], 1000)
    joint_checking_account1 = CheckingAccount(2002, [customer1, customer2, customer3, customer4], 2000, -500, 10, 35)
    joint_savings_account1 = SavingsAccount(2003, [customer1, customer2, customer3, customer4], 3000, interest_rate_tiers)  # Pass the interest_rate_tiers dictionary

    # Create a direct deposit recurring transaction
    direct_deposit = RecurringTransaction("deposit", 2000, "Direct deposit")

    # Add the direct deposit to the joint_acount1
    joint_account1.add_recurring_transactions(direct_deposit)

    #Apply all recurring transactions for the joint_account1
    joint_account1.apply_recurring_transactions()

    # Create a Bank instance
    my_bank = Bank("Fernando's Bank", "456 Market St")

    # Add accounts to the bank
    my_bank.add_account(joint_account1)
    my_bank.add_account(joint_checking_account1)
    my_bank.add_account(joint_savings_account1)

    # Display accounts in the bank
    my_bank.display_accounts()

    # Test Customer methods
    print("\nTesting Customer methods:")
    customer1.display_customer_details()
    customer1.update_address("456 New St")
    customer1.update_phone_number("8683-6896")
    customer1.update_email("fidel.urbina@gmail.com")
    customer2.display_customer_details()
    customer2.update_address("Healiah")
    customer2.update_phone_number("8888-0202")
    customer2.update_email("jasmina.bonilla@ios.com")

    # Test RecurringTransaction
    print("\nTesting RecurringTransaction:")
    print(f"Recurring transaction type: {direct_deposit.transaction_type}, amount: {direct_deposit.amount}, description: {direct_deposit.description}")

    # Test BankAccount methods
    print("\nTesting BankAccount methods:")
    joint_account1.deposit(500)
    joint_account1.withdraw(250)
    joint_account1.display_balance()
    joint_account1.display_transaction_history()

    # Test CheckingAccount methods
    print("\nTesting CheckingAccount methods:")
    joint_checking_account1.withdraw(100)
    joint_checking_account1.apply_monthly_fee()
    joint_checking_account1.apply_overdraft_fee()
    joint_checking_account1.display_balance()
    joint_checking_account1.display_transaction_history()

    # Test SavingsAccount methods
    print("\nTesting SavingsAccount methods:")
    joint_savings_account1.deposit(1000)
    joint_savings_account1.withdraw(500)
    joint_savings_account1.apply_interest()
    joint_savings_account1.display_balance()
    joint_savings_account1.display_transaction_history()

    # Test LoanAccount methods
    print("\nTesting LoanAccount methods:")
    loan_account.display_loan_details()
    loan_account.make_payment(5000)
    loan_account.display_loan_details()

    # Test Bank methods
    print("\nTesting Bank methods:")
    my_bank.display_accounts()
    my_bank.remove_account(joint_account1.account_number)
    my_bank.display_accounts()
    my_bank.add_account(joint_account1)
    my_bank.display_accounts()

if __name__ == "__main__":
    main()


