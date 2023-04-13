    # Create a simple 'BankAccount' class:
    
    # Attributes: account_number, account_holder, balance
    # Methods: deposit(amount), withdraw(amount), display_balance()
    # Ensure that the balance does not go negative during withdrawals.

    # Create a 'BankAccount' class:
import datetime

class BankAccount:
    def __init__(self, account_number, account_holder, balance):
        self.account_number = account_number
        self.account_holder = account_holder
        self.balance = balance
        self.transaction_history = []

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
    def __init__(self, account_number, account_holder, balance, limit):
        super().__init__(account_number, account_holder, balance)
        self.limit = limit
        self.savings_account = None

    def withdraw(self, amount):
        if self.balance - amount < self.limit:
            print("You have reached your limit")
        else:
            self.balance -= amount
            self.transaction_history.append({"type": "withdraw", "amount": amount, "timestamp": datetime.datetime.now()})

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
    def __init__(self, account_number, account_holder, balance, interest_rate):
        super().__init__(account_number, account_holder, balance)
        self.interest_rate = interest_rate

    def calculate_interest(self):
        return self.balance * self.interest_rate

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
                print(f"Account Number: {account_number}, Account Holder: {account.account_holder}, Balance: {account.balance}")


def main():
    # Create a BankAccount instance
    account1 = BankAccount(123456, "John Doe", 1000)
    account1.deposit(500)
    account1.withdraw(200)
    account1.display_balance()
    account1.display_transaction_history()

    # Create a CheckingAccount instance
    account2 = CheckingAccount(234567, "Jane Doe", 2000, -500)
    account2.deposit(1000)
    account2.withdraw(3000)
    account2.display_balance()
    account2.display_transaction_history()

    # Create a SavingsAccount instance
    account3 = SavingsAccount(345678, "Jim Doe", 5000, 0.02)
    account3.deposit(2000)
    account3.withdraw(1000)
    account3.display_balance()
    account3.display_transaction_history()

    # Apply interest to the SavingsAccount
    account3.apply_interest()
    account3.display_balance()

    # Link savings account to checking account
    account2.link_savings_account(account3)

    # Attempt a withdrawal with overdraft protection
    account2.withdraw_with_overdraft_protection(4000)
    account2.display_balance()
    account2.display_transaction_history()
    account3.display_balance()
    account3.display_transaction_history()

if __name__ == "__main__":
    main()


