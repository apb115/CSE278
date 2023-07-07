// Copyright {C} Andrew Boothe

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    /* TODO: Declare any necessary variables here. */
    std::string filename;
    std::cout << "Enter a filename" << std::endl;
    std::cin >> filename;
    ifstream inputR(filename);
    std::vector<std::string> lname(20);
    std::vector<std::string> fname(20);
    std::vector<int> mid1(20);
    std::vector<int> mid2(20);
    std::vector<int> fin(20);
    /* TODO: Read a file name from the user and read the tsv file here. */
    if (!inputR.is_open()) {
        std::cout << "Could not open the file." << std::endl;
        return 1;
    }
    int index = -1;
    while (!inputR.fail()) {
        index++;
        inputR >> lname.at(index);
        inputR >> fname.at(index);
        inputR >> mid1.at(index);
        inputR >> mid2.at(index);
        inputR >> fin.at(index);
    }
    inputR.close();
    for (int i = 0; i < index; i++) {
        std::cout << lname[i] << std::endl;
        std::cout << mid2[i] << std::endl;
    }
    /* TODO: Compute student grades and exam averages, then output results to a text file here. */
    std::ofstream output("report.txt");
    if (!output.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return 1;
    }
    int counter = 0;
    while (counter < index) {
        output << lname[counter] << "\t";
        output << fname[counter] << "\t";
        output << mid1[counter] << "\t";
        output << mid2[counter] << "\t";
        output << fin[counter] << "\t";
        double avg = (mid1[counter] + mid2[counter] + fin[counter]) / 3.0;
        char letter;
        if (avg >= 90) {
            letter = 'A';
        } else if (avg >= 80 && avg < 90) {
            letter = 'B';
        } else if (avg >= 70 && avg < 80) {
            letter = 'C';
        } else if (avg >= 60 && avg < 70) {
            letter = 'D';
        } else {
            letter = 'F';
        }
        // other statements

        output << letter;
        counter++;
    }


    return 0;
}
