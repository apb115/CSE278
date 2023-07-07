/*
Copyright: Vimal Vinod, Andrew Boothe
Purpose: To implement the functions in the header file
Date: 4/27/22
*/

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "./functions.h"

void printMenu() {
    // Prints out choices for the user to read
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "          Airport Query Application          " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << " 1. Find airports in Germany by City" << std::endl;
    std::cout << " 2. Find airports in Germany by City and Code" << std::endl;
    std::cout << " 3. Summarize airports in Germany by criterion" << std::endl;
    std::cout << " 4. Summarize all airports in Germany" << std::endl;
    std::cout << " 5. Exit" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}
// Prints out city names in the Airports table
void cityNames() {
    // Connects to the server
    mysqlpp::Connection myDB("cse278", "localhost", "cse278",
    "wVQABsJFQhwNdNbr");

    // Prints out a list of cities in Germany
    std::cout << "Here are sample city names in Germany:" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    mysqlpp::Query query01 = myDB.query();
    // Limits the number printed out to 5 only
    query01 << "SELECT City FROM Airports ";
    query01 << "WHERE Country LIKE 'Germany' LIMIT 5;";
    query01.parse();
    mysqlpp::StoreQueryResult result01 = query01.store();
    // Prints out the 2d array
    for (const auto& row : result01) {
        for (const auto& col : row) {
            std::cout << "- " << col << "\n";
        }
    }
    std::cout << "---------------------------------------------" << std::endl;
}
// If user enters in option 1
void optionOne() {
    // Connects to the server
    mysqlpp::Connection myDB("cse278", "localhost", "cse278",
    "wVQABsJFQhwNdNbr");
    // Prints out the city names
    cityNames();
    std::cout << std::endl;
    // Makes user enter in city and takes in that input
    std::string opt1;
    std::cout << "Enter the city name in Germany: ";
    std::cin >> opt1;
    // Create a query
    mysqlpp::Query query02 = myDB.query();
    // Queries the table for this statement
    query02 << "SELECT Name, Code, City FROM Airports ";
    query02 << "WHERE Country = 'Germany' AND City Like '%0';";
    query02.parse();
    // Gives the query the input from user
    mysqlpp::StoreQueryResult result02 = query02.store(opt1);
    std::cout << std::endl;
    // Prints out the 2d array in a manner that allows adequate spacing
    std::cout << std::left << std::setw(30) << "Name" << std::left <<
    std::setw(30) <<
    "Code" << std::left << std::setw(30) << "City" << std::endl;
    for (const auto& row : result02) {
        for (const auto& col : row) {
            std::cout << std::left << std::setw(30)
            << col << std::left << std::setw(30);
        }
        std::cout << std::endl;
    }
}
// If user enters in option 2
void optionTwo() {
    // Connects to the server
  
    mysqlpp::Connection myDB("cse278", "localhost", "cse278",
    "wVQABsJFQhwNdNbr");

    // Prints out a list of cities in Germany
    std::cout << "Here are sample city names in Germany:" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    mysqlpp::Query query01 = myDB.query();
    // Limits the number printed out to 5 only
    query01 << "SELECT City FROM Airports ";
    query01 << "WHERE Code != '' AND Country LIKE 'Germany' LIMIT 5;";
    query01.parse();
    mysqlpp::StoreQueryResult result01 = query01.store();
    // Prints out the 2d array
    for (const auto& row : result01) {
        for (const auto& col : row) {
            std::cout << "- " << col << "\n";
        }
    }
    std::cout << "---------------------------------------------" << std::endl;
    // Makes user enter in city name and collects input
    std::string opt2City;
    std::cout << "Enter the city name: ";
    std::cin >> opt2City;
    std::cout << std::endl;
    // Prints out a sample list of airport codes
    std::cout << "Here is a list of sample airport codes from " << opt2City <<
    std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    mysqlpp::Query query04 = myDB.query();
    query04 << "SELECT Code FROM Airports ";
query04 << "WHERE Code != '' AND Country = 'Germany' AND City Like '%0' LIMIT 5;";
    query04.parse();
    mysqlpp::StoreQueryResult result04 = query04.store(opt2City);

    for (const auto& row : result04) {
        for (const auto& col : row) {
            std::cout << "- " << col << "\n";
        }
    }
    std::cout << "---------------------------------------------" << std::endl;
    // Makes user enter in code and collects input
    std::string opt2Code;
    std::cout << "Enter the code name: ";
    std::cin >> opt2Code;
    std::cout << std::endl;
    // Queries the database about an entry with those
    // traits set out by user and prints it
    mysqlpp::Query query05 = myDB.query();
    query05 << "SELECT Name, Code, City FROM Airports ";
query05 << "WHERE Country = 'Germany' AND City Like '%0' AND Code Like '%1';";
    query05.parse();
    mysqlpp::StoreQueryResult result05 = query05.store(opt2City, opt2Code);
    std::cout << std::endl;
    std::cout << std::left << std::setw(30) << "Name" << std::left <<
    std::setw(30)
    << "Code" << std::left << std::setw(30) << "City" << std::endl;
    for (const auto& row : result05) {
        for (const auto& col : row) {
           
std::cout << std::left << std::setw(30) << col << std::left << std::setw(30);
        }
        std::cout << std::endl;
    }
}
// If user enters in option 3
void optionThree() {
    // Connects to the server
    mysqlpp::Connection myDB("cse278", "localhost", "cse278",
    "wVQABsJFQhwNdNbr");

    // Gives users a list of selection criteria
    std::cout << "Here is a list of some selection criteria: " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "- " << "ID" << std::endl;
    std::cout << "- " << "Name" << std::endl;
    std::cout << "- " << "City" << std::endl;
    std::cout << "- " << "Tz" << std::endl;
    std::cout << "- " << "Latitude" << std::endl;
    std::cout << "- " << "Altitude" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    // Makes user enter input and collects it
    std::cout << std::endl;
    std::string opt3;
    std::cout << "Enter your selection criterion: ";
    std::cin >> opt3;
    // Queries database for aggregating based on
    // that criteria.
    mysqlpp::Query query06 = myDB.query();
    query06 << "SELECT COUNT(DISTINCT %0), Country FROM Airports ";
    query06 << "WHERE Country = 'Germany';";
    query06.parse();
    mysqlpp::StoreQueryResult result06 = query06.store(opt3);
    // Prints out the result
    std::cout << std::endl;
    std::cout << std::left << std::setw(30) << "Count"
    << "Country" << std::endl;
    for (const auto& row : result06) {
        for (const auto& col : row) {
            std::cout << std::left << std::setw(30) <<
            col << std::left << std::setw(30);
        }
        std::cout << std::endl;
    }
}
// If user enters in option 4
void optionFour() {
    // Connects to the server
    mysqlpp::Connection myDB("cse278", "localhost", "cse278",
    "wVQABsJFQhwNdNbr");
// Prints out a list of airports table grouped by city
std::cout << "Here is the Airports table grouped by City for Germany "
<< "with more than one airport: " << std::endl;
std::cout << "---------------------------------------------" << std::endl;
    mysqlpp::Query query07 = myDB.query();
    query07 << "SELECT City, Count(City) FROM Airports ";
query07 << "WHERE Country = 'Germany' GROUP BY City HAVING Count(City) > 1;";
    query07.parse();
    // Prints it out below
    std::cout << std::endl;
    mysqlpp::StoreQueryResult result07 = query07.store();
    std::cout << std::left << std::setw(30) << "City" <<
    std::left << std::setw(30) << "Count of Airports" << std::endl;
    for (const auto& row : result07) {
        for (const auto& col : row) {
            std::cout << std::left << std::setw(30)
            << col << std::left << std::setw(30);
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}
