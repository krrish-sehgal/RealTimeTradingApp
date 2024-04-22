#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

using namespace std;

// Callback function to handle data received from cURL
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int makeCSV(string ticker,string exchange ) {
    // URL of the API endpoint
    std::string apiUrl = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol="+ticker+"&interval=5min&apikey=RCJ9B0SWPD3OSGS6&datatype=csv";
    if(exchange=="NSE")apiUrl = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol="+ticker+".BSE&outputsize=compact&apikey=RCJ9B0SWPD3OSGS6&datatype=csv";


    // Path to the SSL/TLS certificate bundle
    const std::string certPath = "/path/to/cacert.pem"; // Update this with the path to your certificate bundle

    // Initialize cURL
    CURL* curl = curl_easy_init();
    if (!curl) {
        cerr << "Failed to initialize cURL" << endl;
        return 1;
    }

    // Initialize a buffer to store the data received from cURL
    std::string readBuffer;

    // Set cURL options
    curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects

    // Specify the path to the SSL/TLS certificate bundle
    curl_easy_setopt(curl, CURLOPT_CAINFO, certPath.c_str());

    // Temporarily disable SSL verification (use only for testing)
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

    // Perform the HTTP request
    CURLcode res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
        cerr << "cURL request failed: " << curl_easy_strerror(res) << endl;
        curl_easy_cleanup(curl);
        return 1;
    }

    // Cleanup cURL
    curl_easy_cleanup(curl);

    // Write the data to a CSV file
    ofstream csvFile("stock_data.csv");
    if (!csvFile.is_open()) {
        cerr << "Failed to open CSV file for writing" << endl;
        return 1;
    }

    csvFile << readBuffer;
    csvFile.close();


    return 0;
}