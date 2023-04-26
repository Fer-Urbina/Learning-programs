    # Create a simple 'BankAccount' class:
    
    # Attributes: account_number, account_holder, balance
    # Methods: deposit(amount), withdraw(amount), display_balance()
    # Ensure that the balance does not go negative during withdrawals.

    # Create a 'BankAccount' class:

from datetime import datetime, date
import random
import smtplib

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

    def send_notification(self, notification):
        print(f"Sending {notification.notification_type} to {self.first_name} {self.last_name}: {notification.message}")

    def generate_otp(self):
        otp = random.randint(100000, 999999)
        self.send_otp_email(otp)
        return otp
    
    def send_otp_email(self, otp):
        # Set up your email server and credentials
        server = smtplib.SMTP("smtp.gmail.com", 587)
        server.starttls()
        server.login("feub122001@gmail.com", "ypyvodsibfzoqkjg")

        # Compose the email
        subject = "Your OTP for secure Banking"
        body = f"Your one-time passcode (OTP) for secure banking is {otp}."
        message = f"Subject: {subject}\n\n{body}"

        # Send the email
        server.sendmail("feub122001@gmail.com", self.email, message)
        server.quit()

def require_otp(func):
        def wrapper(*args, **kwargs):
            customer = args[0].customers[0] # Assuming the first customer initiated
            otp = customer.generate_otp()
            input_otp = int(input("Please enter the OTP sent to your email: "))
            if input_otp == otp:
                return func(*args, **kwargs)
            else:
                print("Incorrect OTP, The action has been cancelled.")
        return wrapper 
    # Eventually, I need to make sure that the OTP is only sent once, if it fails, it does not need to be sent again

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
        self.transactions = []
        self.transaction_history = []
        self.recurring_transactions = []
        self.daily_transaction_limits = {"withdraw": 1000, "transfer": 5000}

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
                                            "timestamp": datetime.now(), "description": transaction.description})

    def deposit(self, amount, description=''):
        self.balance += amount
        self.transaction_history.append({
            "type": "deposit",
            "amount": amount, 
            "timestamp": datetime.now(), 
            "description": f'Deposit: ${amount}'
            })
        
    def check_daily_limtit(self, transaction_type, amount):
        daily_transaction = [t for t in self.transaction_history if t['type'] == transaction_type and t['timestamp'].date() == date.today()]
        daily_total = sum(t['amount'] for t in daily_transaction)
        if daily_total + amount > self.daily_transaction_limits[transaction_type]:
            return False
        return True

    def withdraw(self, amount):
        if not self.check_daily_limtit('withdraw', amount):
            print("Daily withdrawal limit reached.")
            return False
        if amount > self.balance:
            print("Insufficient funds")
            return False
        self.balance -= amount
        self.transaction_history.append({
            "type": "withdraw",
            "amount": amount,
            "timestamp": datetime.now(),
            "description": f'Withdraw: ${amount}'
        })

        if amount >= 500: # You can set your own threshold for a large withdrawal
            for customer in self.customers:
                notification = Notification(f"A large withdrawal of ${amount} has been made from Account {self.account_number}.", "email")
                customer.send_notification(notification)
        return True

    @require_otp
    def transfer(self, to_account, amount, bank=None):
        if not self.check_daily_limtit('transfer', amount):
            print("Daily transfer limit reached.")
            return False
        # Check if the to_account exists in the external bank (if provided)
        if bank is not None and not bank.has_account(to_account.account_number):
            print(f"Transfer failed. Account {to_account.account_number} not found in the destination bank")
            return False
        
        if self.withdraw(amount):
            to_account.deposit(amount)
            self.transaction_history.append({
                "type": "transfer",
                "amount": amount,
                "timestamp": datetime.now(),
                "description": f'Transfer: ${amount} to Account {to_account.account_number}'
            })
            if amount >= 500:
                for customer in self.customers:
                    notification = Notification(f"A large transfer of ${amount} has been made from Account {self.account_number} to Account {to_account.account_number}.", "email")
                    customer.send_notification(notification)

            # Check for low balance
            if self.balance < 200:
                for customer in self.customers:
                    notification = Notification(f"Your balance in Account {self.account_number} has falled below $200 after a transfer.", "email")
                    customer.send_notification(notification)

            return True
        else:
            print("Transfer failed.")
            return False
    
    def display_balance(self):
        print(f"Account Number: {self.account_number}, Balance: ${self.balance}.")

    def display_transaction_history(self):
        print(f"Transaction History for Account {self.account_number}:")
        for transaction in self.transaction_history:
            print(f"{transaction['timestamp']} - {transaction['description']}: ${transaction['amount']}")

    #Currently getting errors with this method (PLEASE REVIEW ASAP)
    
    def generate_statement(self): 
        print(f"Bank Account Statement for Account {self.account_number}")
        print("Transactions:")
        for transaction in self.transaction_history:
            print(f"{transaction['timestamp']} - {transaction['description']}: ${transaction['amount']}")

