// Purpose: Tests if number is power of two using loops instead of bitset library
// Copyright by Andrew Boothe, 2/19/2022

/*
LATEST SUBMISSION (2/19/2022): Added in condition for 0 unsigned int value
How the for loop works: iterates through all 32 bits of a number, if the shifted
mask AND the num1 values are set as 1, then 1 is printed in that space. Otherwise,
0 is printed.

How the if conditions work:
Since in a 32 bit string the twos complement of a number is a power of 2, we compare
the opposite of a number and that number to equal 0. If it does, it's a power of 2,
if not, it is not. A condition for 0 is also necessary.


*/

#include <iostream>

int main() {
    // User input
    uint32_t num1;
    std::cout << "Enter an unsigned integer number:" << std::endl;
    std::cin >> num1;
    std::cout << num1 << " = ";

    // Loop for printing out bits
    for (int i = 31; i >= 0; i--) {
        uint32_t mask = 1 << i;
        if ((num1 & mask) == 0) {
            std::cout << "0";
        } else {
            std::cout << "1";
        }
    }
    std::cout << std::endl;

    if ((num1 & (num1- 1)) != 0) {
        std::cout << "This number is NOT a power of two." << std::endl;
    } else if (num1 == 0) {
        std::cout << "This number is NOT a power of two." << std::endl;
    }   else {
        std::cout << "This number is a power of two." << std::endl;
    }

    return 0;
}
