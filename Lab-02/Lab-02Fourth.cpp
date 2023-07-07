#include <iostream>
#include <bitset>

int main() {
    int count = 65;
    for (int i = 0; i < 26; i = i + 1) {
        char ascii = (char) count;
        std::cout << ascii;
        std::cout << ':';
        std::cout << count << std::endl;
        
        
        count = count + 1;;
    }
}
