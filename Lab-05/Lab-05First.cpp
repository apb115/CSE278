// Copyright (C) Andrew Boothe

#include <iostream>
#include <random>

void printArray(const int a[], const int size) {
    for (int i = 1; i < size; i++) {
        std::cout << i << " repeats " << a[i] << " times." << std::endl;
    }
}

int main() {
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 10);
    int num;
    int histogram[11] = {0};
    for (int i = 0; i < 100; i++) {
        num = distrib(gen);
        // std::cout << num << std::endl;
        histogram[num]++;
    }
    printArray(histogram, 11);
    return 0;
}
