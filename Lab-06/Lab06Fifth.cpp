// Copyright {C} Andrew Boothe

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Incorrect number of command line arguments" << std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);
    std::ofstream outFile(argv[2]);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cout << "Unable to open one of the files" << std::endl;
        return 2;
    }
    std::string line;
    while(  getline(inFile, line)  ) {
        outFile << line << std::endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}
