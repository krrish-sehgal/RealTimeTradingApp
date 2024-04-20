#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "../../stockDataWork/getCSV.h"
#include "../../stockDataWork/getRealTimePrice.h"

float displayGraphAndGetPrice(string companyName , string exchange){
    makeCSV(companyName,exchange);
    system("python3 ../stockDataWork/plotData.py");
    
    float currentPrice = getRealTimePrice(companyName, exchange);
    cout << "This is the current Price = " << currentPrice << endl;

    return currentPrice;
}