// Copyright {C} Andrew Boothe
// Purpose: Code to take input from a file and
//    relay a menu of repeated options


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std;

// Function to print out values of names separated by new lines
void listNames(ifstream& inputR, vector<std::string> name, int index) {
    for (int i = 0; i < index; i++) {
        std::cout << name[i] << std::endl;
    }
}

// Function that inputs file vals,
//    prints a menu, and takes user input
//    about menu actions
void printMenu(std::string filename) {
    // Declare variables for parsing through file
    ifstream inputR(filename);
    std::vector<std::string> name(100);
    std::vector<int> days(100);
    int option;
    bool repeater = true;

    // Closes code if filename is not recognized
    if (!inputR.is_open()) {
        std::cout << "!!! Could not open the input file : " << filename << std::endl;
        return;
    }

    int index = -1;
    while (!inputR.fail()) {
        index++;
       // if (name.at(index) )
        inputR >> name.at(index);
        inputR >> days.at(index);
    }
    inputR.close();

    while (repeater) {
        std::cout << "--------------------------------" << std::endl;
        std::cout << " Nurse Shift Query Application" << std::endl;
        std::cout << "--------------------------------" << std::endl;

        std::cout << " 1 List shift days of the nurse" << std::endl;
        std::cout << " 2 List nurses for the day" << std::endl;
        std::cout << " 3 List days that all nurses work" << std::endl;
        std::cout << " 4 List days no nurse works" << std::endl;
        std::cout << " 5 List names of nurses" << std::endl;
        std::cout << "-1 Exit" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << ">> Enter your choice:" << std::endl;
        std::cin >> option;

        if (option > 5 || option < -1 || option == 0) {
            std::cout << " !! Wrong choice !! Try again!" << std::endl;
        } else if (option == -1) {
            std::cout << "Bye!" << std::endl;
            repeater = false;
        } else if (option == 1) {
            std::cout << "List shift days of the nurse" << std::endl;
        } else if (option == 2) {
            std::cout << "List nurses for the day" << std::endl;
        } else if (option == 3) {
            std::cout << "List days that all nurses work" << std::endl;
        } else if (option == 4) {
            std::cout << "List days no nurse works" << std::endl;
        } else if (option == 5) {
            std::cout << "--- Names of Nurses ---" << std::endl;
            listNames(inputR, name, index);
        }
    }
}
