#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <sstream>
#include <vector>
#include <regex>
#include "gnu/gnuplot-iostream.h"
// #include "gnuplot-cpp/gnuplot_i.hpp"

// Callback function to write response data to a string
size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output) {
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Structure to store daily stock data
struct StockData {
    std::string date;
    double closingPrice;
};

int main() {
    CURL *curl;
    CURLcode res;
    std::string response;

    // Initialize libcurl
    curl = curl_easy_init();
    if (curl) {
        // Set the URL for the API endpoint
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=RELIANCE.BSE&outputsize=full&apikey=HHMA5N5YXWRTT3SP");

        // Set up the write callback function to capture the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            return 1;
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    // Parse the API response and extract daily closing prices
    std::vector<StockData> stockData;
    std::istringstream iss(response);
    std::string line;
    while (std::getline(iss, line)) {
        if (line.find("close") != std::string::npos) {
            std::istringstream ss(line);
            std::string date, close;
            ss >> date >> close;
            // Extract date and closing price
            StockData data;
            data.date = date.substr(1, 10);  // Extracting only the date (YYYY-MM-DD)
            data.closingPrice = std::stod(close);
            stockData.push_back(data);
        }
    }

    // Write data to a file for Gnuplot
    std::ofstream dataFile("stock_data.dat");
    if (dataFile.is_open()) {
        for (const auto& data : stockData) {
            dataFile << data.date << " " << data.closingPrice << std::endl;
        }
        dataFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
        return 1;
    }

    // Use Gnuplot to plot the graph
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        // Gnuplot commands to plot the graph
        fprintf(gnuplotPipe, "set title 'Stock Prices'\n");
        fprintf(gnuplotPipe, "set xlabel 'Date'\n");
        fprintf(gnuplotPipe, "set ylabel 'Closing Price'\n");
        fprintf(gnuplotPipe, "plot 'stock_data.dat' using 1:2 with lines\n");
        fflush(gnuplotPipe);
        // Close the pipe
        pclose(gnuplotPipe);
    } else {
        std::cerr << "Gnuplot not found or failed to open." << std::endl;
        return 1;
    }

    return 0;
}