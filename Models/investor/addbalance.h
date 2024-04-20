#pragma once
#include <bits/stdc++.h>
#include "1_Investor.h"

using namespace std;
void Investor::addBalance(double amount){
 cout << "\nPrevious Balance:$" << balance;
        balance += amount;
        cout << "\nNew Balance:$" << balance;
}