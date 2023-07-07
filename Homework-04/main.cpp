/*
Copyright: Vimal Vinod, Andrew Boothe
Purpose: Query Airport database application
Date: May 3, 2022
*/

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "./functions.h"

int main() {
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278", "localhost", "cse278",
    "wVQABsJFQhwNdNbr");

    // For user choice
    int inpIn = -1;

    // While not 5, the code inside keeps going back to menu
    while (inpIn != 5) {
        // Prints menu to give user choices 
        printMenu();
        // Takes in the user input and converts
        // string into an integer
        std::string input;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> input;
        inpIn = std::stoi(input);
        std::cout << std::endl;
        
        if (inpIn == 1) {
            // If choice 1 do this
            optionOne();
            std::cout << std::endl;
        } else if (inpIn == 2) {
            // If choice 2 do this
            optionTwo();
            std::cout << std::endl;
        } else if (inpIn == 3) {
            // If choice 3 do this
            optionThree();
            std::cout << std::endl;
        } else if (inpIn == 4) {
            // If choice 4 do this
            optionFour();
            std::cout << std::endl;
        } else if (!(inpIn <= 5 && inpIn >= 1)) {
            // If not between 1-5, do this
            std::cout << "Wrong input! Try again!" << std::endl;
            std::cout << std::endl;
        } else if (inpIn == 5) {
            // If 5, exit loop and end program
            std::cout <<
            "You have chosen to exit the program. Bye!" << std::endl;
            std::cout << std::endl;
            break;
        }
    }
}
