#pragma once
#include<bits/stdc++.h>
#include"../investor/1_Investor.h"
#include"1_Broker.h"

using namespace std;
void Broker:: displayClientInfo(int ID) {
   if(clients.find(ID) == clients.end()){
      cout<<"Client not found"<<endl;
   }
   else{ 
      cout<<"ID:"<<ID;
      clients[ID]->displayUserInfo();
      cout<<"\nBalance"<<clients[ID]->getBalance()<<endl;
      cout<<"\nInvested"<<clients[ID]->getinvested()<<endl;
      cout<<"\nTotal PnL\n"<<clients[ID]->gettotalpnl()<<endl;
   }
 }