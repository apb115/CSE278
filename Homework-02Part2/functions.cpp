// Copyright {C} Andrew Boothe 3/14/2022
// Purpose: Code to take input from a file and
//    relay a menu of repeated options

/*
LATEST SUBMISSION (functions.cpp): 
   Overhauled daysThatAllWork and daysThatNoWork functions
   Changed for-loop iteration for optimal date printing
   Reset size values for input vectors
   Edited text and added instruction comments
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "functions.h"
using namespace std;

// Purpose: List all corresponding names
// Parameters: inputR (reference since textfile inputs do not change),
//    name (all names in input vector), index(const since it will not change)
void listNames(ifstream& inputR, vector<std::string> name, const int index) {
    for (int i = 0; i < index; i++) {
        std::cout << name[i] << std::endl;
    }
}
// Purpose: List corresponding shift days to a name
// Parameters: name(all names in input vector),
//    days (all days in input vector)
// WHY:
//    do while loop for space efficiency since only one mother loop is
//       repeatedly executed (SPACE EFFICIENCY)
//    two input vectors since they contain all necessary vals (WHY PARAMS)
void shiftDays(vector<std::string> name, vector<std::string> days) {
    std::vector<std::string> week1{"Saturday", "Friday", "Thursday", "Wednesday", "Tuesday", "Monday", "Sunday"};
    int index = 100;
    bool nameCheck = true;
    do {
        std::string name1;
        std::cout << ">> Enter a nurse name: " << std::endl;
        std::cin >> name1;

        for (unsigned int i = 0; i < name.size(); i++) {
            // Compares ignoring case
            if (strcasecmp(name.at(i).c_str(), name1.c_str()) == 0) {
                index = i;
                break;
            }
        }
        if (index == 100) {
            std::cout << "!!! No record for " << name1 << std::endl;
        } else {
            int shiftCount = 0;
            std::cout << "---- Shift Days ----" << std::endl;
            for (int i = 6; i >= 0; i--) {
                if (days.at(index).at(i) == '1') {
                    std::cout << week1.at(i) << std::endl;
                    shiftCount++;
                }
            }
            if (shiftCount == 0) {
                std::cout << name1 << " does not have a shift this week" << std::endl;
            }
            nameCheck = false;
        }
    } while (nameCheck);
}

// Purpose: List corresponding nurses to a shift day
// Parameters: name(all names in input vector),
//    days (all days in input vector)
// WHY:
//    do while loop for space efficiency since only one mother loop is
//       repeatedly executed for input (SPACE EFFICIENCY)
//    two input vectors since they contain all necessary vals (WHY PARAMS)
void listNursesByDay(std::vector<std::string> name, std::vector<std::string> days) {
    std::string dayOfWeek;
    std::vector<std::string> week2{"saturday", "friday", "thursday", "wednesday", "tuesday", "monday", "sunday"};
    int iterate = 0;
    bool firstDo = true;
    do {
        std::cout << ">> Enter a day of the week:" << std::endl;
        std::cin >> dayOfWeek;

        // lowers case
        for (unsigned int i = 0; i < dayOfWeek.size(); i++) {
        dayOfWeek.at(i) = std::tolower(dayOfWeek.at(i));
        }

        for (int i = 6; i >= 0; i--) {
            if (week2.at(i) == dayOfWeek) {
                // Gives index of day of week in shift strings
                iterate = i;
                firstDo = false;
            }
        }
    } while (firstDo);

    std::cout << "----Nurses----" << std::endl;
    int count2 = 0;
    for (unsigned int i = 0; i < days.size(); i++) {
            if (days.at(i).at(iterate) == '1') {
                std::cout << name.at(i) << std::endl;
                count2++;
            }
    }

    // uppers case
    for (unsigned int i = 0; i < dayOfWeek.size(); i++) {
        dayOfWeek.at(i) = std::toupper(dayOfWeek.at(i));
    }
    std::cout << count2 << " nurse(s) work(s) on " << dayOfWeek << std::endl;
}

// Purpose: List days that all work
// Parameters: days (all days in input vector)
// WHY:
//    Nested for loop to check for each shift day set and
//       each day worked, then printing from a stored vector
//       to offset any other needed loops to iterate
//       through days (SPACE EFFICIENCY)
//    one input vector since it contains all days and names
//       are not needed (WHY PARAMS)
void daysThatAllWork(std::vector<std::string> days) {
    std::vector<std::string> week3{"Saturday", "Friday", "Thursday", "Wednesday", "Tuesday", "Monday", "Sunday"};
    // Blank vector to add counts
    std::vector<unsigned int> increment{0, 0, 0, 0, 0, 0, 0};

    std::cout << "--- Days that all nurses work ---" << std::endl;
    for (unsigned int i = 0; i < days.size(); i++) {
        for (int j = 6; j >= 0; j--) {
            if (days.at(i).at(j) == '1') {
                // adds counts for each day
                increment.at(j) += 1;
            }
        }
    }
    bool isAllDay = true;
    unsigned int sizeCheck = days.size();

    for (int k = increment.size()-1; k >= 0; k--) {
        // prints where days are worked by all
        if (increment.at(k) == sizeCheck) {
            std::cout << week3.at(k) << std::endl;
            isAllDay = false;
        }
    }

    if (isAllDay) {
        // If boolean is never changed and all nurses don't work together in a day
        std::cout << "There is no day that all nurses work!" << std::endl;
    }
}

// Purpose: List days that no work
// Parameters: days (all days in input vector)
// WHY:
//    Nested for loop to check for each shift day set and
//       each day worked, then printing from a stored vector
//       to offset any other needed loops to iterate
//       through days (SPACE EFFICIENCY)
//    one input vector since it contains all days and names
//       are not needed (WHY PARAMS)
void daysThatNoWork(std::vector<std::string> days) {
    std::vector<std::string> week3{"Saturday", "Friday", "Thursday", "Wednesday", "Tuesday", "Monday", "Sunday"};
    // blank vector to increment non-worked days
    std::vector<unsigned int> increment{0, 0, 0, 0, 0, 0, 0};

    std::cout << "--- Days no nurse works ---" << std::endl;
    for (unsigned int i = 0; i < days.size(); i++) {
        for (int j = 6; j >= 0; j--) {
            if (days.at(i).at(j) == '0') {
                // Adds values to days when isn't worked
                increment.at(j) += 1;
            }
        }
    }
    bool isAllDay = true;
    unsigned int sizeCheck = days.size();

    for (int k = increment.size()-1; k >= 0; k--) {
        if (increment.at(k) == sizeCheck) {
            // prints where days are worked by none
            std::cout << week3.at(k) << std::endl;
            isAllDay = false;
        }
    }

    if (isAllDay) {
        // If boolean is never changed and all days are worked by >= 1
        std::cout << "Each day at least one nurse has a shift!" << std::endl;
    }
}

// Purpose: Print menu options
// Parameters: filename (name will not change
//    with running)
// WHY:
//    do while loop to repeat and prevent unnecessary iteration
//       (SPACE EFFICIENCY)
//    one filename since that is the only needed name
//       to iterate through file (WHY PARAMS)
void printMenu(std::string filename) {
    // Declare variables for parsing through file
    ifstream inputR(filename);
    std::vector<std::string> name;
    std::vector<std::string> days;
    int option;
    bool repeater = true;

    // Closes code if filename is not recognized
    if (!inputR.is_open()) {
        std::cout << "!!! Could not open the input file : " << filename << std::endl;
        return;
    }

    int index = -1;
    while (!inputR.fail()) {
        index++;
        std::string val = "";
        inputR >> val;
        if (val.size() > 0) {
            name.push_back(val);
        }
        std::string num = "";
        inputR >> num;
        if (num.size() > 0) {
            days.push_back(num);
        }
    }
    inputR.close();

    while (repeater) {
        std::cout << "--------------------------------" << std::endl;
        std::cout << " Nurse Shift Query Application" << std::endl;
        std::cout << "--------------------------------" << std::endl;

        std::cout << " 1 List shift days of the nurse" << std::endl;
        std::cout << " 2 List nurses for the day" << std::endl;
        std::cout << " 3 List days that all nurses work" << std::endl;
        std::cout << " 4 List days no nurse works" << std::endl;
        std::cout << " 5 List names of nurses" << std::endl;
        std::cout << "-1 Exit" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << ">> Enter your choice:" << std::endl;
        std::cin >> option;

        if (option > 5 || option < -1 || option == 0) {
            std::cout << "!! Wrong choice !! Try again!" << std::endl;
        } else if (option == -1) {
            std::cout << "Bye!" << std::endl;
            repeater = false;
        } else if (option == 1) {
            shiftDays(name, days);
        } else if (option == 2) {
            listNursesByDay(name, days);
        } else if (option == 3) {
            daysThatAllWork(days);
        } else if (option == 4) {
            daysThatNoWork(days);
        } else if (option == 5) {
            std::cout << "--- Names of Nurses ---" << std::endl;
            listNames(inputR, name, index);
        }
    }
}
