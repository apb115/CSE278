// Copyright {C} Andrew Boothe

// MyArray Class declaration

#pragma once
#include <iostream>
#include <initializer_list>

class MyArray {
   
  private:
    size_t asize = 0;
    int * aptr;  

  public:
    // constructors
    MyArray(size_t size);
    MyArray(std::initializer_list<int> list);
    // copy constructor
    MyArray(size_t size);
    // destructor
    ~MyArray();

    // size()
    size_t size() const noexcept;
    // toString()
    std::string toString() const;
    // operator[]
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    // operator==
    bool operator==(const MyArray& right) const;
    // operator+=
    MyArray& operator+=(int value);
    // friend operator>>
    friend std::istream& operator>>(std::istream& in, MyArray& a);
};
// non-member operator<<
std::ostream& operator<<(std::ostream& out, const MyArray& a);
