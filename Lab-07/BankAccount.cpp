m#include <iostream>
#include "BankAccount.h"


// TODO: Define public member functions
BankAccount::BankAccount(std::string newName, double amt1, double amt2) {
         name = newName;
         checkingBal = amt1;
         savingsBal = amt2;
}
void BankAccount::SetName(std::string newName) {
   name = newName;

}
std::string BankAccount::GetName() {
   return name;
}
void BankAccount::SetChecking(double amt) {
   checkingBal = amt;

}
double BankAccount::GetChecking() {
   return checkingBal;
}
void BankAccount::SetSavings(double amt) {
   savingsBal = amt;   
}
double BankAccount::GetSavings() {
   return savingsBal;   
}
void BankAccount::DepositChecking(double amt) {
   if (amt < 0) {
      return;  
   }
   checkingBal += amt;

}
void BankAccount::DepositSavings(double amt) {
   if (amt < 0) {
      return;  
   }
    savingsBal += amt;   
}
void BankAccount::WithdrawChecking(double amt) {
   if (amt < 0) {
      return;  
   }
   checkingBal -= amt; 
}
void BankAccount::WithdrawSavings(double amt) {
   if (amt < 0) {
      return;  
   }
   savingsBal -= amt;    
}
void BankAccount::TransferToSavings(double amt) {
    if (amt < 0) {
      return;  
   }
   checkingBal -= amt;
   savingsBal += amt;
}

