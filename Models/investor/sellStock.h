#pragma once

#include<bits/stdc++.h>
#include"1_Investor.h"
using namespace std;



void Investor :: sellStock(const string& company, int quantity , int flag , int commissonRate){
        if (portfolio.find(company) == portfolio.end() || portfolio[company].quantity < quantity) {
            cout << "Not enough shares of " << company << " to sell" << endl;
            return;
        }
        if(quantity<=0){
            cout<<"Invalid quantity entered cancelling process...Exiting \n ";
            return;
        }
        double profit = (portfolio[company].price - portfolio[company].avgprice) *quantity;
       char choice;
       confirm:
       cout<<"Are you sure you want to sell this stocks?(y/n)";
       cin>>choice;
       switch(choice){
        case 'n':
        cout<<"Cancelling selling stocks...Exiting\n";
       break;
       case 'y': 
        if(profit>0 && flag){
            balance += quantity * portfolio[company].price-profit*commissonRate/100;
        }
        else
        balance += quantity * portfolio[company].price;

        portfolio[company].quantity -= quantity;
        invested-=portfolio[company].avgprice*quantity;
        cout << "Sold " << quantity << " shares of " << company << " at $" << portfolio[company].price << " each" << endl;
       
    break;
    default:
    cout<<"Enter Valid options\n";
    goto confirm;
    break;
    }
    }