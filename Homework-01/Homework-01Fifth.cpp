// Copyright 2022 Andrew Boothe

#include <iostream>
#include <string>
#include <cctype>

/*
PROGRAM DESCRIPTION: Takes an input of a string and checks
   it with conditions below for the perfect password.
   
LATEST SUBMISSION: Formatting fixes, copyright, importing classes,
   making for loop ints unsigned to prevent comparison warnings
   
- Bulk of work done with Visual Studio Code (see Canvas quiz)
*/

int main() {
    // Declare string input
    std::string password;

    // User input
    std::cin >> password;

    // Variables needed for tests
    bool rightLength = true;
    bool hasLetter;
    bool hasNumber;
    bool hasSpecial;

    // rightLength checker
    if (password.length() < 8) {
        std::cout << "Too short" << std::endl;
        rightLength = false;
    }

    // hasLetter checker
    for (unsigned int i = 0; i <= password.length() -1; i++) {
        if (isalpha(password.at(i))) {
            hasLetter = true;
            break;
        } else {
            hasLetter = false;
        }
    }

    if (!(hasLetter)) {
        std::cout << "Missing letter" << std::endl;
    }

    // hasNumber checker
    for (unsigned int i = 0; i <= password.length() -1; i++) {
        if (isdigit(password.at(i))) {
            hasNumber = true;
            break;
        } else {
            hasNumber = false;
        }
    }

    if (!(hasNumber)) {
        std::cout << "Missing number" << std::endl;
    }

    // hasSpecial checker
    for (unsigned int i = 0; i <= password.length() -1; i++) {
        if (password.at(i) == '#' || password.at(i) == '!' || password.at(i) == '%') {
            hasSpecial = true;
            break;
        } else {
            hasSpecial = false;
        }
    }

    if (!(hasSpecial)) {
        std::cout << "Missing special" << std::endl;
    }

    // Final OK check
    if (rightLength && hasLetter && hasNumber && hasSpecial) {
        std::cout << "OK" << std::endl;
    }
    return 0;
}

