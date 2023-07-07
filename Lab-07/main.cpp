#include <iostream>
#include <iomanip>
#include "Bank.h"


int main() {
    Bank bank("Chase");
    bank.AddCustomer(BankAccount("Tara", 500.00, 1000.00));
    bank.AddCustomer(BankAccount("Norm", 100.00, 300.00));
    bank.AddCustomer(BankAccount("Joe", 800.00, 400.00));

    std::cout << bank.GetBankName() << " has "<< bank.GetSizeofBank() << " customer(s)." << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total savings amount : " << bank.GetTotalSavings() << std::endl;
    std::cout << "Total checking amount : " << bank.GetTotalChecking() << std::endl;
    std::cout << "The richest customer : " << bank.GetTheRichestCustomer().GetName() << std::endl;

    bank.DropCustomer("Tara");
    std::cout << "The second richest customer : " << bank.GetTheRichestCustomer().GetName() << std::endl;
    return 0;
}
