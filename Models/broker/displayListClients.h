#pragma once
#include<bits/stdc++.h>
#include"../investor/1_Investor.h"
#include"1_Broker.h"
using namespace std;
void Broker::displayListClients()
{
   if(clients.empty()){
      cout<<"No clients found"<<endl;
      return;
   } 
     for (auto& entry : clients) {
        int ID = entry.first;
        Investor*client = entry.second;
        if(client->gettotalpnl()<0) red();
        else if(client->gettotalpnl()>0)green();
        else reset();

        cout << "Client ID: " << ID << endl;
        client->displayUserInfo();
        cout << "The total Profit/loss of this account : "  << client->gettotalpnl();
        reset();
      }
 } 