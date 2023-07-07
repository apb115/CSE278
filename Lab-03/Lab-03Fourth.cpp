// Copyright {c} Andrew Boothe, February 14th, 2022

#include <iostream>

int main() {
uint16_t findMeInBinary;

std::cout << "Enter an unsigned integer" << std::endl;
std::cin  >> findMeInBinary;

uint16_t mask = 1 << 15;
if (( findMeInBinary & mask) == 0)
    std::cout << "0" << std::endl;
else
    std::cout << "1" << std::endl;

mask = 1<<1;
if (( findMeInBinary & mask) == 0)
    std::cout << "0" << std::endl;
else
    std::cout << "1" << std::endl;

return 0;
}
