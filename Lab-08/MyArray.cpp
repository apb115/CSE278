// Copyright {C} Andrew Boothe

// MyArray implementation

#include <iostream>
#include <sstream>
#include <initializer_list>

#include "MyArray.h"

// Write the implementation of each members and non-members
MyArray::MyArray(size_t size) {
    asize = size;
    aptr = new int[asize];
}

MyArray::MyArray(std::initializer_list<int> list) {
    asize = list.size();
    aptr = new int[asize];
    std::copy(std::begin(list), std::end(list), aptr);
}

MyArray::MyArray(size_t size2) {
    asize = size2;
}

MyArray::~MyArray() {
    std::cout << "MyArray destructor" << std::endl;
    delete[] aptr;
}

size_t MyArray::size() const noexcept {
    return asize;
}

std::string MyArray::toString() const {
    std::ostringstream out;
    out << "{";
    for (size_t i = 0; i < asize-1; i++) {
        out << aptr[i] << ", ";
    }
    out << aptr[asize-1] << "}";
    return out.str();
}

int& MyArray::operator[](size_t index) {
    if (index >= asize) throw std::out_of_range("Index out of range.");
    else {
        return aptr[index]; //*(aptr+index)
    }
}

const int& MyArray::operator[](size_t index) const {
    if (index >= asize) throw std::out_of_range("Index out of range.");
    else {
        return aptr[index];
    }
}

bool MyArray::operator==(const MyArray& right) const {
    if (asize != right.asize) return false;
    for (size_t i = 0; i < asize; i++) {
        if (aptr[i] != right.aptr[i]) {
            return false;
        }
    }
    return true;
}

MyArray& MyArray::operator+=(int value) {
    for (size_t i = 0; i < asize; i++) {
        aptr[i] += value;
    }
    return *this; //*
}

std::istream& operator>>(std::istream& in, MyArray& a) {
    for (size_t i = 0; i < a.asize; i++) {
        in >> a.aptr[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const MyArray& a) {
    out << a.toString();
    return out;
}