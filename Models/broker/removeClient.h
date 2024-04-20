#pragma once
#include<bits/stdc++.h>
#include"../investor/1_Investor.h"
#include"1_Broker.h"
using namespace std;
void Broker::removeClient(int ID){
    if(clients.find(ID) == clients.end()){
        cout<<"Client not found"<<endl;
    }
    else{
        clients.erase(ID);
        cout<<"Client removed"<<endl;
    }
} 