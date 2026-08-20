#include "../include/banking_system.hpp"
#include <iostream>
#include <limits>
#include <string>

#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

void ensureDataFolder() {
#ifdef _WIN32
    _mkdir("data");
#else
    mkdir("data", 0777);
#endif
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    ensureDataFolder();
    BankingSystem bank;

    int choice = 0;
    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "        CODEALPHA BANKING SYSTEM         \n";
        std::cout << "=========================================\n";
        std::cout << " 1. Open New Bank Account\n";
        std::cout << " 2. Deposit Money\n";
        std::cout << " 3. Withdraw Money\n";
        std::cout << " 4. Transfer Funds\n";
        std::cout << " 5. View Account Details & Balance\n";
        std::cout << " 6. View Transaction History\n";
        std::cout << " 7. Exit\n";
        std::cout << "=========================================\n";
        std::cout << "Enter your choice (1-7): ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }
        clearInput();

        if (choice == 1) {
            std::string name, email, phone, accNum, accType;
            double initialDeposit = 0.0;

            std::cout << "\n--- CREATE NEW BANK ACCOUNT ---\n";
            std::cout << "Customer Name: ";
            std::getline(std::cin, name);
            std::cout << "Email Address: ";
            std::getline(std::cin, email);
            std::cout << "Phone Number : ";
            std::getline(std::cin, phone);
            std::cout << "Desired Account Number: ";
            std::getline(std::cin, accNum);
            std::cout << "Account Type (Savings/Checking): ";
            std::getline(std::cin, accType);
            if (accType.empty()) accType = "Savings";

            std::cout << "Initial Deposit Amount ($): ";
            while (!(std::cin >> initialDeposit) || initialDeposit < 0.0) {
                std::cout << "Invalid amount. Enter a non-negative initial deposit ($): ";
                clearInput();
            }
            clearInput();

            bank.createAccount(name, email, phone, accNum, accType, initialDeposit);

        } else if (choice == 2) {
            std::string accNum;
            double amount = 0.0;

            std::cout << "\n--- DEPOSIT FUNDS ---\n";
            std::cout << "Account Number: ";
            std::getline(std::cin, accNum);
            std::cout << "Deposit Amount ($): ";
            while (!(std::cin >> amount) || amount <= 0.0) {
                std::cout << "Invalid amount. Enter a positive deposit amount ($): ";
                clearInput();
            }
            clearInput();

            bank.depositMoney(accNum, amount);

        } else if (choice == 3) {
            std::string accNum;
            double amount = 0.0;

            std::cout << "\n--- WITHDRAW FUNDS ---\n";
            std::cout << "Account Number: ";
            std::getline(std::cin, accNum);
            std::cout << "Withdrawal Amount ($): ";
            while (!(std::cin >> amount) || amount <= 0.0) {
                std::cout << "Invalid amount. Enter a positive withdrawal amount ($): ";
                clearInput();
            }
            clearInput();

            bank.withdrawMoney(accNum, amount);

        } else if (choice == 4) {
            std::string fromAcc, toAcc;
            double amount = 0.0;

            std::cout << "\n--- TRANSFER FUNDS ---\n";
            std::cout << "From Account Number: ";
            std::getline(std::cin, fromAcc);
            std::cout << "To Account Number  : ";
            std::getline(std::cin, toAcc);
            std::cout << "Transfer Amount ($): ";
            while (!(std::cin >> amount) || amount <= 0.0) {
                std::cout << "Invalid amount. Enter a positive transfer amount ($): ";
                clearInput();
            }
            clearInput();

            bank.transferFunds(fromAcc, toAcc, amount);

        } else if (choice == 5) {
            std::string accNum;
            std::cout << "\n--- VIEW ACCOUNT DETAILS ---\n";
            std::cout << "Account Number: ";
            std::getline(std::cin, accNum);

            bank.displayAccountDetails(accNum);

        } else if (choice == 6) {
            std::string accNum;
            std::cout << "\n--- VIEW TRANSACTION HISTORY ---\n";
            std::cout << "Account Number: ";
            std::getline(std::cin, accNum);

            bank.displayTransactionHistory(accNum);

        } else if (choice == 7) {
            std::cout << "Thank you for using CodeAlpha Banking System. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please select between 1 and 7.\n";
        }
    }

    return 0;
}
