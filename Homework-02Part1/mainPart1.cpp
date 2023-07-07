// Copyright {C} Andrew Boothe
// Purpose: Code to take input from a file and
//    relay a menu of repeated options


/*
Latest Submission: Cleaned up code, fixed formatting, 
   added extra comments, made vector limits larger
   to account for more elements being parsed through
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "functions.h"
using namespace std;

int main() {
    // Asks for user input of the filename
    std::string filename;
    std::cout << ">> Enter the file name with its extension:" << std::endl;
    std::cin >> filename;

    printMenu(filename);
    return 0;
}
