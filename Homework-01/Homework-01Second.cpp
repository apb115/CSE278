// Purpose: Statement to test if number is power of two or not
// Copyright by Andrew Boothe , 2/19/2022

/*
SUBMISSION LATEST: Appending loop to reflect use of bitset library
Now, there are no bitwise operators being used, and the condition is met using functions
given in the bitset library. For reference, view 
https://www.cplusplus.com/reference/bitset/bitset/
*/

#include <iostream>
#include <bitset>

int main() {
    
    // Declare num1 and get user input
    unsigned int num1;
    std::cout << "Enter an unsigned integer number:" << std::endl;
    std::cin >> num1;
    // Initialize num1 to a 32 bit number using bitset library

    std::bitset<32> num2(num1);
    std::cout << num1 << " = " << num2 << std::endl;

    // Conditional to determine power of two using bitset library operators
    if (num2.count() > 1) {
        std::cout << "This number is NOT a power of two." << std::endl;
    } else if (!num2.any()) {
       std::cout << "This number is NOT a power of two." << std::endl;
    }   else {
        std::cout << "This number is a power of two." << std::endl;
    }

    return 0;
}
