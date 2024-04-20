#pragma once

#include <bits/stdc++.h>
#include "1_Investor.h"

using namespace std;

void Investor::buyStock(const string &company, int quantity, double price)
{
    // Check if company exists in portfolio, if not add it with initial values
    if (portfolio.find(company) == portfolio.end())
    {
        balance -= (price * quantity);
        invested += (price * quantity);
        portfolio[company].quantity = quantity;
        portfolio[company].price = price;
        portfolio[company].avgprice = price;
    }
    else
    {
        double oldPrice = portfolio[company].price;
        balance -= (price * quantity);
        invested += (price * quantity);
        // Update quantity if company already exists
        int temp = portfolio[company].quantity;
        portfolio[company].quantity += quantity;
        portfolio[company].avgprice = (portfolio[company].avgprice * temp + quantity * price) / (quantity + temp);
    }
    cout << "\nBought " << quantity << " shares of " << company << " at $" << price << " each" << endl;
    displayPortfolio();
}
