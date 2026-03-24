#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_STR_LEN = 50;
const int MAX_PATH_LEN = 100;

class CalendarSystem {
private:
    char fileName[MAX_PATH_LEN];

public:
    // Constructor initializes the database file name
    CalendarSystem(const char* name) {
        strncpy(fileName, name, MAX_PATH_LEN - 1);
        fileName[MAX_PATH_LEN - 1] = '\0';
    }

    // Handles new user registration
    void registerUser() {
        char username[MAX_STR_LEN], password[MAX_STR_LEN];

        std::cout << "--- User Registration ---\n";
        std::cout << "Enter username: ";
        std::cin.getline(username, MAX_STR_LEN);

        std::cout << "Enter password (spaces allowed): ";
        std::cin.getline(password, MAX_STR_LEN);

        // Open file in append mode
        std::ofstream outFile(fileName, std::ios::app);
        if (outFile.is_open()) {
            // Write to file, separated by newlines to support spaces in strings
            outFile << username << "\n" << password << "\n";
            outFile.close();
            std::cout << "Registration successful!\n";
        }
        else {
            std::cerr << "Error: Could not open database for writing.\n";
        }
    }

    // Handles user login by scanning the file line by line
    bool login() {
        char inputUser[MAX_STR_LEN], inputPass[MAX_STR_LEN];
        char fileUser[MAX_STR_LEN], filePass[MAX_STR_LEN];

        std::cout << "--- User Login ---\n";
        std::cout << "Username: ";
        std::cin.getline(inputUser, MAX_STR_LEN);

        std::cout << "Password: ";
        std::cin.getline(inputPass, MAX_STR_LEN);

        std::ifstream inFile(fileName);
        if (!inFile.is_open()) {
            std::cout << "Error: Database file not found.\n";
            return false;
        }

        bool found = false;
        // Read lines in pairs (Username then Password)
        while (inFile.getline(fileUser, MAX_STR_LEN)) {
            if (inFile.getline(filePass, MAX_STR_LEN)) {
                if (strcmp(inputUser, fileUser) == 0 && strcmp(inputPass, filePass) == 0) {
                    found = true;
                    break;
                }
            }
        }

        inFile.close();
        return found;
    }
};

int main() {
    // Database file name
    const char DB_NAME[] = "calendar_users.txt";
    CalendarSystem mySystem(DB_NAME);

    int choice;

    while (true) {
        std::cout << "\n1. Register\n2. Login\n3. Exit\nChoice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Exiting...\n";
            break;
        }
        std::cin.ignore();

        if (choice == 1) {
            mySystem.registerUser();
        }
        else if (choice == 2) {
            if (mySystem.login()) {
                std::cout << "Login successful! Welcome to the system.\n";
            }
            else {
                std::cout << "Login failed: Invalid username or password.\n";
            }
        }
        else if (choice == 3) {
            std::cout << "System shutting down. Goodbye!\n";
            break;
        }
        else {
            std::cout << "Unknown choice. Try again.\n";
        }
    }

    return 0;
}
