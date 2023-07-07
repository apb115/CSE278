// Copyright {C} Andrew Boothe, 3/8/2022

#include <iostream>
#include <fstream>
#include <string>


// Use stoi function for argv[]
int main(int argc, char* argv[]) {
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cout << "File not located" << std::endl;
        return 0;
    // Argument must have three elements in order to satisfy terminal
    //  commands: .\Lab06Seventh, numbers.txt, 2
    } else if (argc != 3) {
        std::cout << "Too many or not enough arguments for goal" << std::endl;
        return 0;
    }
    int lines = std::stoi(argv[2]);
    std::string line;

    // While loop to print each line from file
    int num = 0;
    while(  getline(inFile, line)    ) {
        if ( num < lines) {
            std::cout << "Line " << num+1 << std::endl;
            std::cout << line << std::endl;
            num++;
        }
    }
    inFile.close();
    return 0;
}
