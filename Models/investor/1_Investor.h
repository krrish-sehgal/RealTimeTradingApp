#pragma once

#include <bits/stdc++.h>
#include<unordered_map>
#include "../user/User.h"
using namespace std;

class PortfolioEntry
{
    public:
    int quantity;
    double price;     // current
    double avgprice; // bought price
};

#include "./colors.h"

class Investor : public User
{

protected:
double totalpnl;    double invested;
    double balance;
    unordered_map<string, PortfolioEntry> portfolio; // Map company to quantity
 
public:
    Investor() {}
    Investor(const string &username, const string &email, const string &password, double balance)
        : User(username, password, email), balance(balance) {}

    // Function to buy a stock
    void buyStock(const string &, int , double);

    int displayPNLforOneCompany(string& );
    // Function to sell a stock
    void sellStock(const string &, int , int , int );
    void addBalance(double );
    // Function to display user's portfolio
    int displayPortfolio();
    void displayUserInfo();

    unordered_map<string , PortfolioEntry>& getPortfolio(){
        return portfolio;
    }

    double gettotalpnl(){
        return totalpnl;
    }
    double getBalance(){
        return balance;
    }
    double getinvested(){
        return invested;
    }
};

#include "buystock.h"
#include "sellStock.h"
#include "displayPortfolio.h"
#include "addbalance.h"
#include "displayUserInfo.h"
#include "stockOptions.h"
#include "displayPNLforOneCompany.h"

