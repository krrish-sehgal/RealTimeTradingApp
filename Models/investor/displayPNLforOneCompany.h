#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "1_Investor.h"

int Investor::displayPNLforOneCompany(string& company){

    if(portfolio.find(company)==portfolio.end()){
        return 0 ;
    }
    double totalpnl = 0;
    PortfolioEntry& info = portfolio[company];
    if(info.avgprice ==0){
        cout << "Stocks havent been purchased yet" << endl;
        return 0;
    } 

    cout << info.price << endl << info.avgprice << endl;
    double profit = (info.price - info.avgprice) * info.quantity;
    if(info.avgprice!=0) cout << " -- " << company << ": Bought at $" <<  info.avgprice<<"/share" << " -- \n Current price $" << info.price<< "/share"<< "\n Quantity " << info.quantity ;
    if (profit <= 0) red();
    else green();

    cout << "\n Profit/Loss: $" << profit << endl;
    totalpnl += profit;
    reset();
    return 1;

}