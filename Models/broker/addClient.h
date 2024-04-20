#pragma once
#include<bits/stdc++.h>
#include"../investor/1_Investor.h"
#include"1_Broker.h"
using namespace std;
void Broker::addClient(vector<Investor*> &masterInvestors) {
    string name, mail, pass;    
    cout << "Enter investor's email: ";
    cin >> mail;
    cout << "Enter his/her password: ";
    cin >> pass;
    cout << "Enter his/her name: ";
    cin >> name;
    cout << "Enter the amount to be added in the investing account: "; 
    double balance; 
    cin >> balance;
    
    Investor *newClient = new Investor(name,mail,pass,balance);
    masterInvestors.push_back(newClient);
    // clientList.push_back(newClient);

    clients[clientID++]=newClient;

    cout<<"\nClient added succesfully\n";
} 