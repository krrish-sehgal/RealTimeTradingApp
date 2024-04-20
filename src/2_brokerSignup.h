#pragma once

#include<bits/stdc++.h>
using namespace std;
#include"../Models/broker/1_Broker.h"

void brokerSignup(vector<Broker*>&brokers){
    string name, mail, pass;
    string licenseNumber;
    double commissionRate;
    cout << "Enter your email: ";
    cin >> mail;
    cout << "Enter your password: ";
    cin >> pass;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your license number: ";
    cin >> licenseNumber;

do {
    cout << "Enter your commission rate (between 0 and 16): ";
    cin >> commissionRate;
    if (commissionRate < 0 || commissionRate > 16) {
        cout << "Invalid commission rate. Please enter a rate between 0 and 16." << endl;
    }
} while (commissionRate < 0 || commissionRate > 16);


    brokers.push_back(new  Broker(name, licenseNumber, commissionRate ,mail,pass) );
}