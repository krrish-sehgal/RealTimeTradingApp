#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Include the Gnuplot C++ header
#include "gnuplot-cpp/gnuplot_i.hpp"
int main() {
    // Create a Gnuplot object
    Gnuplot gp;

    gp << "set terminal png\n";
    gp << "set output 'plot.png'\n";

    // Set the style of the plot
    gp << "set style line 1 lt 1 lw 2 lc rgb 'blue'\n";

    // Set the title of the plot
    gp << "set title 'Simple Plot'\n";

    // Set the labels for the x and y axes
    gp << "set xlabel 'X'\n";
    gp << "set ylabel 'Y'\n";

    // Define the function to plot (here, we'll plot a sine function)
    gp << "plot sin(x) with lines linestyle 1 title 'Sin(x)'\n";

    // Wait for user input before closing the plot window
    std::cout << "Press enter to exit..." << std::endl;
    std::cin.get();

    return 0;
}
