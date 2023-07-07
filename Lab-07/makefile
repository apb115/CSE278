main : main.o Bank.o BankAccount.o
	g++ main.o Bank.o BankAccount.o -o main
main.o : main.cpp Bank.cpp BankAccount.cpp
	g++ -c main.cpp -o main.o
Bank.o : Bank.cpp
	g++ -c Bank.cpp -o Bank.o
BankAccount.o : BankAccount.cpp
	g++ -c BankAccount.cpp -o BankAccount.o