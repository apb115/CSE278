// Copyright 2/21/2022 Andrew Boothe

#include <iostream>

// function prototypes or function declarations
template<typename T>
int GenericCheckOrder(T num1, T num2, T num3, T num4);


int main() {
    // Test 1
    std::cout << "100 200 300 400" << std::endl;
    std::cout << GenericCheckOrder(100, 200, 300, 400) << std::endl;  // pass-by value

    // Test 2
    std::cout << "400.6, 300.34, 200.56, 100.0078" << std::endl;
    std::cout << GenericCheckOrder(400.6, 300.34, 200.56, 100.0078) << std::endl;  // pass-by value

    // Test 3
    std::cout << "'a', 'b', 'z', 'g'" << std::endl;
    std::cout << GenericCheckOrder('a', 'b', 'z', 'g') << std::endl;  // pass-by value

    // Test 4
    std::cout << " bat, hat, mat, sat " << std::endl;
    std::cout << GenericCheckOrder("bat", "hat", "mat", "sat") << std::endl;  // pass-by reference


    return 0;
}

template<typename T>
int GenericCheckOrder(T num1, T num2, T num3, T num4) {
    if ((num1 < num2) && (num2 < num3) && (num3 < num4)) {
        return -1;
    } else if ((num4 < num3) && (num3 < num2) && (num2 < num1)) {
        return 1;
    } else {
        return 0;
    }
}
