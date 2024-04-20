#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "1_Investor.h"
void showOptions(Investor &investor , string companyName , float currentPrice , int brokerFlag , int commissionRate){
    unordered_map<string , PortfolioEntry>&portfolio = investor.getPortfolio();

    cout << "Company Name: " << companyName << endl;
    cout << "Current Price: " << currentPrice << endl;

    cout << "Enter 1 to Buy" << endl;
    cout << "Enter 2 to Sell" << endl;
    cout << "Enter 3 to exit" << endl;
    int choice;
    cin >> choice;
    if(choice==1){
        int quantity;
        cout << "Enter quantity: ";
        cin >> quantity;
        double totalPrice = quantity * currentPrice;
        if (investor.getBalance() >= totalPrice) {
            investor.buyStock(companyName, quantity , currentPrice);
        } else {
            cout << "Total price: " << totalPrice <<endl <<  ", Balance: " << investor.getBalance() << endl;
            cout << endl << "Insufficient balance" << endl;
        }
    }
    else if(choice==2){
        if(portfolio.find(companyName)!=portfolio.end()){
            int quantity;
            cout << "Enter quantity: ";
            cin >> quantity;
            investor.sellStock(companyName, quantity,brokerFlag,commissionRate);
        }
        else{
            cout << "You have not bought this stock" << endl;
        }
    }
    else{
        cout << "Exiting..." << endl;
    }
}