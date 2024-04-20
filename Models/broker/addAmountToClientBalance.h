#include<bits/stdc++.h>
using namespace std;

#include"1_Broker.h"

void Broker::addAmountToClientBalance(int ID, double amount){
    if(clients.find(ID) == clients.end()){
        cout<<"Client not found"<<endl;
   }
   else{
    clients[ID]->addBalance(amount);
   }
}