class CheckingAccount(BankAccount):
    def __init__(self, account_number, customers, balance, limit, monthly_fee, overdraft_fee):
        super().__init__(account_number, customers, balance)
        self.limit = limit
        self.monthly_fee = monthly_fee
        self.overdraft_fee_amount = overdraft_fee
        self.savings_account = None

    def withdraw(self, amount):
        if self.balance - amount < self.limit:
            print("You have reached your limit")
        else:
            self.balance -= amount
            self.transaction_history.append({
                "type": "withdraw",
                "amount": amount,
                "timestamp": datetime.now(),
                "description": f'Withdraw: ${amount}'
                })
            self.charge_overdraft_fee()

    def apply_monthly_fee(self):
        self.balance -= self.monthly_fee
        self.transaction_history.append({
            "type": "monthly_fee",
            "amount": self.monthly_fee,
            "timestamp": datetime.now(),
            "description": f'Monthly fee: ${self.monthly_fee}'
            })

    def charge_overdraft_fee(self):
        if self.balance < 0:
            self.balance -= self.overdraft_fee_amount
            self.transaction_history.append({
                "type": "overdraft_fee",
                "amount": self.overdraft_fee_amount,
                "timestamp": datetime.now(),
                "description": f'Overdraft fee: ${self.overdraft_fee_amount}'
                })

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

    def generate_statement(self):
        super().generate_statement()
        print(f"Total monthly fees: ${self.monthly_fee}")

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

    def generate_statement(self):
        super().generate_statement()
        print(f"Total interest eraned: ${self.calculate_interest()}")


class Bank:
    def __init__(self, name, address, branches=None):
        self.name = name
        self.address = address
        self.branches = branches if branches is not None else []
        self.accounts = {}

    def add_branch(self, branch):
        self.branches.append(branch)

    def remove_branch(self, branch_id):
        self.branches = [branch for branch in self.branches if branch.branch_id != branch_id]

    def display_branches(self):
        print(f"Bank: {self.name}")
        for branch in self.branches:
            branch.display_branch_details()

    def add_account(self, account):
        if account.account_number in self.accounts:
            print("Account already exists in the bank.")
        else:
            self.accounts[account.account_number] = account
            print(f"Account {account.account_number} added successfully.")

    def has_account(self, account_number):
            return account_number in self.accounts
    
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

    def get_account(self, account_number):
        for account in self.accounts:
            if account.acount_number == account_number:
                return account
        return None

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
    def __init__(self, employee_id, first_name, last_name, branch):
        super().__init__(employee_id, first_name, last_name, "Manager")
        self.branch = branch

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
        balance = account.get_balance()
        account_type = type(account).__name__

        if balance < 0:
            print(f"The {account_type} account {account.account_number} has a negative balance of ${-balance}. Please investigate")
        elif balance < 1000:
            print(f"The {account_type} account {account.account_number} has a low balance of ${balance}. Please review.")
        else:
            print(f"The {account_type} account {account.account_number} has a healthy balance of ${balance}. No action required.")


    def hire_employee(self, employee):
        self.branch.add_employee(employee)
        print(f"Employee {employee.first_name} {employee.last_name} (ID: {employee.employee_id}) has been hired.")

    def fire_employee(self, employee):
        # Remove the employee from the branch's employee list
        self.branch.remove_employee(employee.employee_id)
        
        # Display a message indicating the employee has been fired
        print(f"Employee {employee.first_name} {employee.last_name} (ID: {employee.employee_id}) has been fired.")

class Branch:
    def __init__(self, branch_id, address, phone_number, employees=None):
        self.branch_id = branch_id
        self.address = address
        self.phone_number = phone_number
        self.employees = employees if employees is not None else []

    def add_employees(self, employee):
        self.employees.append(employee)

    def remove_employee(self, employee_id):
        self.employees = [employee for employee in self.employees if employee.employee_id != employee_id]

    def display_employee(self):
        for employee in self.employees:
            employee.display_employee_details()

    def display_branch_details(self):
        print(f"Branch ID: {self.branch_id}, Adress: {self.address}, Phone Number: {self.phone_number}")

