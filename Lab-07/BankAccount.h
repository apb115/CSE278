#ifndef BANKACCOUNTH
#define BANKACCOUNTH

#include <string>


class BankAccount {
   public:
      BankAccount(std::string newName = "", double amt1 = 0.0, double amt2 = 0.0);
      void SetName(std::string newName);
      std::string GetName();
      void SetChecking(double amt);
      double GetChecking();
      void SetSavings(double amt);
      double GetSavings();
      void DepositChecking(double amt);
      void DepositSavings(double amt);
      void WithdrawChecking(double amt);
      void WithdrawSavings(double amt);
      void TransferToSavings(double amt);
      
   private:
      std::string name;
      double savingsBal;
      double checkingBal;
};

#endif