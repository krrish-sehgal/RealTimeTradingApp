#pragma once

#include<bits/stdc++.h>
using namespace std;
#include"../Models/broker/1_Broker.h"
#include "./3_brokerFunctionalities.h"


// template<typename UserType>
void brokerLogin(vector<Broker*>&arr, vector<Investor*>&masterInvestorsArr) {
    int size = arr.size();
    string mail, pass;
    cout << "Enter your email: ";
    cin >> mail;
    cout << "Enter your password: ";
    cin >> pass;
    int flag = 1;
    for (int i = 0; i < size; i++) {
        if (arr[i]->getMail() == mail && arr[i]->getPass() == pass) {
            cout << endl << "Login successful!" << endl;
            cout << endl << "Welcome " << arr[i]->getName() << endl;
            brokerFunctionalities(*arr[i], masterInvestorsArr);
            flag = 0;
            break;
        }

    }
    if(flag) cout << " User not found , Try again";
}
