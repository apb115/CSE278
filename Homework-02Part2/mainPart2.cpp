// Copyright {C} Andrew Boothe 3/14/2022
// Purpose: Code to take input from a file and
//    relay a menu of repeated options
//    to detail a file of nurse names and shifts

/*
LATEST SUBMISSION (main.cpp): 
   Deleted misc. comments from unimplemented code
   Edited text and added instruction comments
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


    // activates central function with all other helper functions inside it
    printMenu(filename);

    // ends code
    return 0;
}
