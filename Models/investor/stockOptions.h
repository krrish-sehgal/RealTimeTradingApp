#pragma once
#include<bits/stdc++.h>
#include <random>
#include "1_Investor.h"
using namespace std;


vector<string>companies ={"AAPL", "TSLA", "MSFT", "AMZN", "META", "JNJ", "ORCL", "TM", "NFLX", "DLTR", "ADBE", "INTC"};
int totalCompanies = companies.size();

// Define the unordered_map for company prices
unordered_map<string, double*> company;
unordered_map<string, int> currentIndex;

void initialiseOptions() {
    // double price1[] = {100, 200, 300};
    // double price2[] = {100, 600, 200};
    // double price3[] = {100, 500, 400};
    // company[ticker[0]] = new double[3];
    // company[ticker[1]] = new double[3];
    // company[ticker[2]] = new double[3];
    // for (int i = 0; i < 3; i++) {
    //     company[ticker[0]][i] = price1[i];
    //     company[ticker[1]][i] = price2[i];
    //     company[ticker[2]][i] = price3[i];
    // }
    // currentIndex[ticker[0]] = 0;
    // currentIndex[ticker[1]] = 0;
    // currentIndex[ticker[2]] = 0;
}

void shufflePrices() {
    // unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // mt19937 g(seed);
    // for (auto& pair : company) {
    //     shuffle(pair.second, pair.second + 3, g);
    // }
}


#include "displayGraph.h"
#include "showOptions.h"    

void displayOptions(Investor &investor , int brokerFlag , int commissionRate) {
    initialiseOptions();
    int choice;
    do {
      shufflePrices(); // Shuffle prices before displaying options
        cout << "Companies and Prices:" << endl;
        

        for (int i = 0; i < totalCompanies; i++) {
            string name = companies[i];
            unordered_map<string , PortfolioEntry>port = investor.getPortfolio();
            double boughtAt =0;
            if(port.find(name)!=port.end()) boughtAt = port[name].avgprice;
            cout << i+1 << ". " << name;
            if( boughtAt)cout <<"    bought at" << boughtAt << endl;
            else cout <<"    Not Bought"<< endl;
        }

        cout << "Enter 1 to Display stock Details" << endl;
        cout << "Enter 2 to exit" << endl;
        
        cin >> choice;
        
        if (choice == 1) {
            int serialNumber;
            cout << "Enter the serial number of the company: ";
            cin >> serialNumber;
            
            if (serialNumber < 1 || serialNumber > totalCompanies) {
                cout << "Invalid serial number" << endl;
                continue;
            }
            string companyName = companies[serialNumber - 1];
            float currentPrice = 0;
            if(serialNumber==1){
                currentPrice = displayGraphAndGetPrice("AAPL","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==2){
                currentPrice = displayGraphAndGetPrice("TSLA","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==3){
                currentPrice = displayGraphAndGetPrice("MSFT","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==4){
                currentPrice = displayGraphAndGetPrice("AMZN","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==5){
                currentPrice = displayGraphAndGetPrice("META","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==6){
                currentPrice = displayGraphAndGetPrice("JNJ","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==7){
                currentPrice = displayGraphAndGetPrice("ORCL","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==8){
                currentPrice = displayGraphAndGetPrice("TM","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==9){
                currentPrice = displayGraphAndGetPrice("NFLX","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==10){
                currentPrice = displayGraphAndGetPrice("DLTR","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==11){
                currentPrice = displayGraphAndGetPrice("ADBE","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==12){
                currentPrice = displayGraphAndGetPrice("INTC","NASDAQ");
                showOptions(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            
            unordered_map<string , PortfolioEntry>&portfolio = investor.getPortfolio();
            portfolio[companyName].price = currentPrice;

        } else if (choice == 2) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    } while (true);
}

