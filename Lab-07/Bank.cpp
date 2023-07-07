// implementation of Bank members
#include <iostream>
#include "Bank.h"
#include "BankAccount.h"
#include <string>
#include <vector>

Bank::Bank(std::string name) {
   bankName = name;
}
void Bank::SetBankName(std::string newName) {
   bankName = newName;
}
std::string Bank::GetBankName() {
   return bankName;
}
void Bank::AddCustomer (BankAccount b) {
   customers.push_back(b);
}
void Bank::DropCustomer (std::string name) {
   for (unsigned int i = 0; i < customers.size(); i++) {
       if (customers.at(i).GetName() == name) {
           customers.erase(customers.begin() + i);
           return;
       }
   }
}
int Bank::GetSizeofBank () {
   return customers.size();
}
double Bank::GetTotalSavings() {
    double total;
   for (unsigned int i = 0; i < customers.size(); i++) {
       total += customers.at(i).GetSavings();
   }
   return total;
}

double Bank::GetTotalChecking() {
   double total;
   for (unsigned int i = 0; i < customers.size(); i++) {
       total += customers.at(i).GetChecking();
   }
   return total;
}

BankAccount Bank::GetTheRichestCustomer() {
    if (customers.size() == 0) return BankAccount();
    BankAccount richest;
    int position;
    double max;
    for (unsigned int i = 0; i < customers.size(); i++) {
        if (customers.at(i).GetSavings() + customers.at(i).GetChecking() > max) {
           max = customers.at(i).GetSavings() + customers.at(i).GetChecking();
            position = i;
        }
    }
    
   return customers.at(position);
}