#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "BankAccount.h"

class Bank {
 public:
    Bank(std::string name);
    void SetBankName(std::string newName);
    std::string GetBankName();
    void AddCustomer(BankAccount b);
    void DropCustomer(std::string name);
    int GetSizeofBank();
    double GetTotalSavings();
    double GetTotalChecking();
    BankAccount GetTheRichestCustomer();
 private:
    std::string bankName;
    std::vector<BankAccount> customers;
};

#endif