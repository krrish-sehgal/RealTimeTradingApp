#pragma once

#include<bits/stdc++.h>
using namespace std;


class User {
protected:
    string username;
    string email;
    string password;

public:
    // Constructor
    User() {}
    User(const string& username,const string& email,const string& password): username(username),password(password), email(email) {}

    // Virtual destructor
    virtual ~User() {}

    // Getter methods
    string getName() {
        return username;
    }

    string getMail() {
        return email;
    }

    string getPass() {
        return password;
    }   
    // Virtual function to display user information
    virtual void displayUserInfo() const {
        cout << "Username: " << username << endl;
        cout << "Email: " << email << endl;
    }
};