class ATM:
    def __init__(self, atm_id, bank, balance):
        self.atm_id = atm_id
        self.bank = bank
        self.balance = balance

    def withdraw_cash(self, account_number, amount):
        account = self.bank.get_account(account_number)
        if account is not None:
            if account.withdraw(amount):
                if self.balance >= amount:
                    self.balance -= amount
                    print(f"Withdrawal successful! Depending ${amount}.")
                    return True
                else:
                    print("ATM has inssufficient cash for this withdrawal.")
                    return False
            else:
                print("Withdrawal unsuccessful. Please check your account balance and try again.")
                return False
        else:
            print("Account not found.")
            return False
        
    def check_balance(self, account_number):
        account = self.bank.get_account(account_number)
        if account is not None:
            print(f"Account balance: ${account.balance}")
        else:
            print("Account not found.")

    def deposit_cash(self, account_number, amount):
        account = self.bank.get_account(account_number)
        if account is not None:
            account.deposit(amount)
            print(f"Deposit successful! ${amount} has been added to your account.")
        else:
            print("Account not found.")
    
    def transfer_funds(self, from_account_number, to_account_number, amount):
        from_account = self.bank.get_account(from_account_number)
        to_account = self.bank.get_account(to_account_number)

        if from_account is not None and to_account is not None:
            if from_account.withdraw(amount):
                to_account.deposit(amount)
                print(f"Transfer successful! ${amount} has been transferred from account {from_account_number} to account {to_account_number}.")
            else:
                print("Transfer unsuccessful. Please check your account balance and try again.")
        else:
            print("One or both account numbers not found.")

    def print_transaction_history(self, account_number):
        account = self.bank.get_account(account_number)
        if account is not None:
            account.display_transaction_history()
        else:
            print("Account not found.")

class Notification:
    def __init__(self, message, notification_type):
        self.message = message
        self.notification_type = notification_type

             

# Testing all classes and their methods in the following main function:

