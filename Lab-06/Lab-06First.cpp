// Copyright {C} Andrew Boothe

#include <iostream>

void hideSSN(const char* ssn, char mask, char* maskedssn) {
    int i;
    for (i = 0; ssn[i] != '\0'; i++) {
        maskedssn[i] = ssn[i];
    }
    maskedssn[i] = '\0';
    for (int j = 0; j < i-4; j++) {
        if (maskedssn[j] != '-') {
            maskedssn[j] = mask;
        }
    }
}

int main() {
    char ssn[] = "123-67-890";
    char ssn_masked[12];
    hideSSN(ssn, '*', ssn_masked);
    std::cout << ssn_masked << std::endl;


    return 0;
}