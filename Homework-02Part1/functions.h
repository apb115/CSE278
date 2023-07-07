// Copyright 3/02/2022 Andrew Boothe

/*
Latest Submission: Changing parameters on printMenu
   to account for more code
*/

#ifndef FUNCTIONS_H  // HOMEWORK_02PART1_FUNCTIONS_H_
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


// function prototypes or function declarations
void listNames(ifstream& inputR, vector<std::string> name, int index);
void printMenu(std::string filename);

#endif  // HOMEWORK_02PART1_FUNCTIONS_H_
