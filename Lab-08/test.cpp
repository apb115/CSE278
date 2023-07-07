// Copyright {C} Andrew Boothe

#include <iostream>
#include <stdexcept>
#include "MyArray.h"

int main() {
    MyArray ints1{1, 2, 3, 4};
    MyArray ints2(3);

    // print ints1 size and content
    std::cout << "ints1 size: " <<ints1.size() << std::endl;
    std::cout << "ints1 content: " <<ints1 << std::endl;

    // print ints2 size and content
    std::cout << "ints2 size: " <<ints2.size() << std::endl;
    std::cout << "ints2 content: " <<ints2 << std::endl;

    // input and print ints1 and ints2
    std::cout << "Enter 3 integers" << std::endl;
    std::cin >> ints2;

    std::cout << "ints1:" << ints1 << std::endl;
    std::cout << "ints2:" << ints2 << std::endl;

    // use overloaded equality (==) operator
    std::cout << "Evaluating ints1 == ints2 " << std::endl;

    if (ints1 == ints2)
        std::cout << "ints1 and ints2 are  equal" << std::endl;
    else
        std::cout << "ints1 and ints2 are not equal" << std::endl;

    // attempt to use out-of-range subscript
    try {
        // use overloaded subscript operator to create an rvalue
       std::cout << "ints1[2] is " << ints1[2] << std::endl;
       // use overloaded subscript operator to create an lvalue
       std::cout << "Assigning 1000 to ints1[2]" << std::endl;
       ints1[2] = 1000;
       std::cout << "ints1: " << ints1 << std::endl;
       std::cout << "Attempt to assign 1000 to ints1[15]" << std::endl;
       ints1[15] = 1000;
    }
    catch(const std::out_of_range& ex) {
        std::cout << "An exception occurred:" << ex.what() << std::endl;
    }
    std::cout << "ints1: " << ints1 << std::endl;
    // add a value to every element of ints2 using +=
    std::cout << "Add 7 to every ints2 element :" << (ints2 +=7);

    
    return 0;
}
