#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class temp {
    string userName, email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUp();
    void forgotPassword();
};

int main() {
    temp obj;
    int choice;

    while (true) {
        cout << "\n1- Login";
        cout << "\n2- Sign up";
        cout << "\n3- Forgot password";
        cout << "\n4- Exit";
        cout << "\nEnter your choice :: ";
        cin >> choice;
        cin.ignore(); // Limpa o buffer de entrada

        switch (choice) {
            case 1:
                obj.login();
                break;
            case 2:
                obj.signUp();
                break;
            case 3:
                obj.forgotPassword();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid Selection...!" << endl;
        }
    }
}

void temp::signUp() {
    cout << "\nEnter your user name :: ";
    getline(cin, userName);
    cout << "\nEnter your email :: ";
    getline(cin, email);
    cout << "\nEnter your password :: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << email << "*" << password << endl;
    file.close();
    cout << "Sign up successful!" << endl;
}

void temp::login() {
    string searchName, searchPass;
    cout << "--------LOGIN-----------" << endl;
    cout << "Enter your User name :: ";
    getline(cin, searchName);
    cout << "Enter your password :: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    bool found = false;

    while (getline(file, userName, '*') &&
           getline(file, email, '*') &&
           getline(file, password)) {
        if (userName == searchName && password == searchPass) {
            found = true;
            cout << "Login Successful...." << endl;
            cout << "Username :: " << userName << endl;
            cout << "Email :: " << email << endl;
            break;
        }
    }

    if (!found) {
        cout << "Incorrect username or password...." << endl;
    }
    file.close();
}

void temp::forgotPassword() {
    cout << "\nEnter your username :: ";
    getline(cin, searchName);
    cout << "\nEnter your email address :: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    bool found = false;

    while (getline(file, userName, '*') &&
           getline(file, email, '*') &&
           getline(file, password)) {
        if (userName == searchName && email == searchEmail) {
            found = true;
            cout << "Your Password is :: " << password << endl;
            break;
        }
    }

    if (!found) {
        cout << "Username or email not found...." << endl;
    }
    file.close();
}
