#pragma once    
#include<bits/stdc++.h>
using namespace std;

void reset()
{
    cout << "\033[0m";
}
void red() // red
{
    cout << "\033[0;31m";
}
void green()
{
    cout << "\033[0;32m";
}
void purple()//purple
{cout<<"\033[0;35m";}
void yellow()//yellow
{cout<<"\033[0;33m";}
void cyan()
{cout<<"\033[0;36m";}
void highlight()
{cout<<"\033[1;41m";}
void blue() //blue
{cout<<"\033[0;34m";}