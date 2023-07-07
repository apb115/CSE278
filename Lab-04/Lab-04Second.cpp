// Copyright 2/22/2022 Andrew Boothe

#include <iostream>
#include <string>

std::string letterCheck(std::string s1);



int main() {
    
    std::cout << letterCheck("This !$ @ sentence.") << std::endl;
    std::cout << letterCheck("-Hello, 1 world$!") << std::endl;
    std::cout << letterCheck("Look!    Multiple spaces.") << std::endl;
    std::cout << letterCheck("flying") << std::endl;

    return 0;
}

std::string letterCheck(std::string s1) {
    std::string s2 = "";
    for (int i = 0; i < s1.length(); i++) {
        if (isalpha(s1[i])) {
            s2 += s1[i];
        }
    }
    return s2;
}
