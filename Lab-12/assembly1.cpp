// Copyright 2022 Andrew Boothe

#include <iostream>

int foo(int var1) {
    int var3=var1;
    var3 = var3+20;
    return var3;
}
int main() {
    int x= 9;
    int var = foo(x);
    std::cout << var << std::endl;
    return 0;
}