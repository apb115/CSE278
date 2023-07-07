// Copyright {c} Andrew Boothe, February 14th, 2022

#include <iostream>
#include <bitset>
int main() {
    std::bitset<16> test_number(256U);

    std::cout << test_number << std::endl;

    std::cout << test_number.count() << std::endl;

    for (int i = 1; i < test_number.size(); i++) {
        if (test_number[i] == 1)
            std::cout << i << std::endl;
    }
    std::cout << (test_number >> 2).to_ulong() << std::endl;
    return 0;
}
