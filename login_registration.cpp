#include <iostream>
#include <fstream>
#include <string>

void registerUser() {
    std::string username, password, u, p;
    std::cout << "\n--- Registration ---\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Check if user already exists
    std::ifstream infile("users.txt");
    while (infile >> u >> p) {
        if (u == username) {
            std::cout << "❌ Error: Username already exists!\n";
            infile.close();
            return;
        }
    }
    infile.close();

    // Save new user
    std::ofstream outfile("users.txt", std::ios::app);
    outfile << username << " " << password << "\n";
    outfile.close();
    std::cout << "Registration successful!\n";
}

bool loginUser() {
    std::string username, password, u, p;
    std::cout << "\n--- Login ---\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream infile("users.txt");
    while (infile >> u >> p) {
        if (u == username && p == password) {
            std::cout << "Login successful! Welcome back, " << username << ".\n";
            infile.close();
            return true;
        }
    }
    infile.close();
    std::cout << "Invalid username or password.\n";
    return false;
}

int main() {
    int choice;
    while (true) {
        std::cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
        std::cin >> choice;
        
        if (choice == 1) registerUser();
        else if (choice == 2) loginUser();
        else if (choice == 3) break;
        else std::cout << "Invalid choice!\n";
    }
    return 0;
}
