#include "../include/auth_system.hpp"
#include <iostream>
#include <limits>
#include <string>

#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

void ensureDataDirExists() {
#ifdef _WIN32
    _mkdir("data");
#else
    mkdir("data", 0777);
#endif
}

void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    ensureDataDirExists();
    AuthSystem auth("data/users.txt");

    int choice = 0;
    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "    LOGIN & REGISTRATION SYSTEM           \n";
        std::cout << "=========================================\n";
        std::cout << " 1. Register New User\n";
        std::cout << " 2. User Login\n";
        std::cout << " 3. Exit\n";
        std::cout << "=========================================\n";
        std::cout << "Enter choice (1-3): ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearBuffer();
            continue;
        }
        clearBuffer();

        if (choice == 1) {
            std::string username, password;
            std::cout << "\n--- USER REGISTRATION ---\n";
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);
            std::cout << "Enter Password: ";
            std::getline(std::cin, password);

            auth.registerUser(username, password);

        } else if (choice == 2) {
            std::string username, password;
            std::cout << "\n--- USER LOGIN ---\n";
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);
            std::cout << "Enter Password: ";
            std::getline(std::cin, password);

            if (auth.loginUser(username, password)) {
                std::cout << "\n>>> Access Granted to System Dashboard <<<\n";
            }
        } else if (choice == 3) {
            std::cout << "Exiting Login System. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please choose 1, 2, or 3.\n";
        }
    }

    return 0;
}
