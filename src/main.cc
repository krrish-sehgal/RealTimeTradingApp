#include <iostream>
#include "../Models/user/User.h"
#include "../Models/investor/1_Investor.h"
#include "../Models/broker/1_Broker.h"    
#include "1_brokerLogin.h"    
#include "2_brokerSignup.h"    
#include "5_investorLogin.h"    
#include "6_investorSignup.h"    


using namespace std;

int main() {

    bool running = true;

    vector<Broker*> brokers;
    vector<Investor*> investors;
 
    while (running) {
        cout << "Welcome to the Trading Simulation Application\n";
        cout << "1. Broker\n";
        cout << "2. Investor\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";

        int option;
        cin >> option;
        int pass ; 
        string mail;
        if (option == 1) {
            do{
                cout << "You chose Broker\n";  
                cout << "1.Login" << endl << "2.SignUp" << endl  << "3.Exit" << endl;
                cin >> option;
                if(option==1){
                    brokerLogin(brokers,investors);
                }
                else if(option==2){
                    brokerSignup(brokers);
                }
                else{
                    cout << "Invalid option. Please choose again.\n";}
            }while(option!=3);
        } else if (option == 2) {
            do{
                cout << "You are an Investor\n";
                cout << "1.Login" << endl << "2.SignUp" << endl << "3.Exit" << endl;
                cin >> option;
                if(option==1){
                    investorLogin(investors);
                }
                else if(option==2){
                    investorSignup(investors);
                }
                else{
                    cout << "Invalid option. Please choose again.\n";
                }
            }while(option!=3);
        } else if (option == 3) {
            cout << "Exiting...\n";
            running = false;
        } else {
            cout << "Invalid option. Please choose again.\n";
        }
    }
}

