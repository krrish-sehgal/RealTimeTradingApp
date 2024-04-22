#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "../../stockDataWork/getCSV.h"
#include "../../stockDataWork/getRealTimePrice.h"
    std::stringstream cmd;
float displayGraphAndGetPrice(string companyName , string exchange){
    makeCSV(companyName,exchange);
    system("python3 ../stockDataWork/plotData.py");

    
    float currentPrice = getRealTimePrice(companyName, exchange);

    return currentPrice;
}