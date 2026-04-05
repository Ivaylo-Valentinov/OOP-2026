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
    void registerUser() {
        size_t maxLength; 
        std::cin >> maxLength;

        char* username = new char[maxLength + 1];
        char* password = new char[maxLength + 1];

        if (std::cin.peek() == '\n') {
            std::cin.ignore();
        }

        std::cin.getline(username, maxLength);
        std::cin.getline(password, maxLength);

        std::ofstream fout(fileName, std::ios::app);

        fout << maxLength + 1 << std::endl << username << std::endl << password << std::endl;

        fout.close();
        delete[] username;
        delete[] password;
    }

    // Handles user login by scanning the file line by line
    bool login() {
        size_t maxLength;
        std::cin >> maxLength;

        char* username = new char[maxLength + 1];
        char* password = new char[maxLength + 1];

        if (std::cin.peek() == '\n') {
            std::cin.ignore();
        }

        std::cin.getline(username, maxLength);
        std::cin.getline(password, maxLength);

        std::ifstream fin(fileName);
        size_t tempMaxLength; 
        bool found = false;
        while (!found && fin >> tempMaxLength) {

            char* tempUsername = new char[tempMaxLength];
            char* tempPassword = new char[tempMaxLength];
            fin.ignore();

            fin.getline(tempUsername, tempMaxLength);
            fin.getline(tempPassword, tempMaxLength);

            if (strcmp(username, tempUsername) == 0 && strcmp(password, tempPassword) == 0) {
                found = true;
            }

            delete[] tempUsername;
            delete[] tempPassword;
        }

        fin.close();
        delete[] username;
        delete[] password;
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
