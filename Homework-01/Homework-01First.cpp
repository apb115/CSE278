// Copyright 2022, Andrew Boothe
// Purpose: Checks a given integer to see if it is odd or even

/*
SUBMISSION UPDATES:
Latest submission(2/19/2022): Formatting user input statement, commenting
*/

#include <iostream>

int main() {
  
// Initializes input variable
  int num1;

// User input
  std::cout << "Enter an integer number" << std::endl;
  std::cin >> num1;

// | operator iterates through every bit of num1, if the last bit in num1
//    is a one, then the number must be even
  if ((num1 | 1) > num1) {
      std::cout << num1 <<  " is an even number." << std::endl;
  } else {
      std::cout << num1 << " is an odd number." << std::endl;
  }

    return 0;
}
