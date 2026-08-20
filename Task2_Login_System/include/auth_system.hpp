#ifndef AUTH_SYSTEM_HPP
#define AUTH_SYSTEM_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdint>

class AuthSystem {
private:
    std::string databasePath;

    // Simple robust hashing function (Salted FNV-1a 64-bit hash formatted as hex)
    static std::string hashPassword(const std::string& password, const std::string& salt = "CodeAlphaSalt2026") {
        uint64_t hash = 14695981039346656037ULL; // FNV offset basis
        uint64_t prime = 1099511628211ULL;     // FNV prime

        std::string salted = salt + password;
        for (char c : salted) {
            hash ^= static_cast<uint64_t>(c);
            hash *= prime;
        }

        std::stringstream ss;
        ss << std::hex << std::setw(16) << std::setfill('0') << hash;
        return ss.str();
    }

public:
    explicit AuthSystem(const std::string& dbPath = "data/users.txt") 
        : databasePath(dbPath) {}

    bool userExists(const std::string& username) const {
        std::ifstream file(databasePath);
        if (!file.is_open()) return false;

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            std::string storedUser;
            std::getline(ss, storedUser, ':');
            if (storedUser == username) {
                return true;
            }
        }
        return false;
    }

    bool registerUser(const std::string& username, const std::string& password) {
        if (username.empty() || password.empty()) {
            std::cout << "[ERROR] Username and password cannot be empty.\n";
            return false;
        }

        if (username.find(':') != std::string::npos || password.find(':') != std::string::npos) {
            std::cout << "[ERROR] Username and password cannot contain colon (:) character.\n";
            return false;
        }

        if (password.length() < 4) {
            std::cout << "[ERROR] Password must be at least 4 characters long.\n";
            return false;
        }

        if (userExists(username)) {
            std::cout << "[ERROR] Username '" << username << "' is already registered. Please pick another.\n";
            return false;
        }

        std::ofstream file(databasePath, std::ios::app);
        if (!file.is_open()) {
            std::cout << "[ERROR] Failed to open user database for writing.\n";
            return false;
        }

        std::string hashedPassword = hashPassword(password);
        file << username << ":" << hashedPassword << "\n";
        file.close();

        std::cout << "[SUCCESS] User '" << username << "' registered successfully!\n";
        return true;
    }

    bool loginUser(const std::string& username, const std::string& password) const {
        if (username.empty() || password.empty()) {
            std::cout << "[ERROR] Username and password cannot be empty.\n";
            return false;
        }

        std::ifstream file(databasePath);
        if (!file.is_open()) {
            std::cout << "[ERROR] User database is empty or cannot be opened. Please register first.\n";
            return false;
        }

        std::string line;
        std::string inputHash = hashPassword(password);

        while (std::getline(file, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            std::string storedUser, storedHash;
            std::getline(ss, storedUser, ':');
            std::getline(ss, storedHash, ':');

            if (storedUser == username) {
                if (storedHash == inputHash) {
                    std::cout << "[SUCCESS] Login successful! Welcome back, " << username << ".\n";
                    return true;
                } else {
                    std::cout << "[ERROR] Invalid password provided.\n";
                    return false;
                }
            }
        }

        std::cout << "[ERROR] Username '" << username << "' not found.\n";
        return false;
    }
};

#endif // AUTH_SYSTEM_HPP
