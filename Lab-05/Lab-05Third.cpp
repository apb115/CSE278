// Copyright (C) Andrew Boothe

#include <iostream>
#include <vector>

void printVector(std::vector<int>& v) {
    for (auto item : v) {
        std::cout << item << " ";

    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> A;
    std::vector<int> B;

    for (int i = 10; i < 100; i += 10) {
        A.push_back(i);
    }
    printVector(A);

    for (int i = 100; i < 400; i += 100) {
        B.push_back(i);
    }
    printVector(B);

    std::cout << "Insert 25 as a third element to the vector A" << std::endl;
    A.insert(A.begin()+2, 25);
    printVector(A);

    std::cout << "Insert the first three elements of A to the beginning of the B" << std::endl;
    B.insert(B.begin(), A.begin(), A.begin() + 3);
    printVector(B);

    std::cout << "Erase the second last element of B" << std::endl;
    B.erase(B.end() - 2);
    printVector(B);

    std::cout << "Erase the numbers between the second and fifth element of A (exclusive)" << std::endl;
    A.erase(A.begin() + 2, A.begin() + 5);
    printVector(A);

    std::cout << "Sum the first and the last element of A" << std::endl;
    int sum;
    sum = A.front() + A.back();
    std::cout << sum << std::endl;

    return 0;
}