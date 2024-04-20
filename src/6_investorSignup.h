#pragma once
#include<bits/stdc++.h>
using namespace std;
#include"../Models/investor/1_Investor.h"

void investorSignup(vector<Investor*> &investors){
    string name, mail, pass;    
    cout << "Enter your email: ";
    cin >> mail;
    cout << "Enter your password: ";
    cin >> pass;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your balance: "; 
    double balance; 
    cin >> balance;

    investors.push_back(new Investor(name,mail,pass,balance));
}