#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(const string &username) {
    ifstream infile("users.txt");
    string u, p;
    while (infile >> u >> p) {
        if (u == username) {
            return true; // Duplicate username found
        }
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "❌ Username already exists! Try another.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream outfile("users.txt", ios::app); // Append mode
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "✅ Registration successful!\n";
}

bool loginUser() {
    string username, password, u, p;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    while (infile >> u >> p) {
        if (u == username && p == password) {
            cout << "✅ Login successful! Welcome, " << username << ".\n";
            return true;
        }
    }
    cout << "❌ Invalid username or password!\n";
    return false;
}

int main() {
    int choice;
    do {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "❌ Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}