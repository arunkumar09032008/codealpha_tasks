#ifndef BANKING_SYSTEM_HPP
#define BANKING_SYSTEM_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>

struct Transaction {
    std::string transactionId;
    std::string accountNumber;
    std::string type; // "DEPOSIT", "WITHDRAWAL", "TRANSFER_OUT", "TRANSFER_IN"
    double amount;
    std::string timestamp;
    std::string details;

    Transaction() : amount(0.0) {}
    Transaction(std::string id, std::string accNum, std::string t, double amt, std::string timeStr, std::string det)
        : transactionId(id), accountNumber(accNum), type(t), amount(amt), timestamp(timeStr), details(det) {}

    std::string toString() const {
        std::stringstream ss;
        ss << transactionId << "|" << accountNumber << "|" << type << "|" << amount << "|" << timestamp << "|" << details;
        return ss.str();
    }

    static Transaction fromString(const std::string& line) {
        std::stringstream ss(line);
        std::string id, accNum, t, amtStr, timeStr, det;
        std::getline(ss, id, '|');
        std::getline(ss, accNum, '|');
        std::getline(ss, t, '|');
        std::getline(ss, amtStr, '|');
        std::getline(ss, timeStr, '|');
        std::getline(ss, det, '|');
        double amt = amtStr.empty() ? 0.0 : std::stod(amtStr);
        return Transaction(id, accNum, t, amt, timeStr, det);
    }
};

class Customer {
private:
    std::string customerId;
    std::string name;
    std::string email;
    std::string phone;

public:
    Customer() {}
    Customer(std::string id, std::string n, std::string e, std::string p)
        : customerId(id), name(n), email(e), phone(p) {}

    std::string getCustomerId() const { return customerId; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getPhone() const { return phone; }

    std::string toString() const {
        return customerId + "|" + name + "|" + email + "|" + phone;
    }

    static Customer fromString(const std::string& line) {
        std::stringstream ss(line);
        std::string id, n, e, p;
        std::getline(ss, id, '|');
        std::getline(ss, n, '|');
        std::getline(ss, e, '|');
        std::getline(ss, p, '|');
        return Customer(id, n, e, p);
    }
};

class Account {
private:
    std::string accountNumber;
    std::string customerId;
    double balance;
    std::string accountType; // "Savings", "Checking"

public:
    Account() : balance(0.0) {}
    Account(std::string accNum, std::string custId, double initialBal, std::string type = "Savings")
        : accountNumber(accNum), customerId(custId), balance(initialBal), accountType(type) {}

    std::string getAccountNumber() const { return accountNumber; }
    std::string getCustomerId() const { return customerId; }
    double getBalance() const { return balance; }
    std::string getAccountType() const { return accountType; }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << accountNumber << "|" << customerId << "|" << balance << "|" << accountType;
        return ss.str();
    }

    static Account fromString(const std::string& line) {
        std::stringstream ss(line);
        std::string accNum, custId, balStr, type;
        std::getline(ss, accNum, '|');
        std::getline(ss, custId, '|');
        std::getline(ss, balStr, '|');
        std::getline(ss, type, '|');
        double bal = balStr.empty() ? 0.0 : std::stod(balStr);
        return Account(accNum, custId, bal, type);
    }
};

class BankingSystem {
private:
    std::vector<Customer> customers;
    std::vector<Account> accounts;
    std::vector<Transaction> transactions;

    std::string customersFile = "data/customers.txt";
    std::string accountsFile = "data/accounts.txt";
    std::string transactionsFile = "data/transactions.txt";

    static std::string getCurrentTimestamp() {
        std::time_t now = std::time(nullptr);
        char buf[100];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return std::string(buf);
    }

    static std::string generateTxId() {
        static int count = 1000;
        return "TX" + std::to_string(std::time(nullptr)) + std::to_string(++count);
    }

public:
    BankingSystem() {
        loadData();
    }

    ~BankingSystem() {
        saveData();
    }

