#pragma once

#include<bits/stdc++.h>
using namespace std;

float getRealTimePrice(string ticker, string exchange) {

    std::stringstream cmd;
    cmd << "python3 ../stockDataWork/sendRealTimePriceToHeader.py " << ticker << " " << exchange;

    FILE* pipe = popen(cmd.str().c_str(), "r");
    if (!pipe) {
        std::cerr << "Error executing Python script." << std::endl;
        return 1;
    }

    char buffer[128];
    std::string result = "";
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr) {
            result += buffer;
        }
    }
    pclose(pipe);

    float price = std::stof(result);
    // std::cout << "Real-time price of " << ticker << " on " << exchange << " is: " << price << std::endl;

    return price;
}