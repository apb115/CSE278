// Copyright 2022 Andrew Boothe

#include <iostream>
#include <string>
#include <cmath>

int main() {
    // Declare initial variables
    int wages;
    int taxInterest;
    int unemCompensation;
    int status;
    int taxWithheld;

    // Additional variables
    int deduction;
    int taxIncome;
    double taxAmount;
    int taxDue;

    // User input for all necessary fields
    std::cin >> wages;
    std::cin >> taxInterest;
    std::cin >> unemCompensation;
    std::cin >> status;
    std::cin >> taxWithheld;

    // Condition to determine status
    if (status != 1 && status != 2) {
        status = 1;
    }

    // Calculate and print average gross income
    int agi = wages + taxInterest + unemCompensation;
    std::cout << "AGI: $" << agi << std::endl;

    // Conditional to prevent too high AGI
    if (agi > 120000) {
        std::cout << "Error: Income too high to use this form" << std::endl;
        return 0;
    }

    // Condition for deductions
    if (status == 1) {
        deduction = 12000;
        std::cout << "Deduction: $" << deduction << std::endl;
    } else {
        deduction = 24000;
        std::cout << "Deduction: $" << deduction << std::endl;
    }

    // Taxable income conditions
    taxIncome = agi - deduction;
    if (taxIncome < 0) {
        taxIncome = 0;
        std::cout << "Taxable income: $" << taxIncome << std::endl;
        return 0;
    } else {
        std::cout << "Taxable income: $" << taxIncome << std::endl;
    }

    // Conditions for tax amount
    if (status == 1) {
        if (taxIncome >= 0 && taxIncome <= 10000) {
            taxAmount = .10 * taxIncome;
        } else if (taxIncome >= 10001 && taxIncome <= 40000) {
            taxAmount = 1000 + (.12 * (taxIncome - 10000));
        } else if (taxIncome >= 40001 && taxIncome <= 85000) {
            taxAmount = 4600 + (.22 * (taxIncome - 40000));
        } else if (taxIncome > 85000) {
            taxAmount = 14500 + (.24 * (taxIncome - 85000));
        } else {
            return 0;
        }
    } else {
        if (taxIncome >= 0 && taxIncome <= 20000) {
            taxAmount = .10 * taxIncome;
        } else if (taxIncome >= 20001 && taxIncome <= 80000) {
            taxAmount = 2000 + (.12 * (taxIncome - 20000));
        } else if (taxIncome > 80000) {
            taxAmount = 9200 + (.22 * (taxIncome - 80000));
        } else {
            return 0;
        }
    }
    // Prints taxAmount
    std::cout << "Federal tax: $" << round(taxAmount) << std::endl;

    // taxDue conditional
    taxDue = taxAmount - taxWithheld;
    if (taxDue < 0) {
        std::cout << "Tax refund: $" << -taxDue << std::endl;
    } else {
        std::cout << "Taxes Owed: $" << taxDue << std::endl;
    }

    return 0;
}