    void saveData() const {
        std::ofstream custOut(customersFile);
        for (const auto& c : customers) custOut << c.toString() << "\n";

        std::ofstream accOut(accountsFile);
        for (const auto& a : accounts) accOut << a.toString() << "\n";

        std::ofstream txOut(transactionsFile);
        for (const auto& t : transactions) txOut << t.toString() << "\n";
    }

    void loadData() {
        customers.clear();
        accounts.clear();
        transactions.clear();

        std::ifstream custIn(customersFile);
        std::string line;
        while (std::getline(custIn, line)) {
            if (!line.empty()) customers.push_back(Customer::fromString(line));
        }

        std::ifstream accIn(accountsFile);
        while (std::getline(accIn, line)) {
            if (!line.empty()) accounts.push_back(Account::fromString(line));
        }

        std::ifstream txIn(transactionsFile);
        while (std::getline(txIn, line)) {
            if (!line.empty()) transactions.push_back(Transaction::fromString(line));
        }
    }

    Customer* findCustomer(const std::string& custId) {
        for (auto& c : customers) {
            if (c.getCustomerId() == custId) return &c;
        }
        return nullptr;
    }

    Account* findAccount(const std::string& accNum) {
        for (auto& a : accounts) {
            if (a.getAccountNumber() == accNum) return &a;
        }
        return nullptr;
    }

    bool createAccount(const std::string& name, const std::string& email, const std::string& phone, 
                       const std::string& accNum, const std::string& accType, double initialDeposit) {
        if (findAccount(accNum) != nullptr) {
            std::cout << "[ERROR] Account number '" << accNum << "' already exists!\n";
            return false;
        }

        std::string custId = "CUST" + std::to_string(customers.size() + 101);
        Customer newCust(custId, name, email, phone);
        customers.push_back(newCust);

        Account newAcc(accNum, custId, initialDeposit, accType);
        accounts.push_back(newAcc);

        if (initialDeposit > 0) {
            transactions.emplace_back(generateTxId(), accNum, "DEPOSIT", initialDeposit, getCurrentTimestamp(), "Initial Account Deposit");
        }

        saveData();
        std::cout << "[SUCCESS] Account created successfully!\n";
        std::cout << "          Customer ID   : " << custId << "\n";
        std::cout << "          Account Number: " << accNum << "\n";
        std::cout << "          Initial Balance: $" << std::fixed << std::setprecision(2) << initialDeposit << "\n";
        return true;
    }

    bool depositMoney(const std::string& accNum, double amount) {
        Account* acc = findAccount(accNum);
        if (!acc) {
            std::cout << "[ERROR] Account number '" << accNum << "' not found.\n";
            return false;
        }

        if (amount <= 0) {
            std::cout << "[ERROR] Deposit amount must be positive.\n";
            return false;
        }

        acc->deposit(amount);
        transactions.emplace_back(generateTxId(), accNum, "DEPOSIT", amount, getCurrentTimestamp(), "Cash Deposit");
        saveData();

        std::cout << "[SUCCESS] Deposited $" << std::fixed << std::setprecision(2) << amount << " into account " << accNum << ".\n";
        std::cout << "          New Balance: $" << acc->getBalance() << "\n";
        return true;
    }

    bool withdrawMoney(const std::string& accNum, double amount) {
        Account* acc = findAccount(accNum);
        if (!acc) {
            std::cout << "[ERROR] Account number '" << accNum << "' not found.\n";
            return false;
        }

        if (amount <= 0) {
            std::cout << "[ERROR] Withdrawal amount must be positive.\n";
            return false;
        }

        if (!acc->withdraw(amount)) {
            std::cout << "[ERROR] Insufficient balance! Current Balance: $" << std::fixed << std::setprecision(2) << acc->getBalance() << "\n";
            return false;
        }

        transactions.emplace_back(generateTxId(), accNum, "WITHDRAWAL", amount, getCurrentTimestamp(), "Cash Withdrawal");
        saveData();

        std::cout << "[SUCCESS] Withdrew $" << std::fixed << std::setprecision(2) << amount << " from account " << accNum << ".\n";
        std::cout << "          Remaining Balance: $" << acc->getBalance() << "\n";
        return true;
    }

