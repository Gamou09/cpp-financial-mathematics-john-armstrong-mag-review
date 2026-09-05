//
//  main.cpp
//  System Divers
//
//  Created by Martial Aguessi on 07/05/2025.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "--- Checking the memory size of each variable on system --- \n" ;
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of float: " << sizeof(float) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";
    cout << "Size of char: " << sizeof(char) << " bytes\n";
    cout << "Size of long: " << sizeof(long) << " bytes\n";
    cout << "Size of long long: " << sizeof(long long) << " bytes\n";
    cout << "Size of bool: " << sizeof(bool) << " bytes\n";
    cout << "Size of a char pointer: " << sizeof(const char*) << " bytes\n"; // Example of C-string
    cout << "Size of a int pointer: " << sizeof(const int*) << " bytes\n";
    cout << "Size of a int: " << sizeof(const int) << " bytes\n";
    
    cout << "Size of a string: " << sizeof(const string) << " bytes\n"; // Prefer this (thank to the include of string header - because string is not a base type in C++) to a of C-string
    
    
    // test C-string
    
//    char* speech = "To be or not to be?" ; // this line has an error if uncommented --> where C++ 11 does not conversion from string litteral to char
    const char* speech = "To be or not to be?" ;
    cout << "Size of the variable speech: " << sizeof(speech) << " bytes\n" ;
    
    return 0;
}
