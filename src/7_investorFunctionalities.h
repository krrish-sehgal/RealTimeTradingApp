#pragma once

#include<bits/stdc++.h>
using namespace std;
#include"../Models/investor/1_Investor.h"
#include"../Models/investor/buystock.h"
#include"../Models/investor/sellStock.h"
#include"../Models/investor/displayPortfolio.h"
#include"../Models/investor/addbalance.h"
#include"../Models/investor/colors.h"


void investorFunctionalities(Investor&obj){

    int choice;
    while(true){
        cout << "\n\n1.display options\n2.Display Portfolio\n3.Display UserInfo\n4.Add Balance\n5.Exit\n";
        
        cin >> choice;
        if(choice==1){
            displayOptions(obj,0,0);
        }
        else if(choice==2){
            obj.displayPortfolio();
        }
        else if(choice==3){
            obj.displayUserInfo();
        }
        else if(choice==4){
            double amount;
            cout << "Enter the amount to be added: ";
            cin >> amount;
            obj.addBalance(amount);
        }
        else if(choice==5){
            break;
        }
        else{
            cout << "Invalid choice" << endl;
        }
    }
}