    bool transferFunds(const std::string& fromAccNum, const std::string& toAccNum, double amount) {
        if (fromAccNum == toAccNum) {
            std::cout << "[ERROR] Cannot transfer funds to the same account.\n";
            return false;
        }

        Account* fromAcc = findAccount(fromAccNum);
        Account* toAcc = findAccount(toAccNum);

        if (!fromAcc) {
            std::cout << "[ERROR] Source account '" << fromAccNum << "' not found.\n";
            return false;
        }

        if (!toAcc) {
            std::cout << "[ERROR] Destination account '" << toAccNum << "' not found.\n";
            return false;
        }

        if (amount <= 0) {
            std::cout << "[ERROR] Transfer amount must be positive.\n";
            return false;
        }

        if (!fromAcc->withdraw(amount)) {
            std::cout << "[ERROR] Insufficient funds in source account for transfer.\n";
            return false;
        }

        toAcc->deposit(amount);
        std::string nowStr = getCurrentTimestamp();

        transactions.emplace_back(generateTxId(), fromAccNum, "TRANSFER_OUT", amount, nowStr, "Transfer to " + toAccNum);
        transactions.emplace_back(generateTxId(), toAccNum, "TRANSFER_IN", amount, nowStr, "Transfer from " + fromAccNum);

        saveData();

        std::cout << "[SUCCESS] Transferred $" << std::fixed << std::setprecision(2) << amount 
                  << " from " << fromAccNum << " to " << toAccNum << ".\n";
        std::cout << "          Source New Balance: $" << fromAcc->getBalance() << "\n";
        return true;
    }

    void displayAccountDetails(const std::string& accNum) {
        Account* acc = findAccount(accNum);
        if (!acc) {
            std::cout << "[ERROR] Account '" << accNum << "' not found.\n";
            return;
        }

        Customer* cust = findCustomer(acc->getCustomerId());

        std::cout << "\n=======================================================\n";
        std::cout << "                ACCOUNT INFORMATION                    \n";
        std::cout << "=======================================================\n";
        std::cout << " Account Number  : " << acc->getAccountNumber() << "\n";
        std::cout << " Account Type    : " << acc->getAccountType() << "\n";
        std::cout << " Account Balance : $" << std::fixed << std::setprecision(2) << acc->getBalance() << "\n";
        if (cust) {
            std::cout << " Customer ID     : " << cust->getCustomerId() << "\n";
            std::cout << " Customer Name   : " << cust->getName() << "\n";
            std::cout << " Email           : " << cust->getEmail() << "\n";
            std::cout << " Phone           : " << cust->getPhone() << "\n";
        }
        std::cout << "=======================================================\n";
    }

    void displayTransactionHistory(const std::string& accNum) const {
        bool found = false;
        std::cout << "\n========================================================================================\n";
        std::cout << "                           TRANSACTION HISTORY FOR ACCOUNT: " << accNum << "\n";
        std::cout << "========================================================================================\n";
        std::cout << std::left << std::setw(20) << "Tx ID" 
                  << std::setw(15) << "Type" 
                  << std::setw(12) << "Amount ($)" 
                  << std::setw(22) << "Date & Time" 
                  << std::setw(25) << "Details" << "\n";
        std::cout << "----------------------------------------------------------------------------------------\n";

        for (const auto& t : transactions) {
            if (t.accountNumber == accNum) {
                found = true;
                std::cout << std::left << std::setw(20) << t.transactionId 
                          << std::setw(15) << t.type 
                          << std::setw(12) << std::fixed << std::setprecision(2) << t.amount 
                          << std::setw(22) << t.timestamp 
                          << std::setw(25) << t.details << "\n";
            }
        }

        if (!found) {
            std::cout << "No transactions recorded for this account.\n";
        }
        std::cout << "========================================================================================\n";
    }
};

#endif // BANKING_SYSTEM_HPP
