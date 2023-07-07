// Copyright 2/21/2022 Andrew Boothe

#include <iostream>

// function prototypes or function declarations
int CheckOrder(int num1, int num2, int num3, int num4);
int CheckOrder(double num1, double num2, double num3, double num4);
int CheckOrder(char ch1, char ch2, char ch3, char ch4);
int CheckOrder(const std::string s1, const std::string s2, const std::string s3, const std::string s4);


int main() {
    // Test 1
    std::cout << "100 200 300 400" << std::endl;
    std::cout << CheckOrder(100, 200, 300, 400) << std::endl;  // pass-by value

    // Test 2
    std::cout << "400.6, 300.34, 200.56, 100.0078" << std::endl;
    std::cout << CheckOrder(400.6, 300.34, 200.56, 100.0078) << std::endl;  // pass-by value

    // Test 3
    std::cout << "'a', 'b', 'z', 'g'" << std::endl;
    std::cout << CheckOrder('a', 'b', 'z', 'g') << std::endl;  // pass-by value

    // Test 4
    std::cout << " bat, hat, mat, sat " << std::endl;
    std::cout << CheckOrder("bat", "hat", "mat", "sat") << std::endl;  // pass-by reference


    return 0;
}

int CheckOrder(int num1, int num2, int num3, int num4) {
    if ((num1 < num2) && (num2 < num3) && (num3 < num4)) {
        return -1;
    } else if ((num4 < num3) && (num3 < num2) && (num2 < num1)) {
        return 1;
    } else {
        return 0;
    }
}

int CheckOrder(double num1, double num2, double num3, double num4) {
    if ((num1 < num2) && (num2 < num3) && (num3 < num4)) {
        return -1;
    } else if ((num4 < num3) && (num3 < num2) && (num2 < num1)) {
        return 1;
    } else {
        return 0;
    }
}

int CheckOrder(char ch1, char ch2, char ch3, char ch4) {
    if ((ch1 < ch2) && (ch2 < ch3) && (ch3 < ch4)) {
        return -1;
    } else if ((ch4 < ch3) && (ch3 < ch2) && (ch2 < ch1)) {
        return 1;
    } else {
        return 0;
    }
}

int CheckOrder(const std::string s1, const std::string s2, const std::string s3, const std::string s4) {
    if ((s1 <= s2) && (s2 <= s3) && (s3 <= s4)) {
        return -1;
    } else if ((s4 < s3) && (s3 < s2) && (s2 < s1)) {
        return 1;
    } else {
        return 0;
    }
}
