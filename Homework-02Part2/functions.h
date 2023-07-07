// Copyright Andrew Boothe 3/14/2022

/*
LATEST SUBMISSION: 
   Reducing parameter variables necessary in declarations
   Cleaning up comments
*/

#ifndef FUNCTIONS_H  // HOMEWORK_02PART2_FUNCTIONS_H_
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


// function prototypes or function declarations
void listNames(ifstream& inputR, vector<std::string> name, int index);
void shiftDays(vector<std::string> name, vector<std::string> days);
void listNursesByDay(std::vector<std::string> name, std::vector<std::string> days);
void daysThatAllWork(std::vector<std::string> days);
void daysThatNoWork(std::vector<std::string> days);
void printMenu(std::string filename);

#endif  // HOMEWORK_02PART2_FUNCTIONS_H_
