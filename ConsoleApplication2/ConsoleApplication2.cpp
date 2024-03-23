#include <iostream>

class BankAccount {
private:
    int accountNumber;  
    double balance;     
    double interestRate;  

public:
    
    BankAccount(int account_number, double initial_balance)
        : accountNumber(account_number), balance(initial_balance), interestRate(0.0) {}

   
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

 
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        else {
            return false;
        }
    }

    
    double getBalance() const {
        return balance;
    }

    
    double getInterest() const {
        return balance * interestRate * (1 / 12);
    }

    
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    
    int getAccountNumber() const {
        return accountNumber;
    }

    static bool transfer(BankAccount& account_from, BankAccount& account_to, double amount) {
        if (amount > 0 && amount <= account_from.getBalance()) {
            account_from.withdraw(amount);
            account_to.deposit(amount);
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
   
    BankAccount account1(1, 1000.0);
    BankAccount account2(2, 500.0);

    
    account1.deposit(200.0);

   
    bool success = BankAccount::transfer(account1, account2, 300.0);
    std::cout << "Transfer successful: " << std::boolalpha << success << std::endl;


    std::cout << "Account 1 balance: " << account1.getBalance() << std::endl;
    std::cout << "Account 2 balance: " << account2.getBalance() << std::endl;

    return 0;
}
