#include <iostream>
#include <vector>
#include <string>

enum class AccountType {
  kSavings,
  kChecking
};

struct Account {
  int number;
  double balance;
  AccountType type;
};

class Bank {
public:
  Bank() {}
  void CreateAccount(int number, AccountType type) {
    accounts_.push_back(Account{number, 0.0, type});
  }
  bool Deposit(int number, double amount) {
    for (Account& account : accounts_) {
      if (account.number == number) {
        account.balance += amount;
        return true;
      }
    }
    return false;
  }
  bool Withdraw(int number, double amount) {
    for (Account& account : accounts_) {
      if (account.number == number && account.balance >= amount) {
        account.balance -= amount;
        return true;
      }
    }
    return false;
  }
  double CheckBalance(int number) {
    for (const Account& account : accounts_) {
      if (account.number == number) {
        return account.balance;
      }
    }
    return -1;
  }
private:
  std::vector<Account> accounts_;
};

int main() {
  Bank bank;
  bank.CreateAccount(12345, AccountType::kSavings);
  bank.CreateAccount(67890, AccountType::kChecking);
  
  if (bank.Deposit(12345, 100.0)) {
    std::cout << "Deposit successful" << std::endl;
  } else {
    std::cout << "Deposit failed" << std::endl;
  }
  
  if (bank.Withdraw(12345, 50.0)) {
    std::cout << "Withdrawal successful" << std::endl;
  } else {
    std::cout << "Withdrawal failed" << std::endl;
  }
  
  std::cout << "Balance: " << bank.CheckBalance(12345) << std::endl;
  
  return 0;
}