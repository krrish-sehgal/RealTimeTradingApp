#pragma once
#include<bits/stdc++.h>
#include<unordered_map>
#include "../user/User.h"
#include"../investor/1_Investor.h"

using namespace std;

class Broker:public User {
protected:

    string licenseNumber;
    double commissionRate;
    unordered_map<int, Investor*> clients; 
    int clientID; // Track the client ID
    vector<Investor*> clientList;

public:
    // Constructor
    Broker() {}
    Broker(string& name, string& licenseNumber, double commissionRate,string mail,string pass)
        :User(name,mail,pass), licenseNumber(licenseNumber), commissionRate(commissionRate) {

            clientID = 0;
        }

    // Getter methods
    string getLicenseNumber() const {
        return licenseNumber;
    }

    double getCommissionRate() const {
        return commissionRate;
    }

    void setLicenseNumber(const string& newLicenseNumber) {
        licenseNumber = newLicenseNumber;
    }

    void setCommissionRate(double newCommissionRate) {
        commissionRate = newCommissionRate;
    }


void displayBrokerInfo();
 void addClient(vector<Investor*> &);
 void removeClient(int );   
 void displayListClients();
 void displayClientInfo(int );
 void openclientid(int ,string& ) ;
void addAmountToClientBalance(int , double );

};
#include"./addClient.h"
#include"./displayClientInfo.h"
#include"./displayListClients.h"
#include"./openClientid.h"
#include"./removeClient.h"
#include"./addAmountToClientBalance.h"
#include"./displayBrokerInfo.h"