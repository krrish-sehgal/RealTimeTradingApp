#pragma once
#include<bits/stdc++.h>
#include <random>
#include "1_Investor.h"
using namespace std;


vector<string>companies ={"AAPL", "TSLA", "MSFT", "AMZN", "META", "JNJ", "ORCL", "TM", "NFLX", "DLTR", "ADBE", "INTC"};
int totalCompanies = companies.size();

#include "displayGraph.h"
#include "buyOrSell.h"    

void displayOptions(Investor &investor , int brokerFlag , int commissionRate) {

    int choice;
    do {
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
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==2){
                currentPrice = displayGraphAndGetPrice("TSLA","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==3){
                currentPrice = displayGraphAndGetPrice("MSFT","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==4){
                currentPrice = displayGraphAndGetPrice("AMZN","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==5){
                currentPrice = displayGraphAndGetPrice("META","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==6){
                currentPrice = displayGraphAndGetPrice("JNJ","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==7){
                currentPrice = displayGraphAndGetPrice("ORCL","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==8){
                currentPrice = displayGraphAndGetPrice("TM","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==9){
                currentPrice = displayGraphAndGetPrice("NFLX","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==10){
                currentPrice = displayGraphAndGetPrice("DLTR","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==11){
                currentPrice = displayGraphAndGetPrice("ADBE","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
            }
            else if(serialNumber==12){
                currentPrice = displayGraphAndGetPrice("INTC","NASDAQ");
                buyOrSell(investor,companyName,currentPrice,brokerFlag,commissionRate);
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

