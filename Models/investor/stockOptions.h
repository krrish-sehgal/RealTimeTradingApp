#pragma once
#include<bits/stdc++.h>
#include <random>
#include "1_Investor.h"
using namespace std;


vector<string>names = {"AXIS BANK", "RELIANCE", "TATA MOTORS"};
int totalCompanies = names.size();

// Define the unordered_map for company prices
unordered_map<string, double*> company;
unordered_map<string, int> currentIndex;

void initialiseOptions() {
    double price1[] = {100, 200, 300};
    double price2[] = {100, 600, 200};
    double price3[] = {100, 500, 400};
    company[names[0]] = new double[3];
    company[names[1]] = new double[3];
    company[names[2]] = new double[3];
    for (int i = 0; i < 3; i++) {
        company[names[0]][i] = price1[i];
        company[names[1]][i] = price2[i];
        company[names[2]][i] = price3[i];
    }
    currentIndex[names[0]] = 0;
    currentIndex[names[1]] = 0;
    currentIndex[names[2]] = 0;
}

void shufflePrices() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 g(seed);
    for (auto& pair : company) {
        shuffle(pair.second, pair.second + 3, g);
    }
}

void displayOptions(Investor &investor , int brokerFlag , int commissionRate) {
    initialiseOptions();
    int choice;
    do {
      shufflePrices(); // Shuffle prices before displaying options
        cout << "Companies and Prices:" << endl;
        for (int i = 0; i < 3; i++) {
            string name = names[i];
            double* prices = company[name];
            int index = currentIndex[name];
            unordered_map<string , PortfolioEntry>port = investor.getPortfolio();
            double boughtAt =0;
            if(port.find(name)!=port.end()) boughtAt = port[name].avgprice;
            cout << i+1 << ". " << name << ": $" << prices[index];
            if( boughtAt)cout <<"    bought at" << boughtAt << endl;
            else cout <<"    Not Bought"<< endl;
        }

        cout << "Enter 1 to buy stock" << endl;
        cout << "Enter 2 to sell stock" << endl;
        cout << "Enter 3 to exit" << endl;
        
        cin >> choice;
        
        if (choice == 1 || choice == 2) {
            int serialNumber;
            cout << "Enter the serial number of the company: ";
            cin >> serialNumber;
            
            if (serialNumber < 1 || serialNumber > 3) {
                cout << "Invalid serial number" << endl;
                continue;
            }
            
            string companyName = names[serialNumber - 1];
            double* prices = company[companyName];
            int index = currentIndex[companyName];
            double price = prices[index];
            
            unordered_map<string , PortfolioEntry>&portfolio = investor.getPortfolio();
            portfolio[companyName].price = price;

            if (choice == 1) {
                int quantity;
                cout << "Enter quantity: ";
                cin >> quantity;
                double totalPrice = quantity * price;
                
                if (investor.getBalance() >= totalPrice) {
                    investor.buyStock(companyName, quantity , price);
                } else {
                    cout << "Total price: " << totalPrice <<endl <<  ", Balance: " << investor.getBalance() << endl;
                    cout << endl << "Insufficient balance" << endl;
                }
            } else { // choice == 2
                if(investor.displayPNLforOneCompany(companyName)){

                    int quantity;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    investor.sellStock(companyName, quantity,brokerFlag,commissionRate);
                };

            }
        } else if (choice == 3) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    } while (true);
}