def main():
        # [PART 1] Create Customer instances
    # Create Customer instances
    customer1 = Customer(1, "Fidel", "Urbina", "1990-01-01", "123 Main St", "8683-6896", "fidel.urbina@gmail.com", 750)
    customer2 = Customer(2, "Jasmina", "Bonilla", "1991-02-02", "123 Main St", "8393-9852", "jasmina.bonilla@hotmail.com", 700)
    customer3 = Customer(3, "James", "Urbina", "2019-10-28", "Healieah, Managua", "8481-9788", "james.urbina@gmail.com", 800)
    customer4 = Customer(4, "Greyshell", "Vega", "1980-11-25", "Acahualinca, Managua", "8685-6503", "greyshell.vega@outlook.com", 850)
    customer5 = Customer(5, "Olivia", "Taylor", "1980-11-30", "222 Main St", "8883-6803", "olivia.taylor@outlook.com", 820)
    customer6 = Customer(6, "Lucas", "Garcia", "1995-08-25", "333 Main St", "7773-6904", "lucas.garcia@gmail.com", 840)

    interest_rate_tiers = {
        0: 0.01,      # 1% interest for balances between $0 and $999.99
        1000: 0.015,  # 1.5% interest for balances between $1000 and $4999.99
        5000: 0.02    # 2% interest for balances of $5000 or more
    }

        # [PART 2] Create LoanAccount instances
    # Create a LoanAccount instance
    loan_account = LoanAccount(3001, [customer1, customer2], 100000, 0.05, 30) # loan_amount = 100000, interest_rate = 5% (0.05), loan_term = 30 years
    loan_account = LoanAccount(3002, [customer3, customer4], 5000, 0.04, 2) # loan_amount = 5000, interest_rate 4% (0.04), loan_term = 2 years

        # [PART 3] Create Branch instances
    #Create branches
    branch1 = Branch(1, "456 Market St", "123-456-7890")
    branch2 = Branch(2, "789 Main St", "987-654-3210")

        # [PART 4] Create Manager instance
    # Create a Manager instance
    manager = Manager(101, "Fernando", "Urbina", branch1)

        # [PART 5] Create BankAccount instances
    # Display loan details before approval
    print("\nLoan details before approval:")
    loan_account.display_loan_details()

    # Approve the loan
    manager.approve_loan(loan_account)

    # Create joint BankAccount instances
    joint_account1 = BankAccount(2001, [customer1, customer2, customer3, customer4], 1000)
    joint_checking_account1 = CheckingAccount(2002, [customer1, customer2, customer3, customer4], 2000, -500, 10, 35)
    joint_savings_account1 = SavingsAccount(2003, [customer1, customer2, customer3, customer4], 3000, interest_rate_tiers)  # Pass the interest_rate_tiers dictionary

    # Add some transactions to the accounts
    joint_checking_account1.deposit(500)
    joint_checking_account1.withdraw(200)
    joint_savings_account1.deposit(1000)

    # Generate statements for both accounts
    joint_checking_account1.generate_statement()
    joint_savings_account1.generate_statement()

    # Create a direct deposit recurring transaction
    direct_deposit = RecurringTransaction("deposit", 2000, "Direct deposit")

    # Add the direct deposit to the joint_acount1
    joint_account1.add_recurring_transactions(direct_deposit)

    #Apply all recurring transactions for the joint_account1
    joint_account1.apply_recurring_transactions()

        # [PART 6] Create Bank instance
    # Create a Bank instance
    my_bank = Bank("Fernando's Bank", "456 Market St")
    another_bank = Bank("Another Bank","789 Main St")

    # Creation of accounts for the new bank (another_bank)
    account_in_another_bank = BankAccount(5001, [customer5, customer6], 1000)

    another_bank.add_account(account_in_another_bank)

    # Test transfers between different banks
    print("\nTesting transfers within the same bank:")
    joint_checking_account1.transfer(account_in_another_bank, 300, another_bank)
    joint_checking_account1.display_balance()
    joint_savings_account1.display_balance()

    # Test transfers between different banks
    print("\nTesting transfers between different banks:")
    joint_account1.transfer(account_in_another_bank, 300, another_bank)
    joint_account1.display_balance()
    account_in_another_bank.display_balance()

    # Add accounts to the bank
    my_bank.add_account(joint_account1)
    my_bank.add_account(joint_checking_account1)
    my_bank.add_account(joint_savings_account1)
    my_bank.add_branch(branch1)
    my_bank.add_branch(branch2)

    # Display accounts in the bank
    my_bank.display_accounts()

    # Display branches
    my_bank.display_branches()

        # [PART 7] Test Customer methods
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

        # [PART 8] Test RecurringTransaction
    # Test RecurringTransaction
    print("\nTesting RecurringTransaction:")
    print(f"Recurring transaction type: {direct_deposit.transaction_type}, amount: {direct_deposit.amount}, description: {direct_deposit.description}")

        # [PART 9] Test BankAccount methods
    # Test BankAccount methods
    print("\nTesting BankAccount methods:")
    joint_account1.deposit(500)
    joint_account1.withdraw(250)
    joint_account1.display_balance()
    joint_account1.display_transaction_history()

        # [PART 10] Test CheckingAccount methods
    # Test CheckingAccount methods
    print("\nTesting CheckingAccount methods:")
    joint_checking_account1.withdraw(100)
    joint_checking_account1.apply_monthly_fee()
    joint_checking_account1.charge_overdraft_fee()
    joint_checking_account1.display_balance()
    joint_checking_account1.display_transaction_history()

        # [PART 11] Test SavingsAccount methods
    # Test SavingsAccount methods
    print("\nTesting SavingsAccount methods:")
    joint_savings_account1.deposit(1000)
    joint_savings_account1.withdraw(500)
    joint_savings_account1.apply_interest()
    joint_savings_account1.display_balance()
    joint_savings_account1.display_transaction_history()

        # [PART 12] Test LoanAccount methods
    # Test LoanAccount methods
    print("\nTesting LoanAccount methods:")
    loan_account.display_loan_details()
    loan_account.make_payment(5000)
    loan_account.display_loan_details()

        # [PART 13] Test Bank methods   
    # Test Bank methods
    print("\nTesting Bank methods:")
    my_bank.display_accounts()
    my_bank.remove_account(joint_account1.account_number)
    my_bank.display_accounts()
    my_bank.add_account(joint_account1)
    my_bank.display_accounts()

        # [PART 14] Test daily transaction limits
    # Test daily transaction limits
    print("\nTesting daily transaction limits:")

    # Create some BankAccount instances for testing
    alice = Customer("C001", "Alice", "Smith", "1990-01-01", "123 Main St", "555-123-4567", "alice.smith@gmail.com", 700)
    bob = Customer("C002", "Bob", "Johnson", "1985-10-04", "146 Ave Ln", "123-654-8760", "bob.Johnson@gmail.com", 800)

    alice_account = BankAccount(4001, [alice], 3000)
    bob_account = BankAccount(4002, [bob], 5000)

    # Test daily withdrawal limit
    print("Testing daily withdrawal limit:")
    alice_account.withdraw(500) # Should be successful
    alice_account.withdraw(600) # Should fail, as it exceeds the daily limit
    alice_account.display_balance()

    # Test daily transfer limit
    print("Testing daily transfer limit:")
    alice_account.transfer(bob_account, 4000) # Should fail, as it exceeds the daily limit
    alice_account.transfer(bob_account, 3000) # Should be successful
    alice_account.display_balance()
    bob_account.display_balance()

if __name__ == "__main__":
    main()


