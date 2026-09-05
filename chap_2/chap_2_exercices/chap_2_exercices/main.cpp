//
//  main.cpp
//  chap_2_exercices
//
//  Created by Martial Aguessi on 09/05/2025.
//

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std ;

int main(int argc, const char * argv[]) {
    
//    insert code here...
    cout << "Hello, World!\n";
    
//  2.5.1
//    bool res = (false || true ) ;
//    cout <<  res ;
//    cout << "\n";
//    
//    cout << (true && false) || true ;
//    cout << "\n";
//    
//    cout << true && (false || true) ;
//    cout << "\n";
//    
//    cout << (true && false) || true ;
//    cout << "\n";
//    
//    cout << (3*5==15) && (7*8==21 || true !=false) ;
//    cout << "\n";
    
// 2.5.2
//    cout << "--- Checking the memory size of each variable on system --- \n" ;
//    cout << "Size of int: " << sizeof(int) << " bytes\n";
//    cout << "Size of float: " << sizeof(float) << " bytes\n";
//    cout << "Size of double: " << sizeof(double) << " bytes\n";
//    cout << "Size of char: " << sizeof(char) << " bytes\n";
//    cout << "Size of long: " << sizeof(long) << " bytes\n";
//    cout << "Size of long long: " << sizeof(long long) << " bytes\n";
//    cout << "Size of bool: " << sizeof(bool) << " bytes\n";
//    cout << "Size of a char pointer: " << sizeof(const char*) << " bytes\n"; // Example of C-string
//    cout << "Size of a int pointer: " << sizeof(const int*) << " bytes\n";
//    cout << "Size of a int: " << sizeof(const int) << " bytes\n";
//    
//    cout << "Size of a string: " << sizeof(const string) << " bytes\n"; // Prefer this (thank to the include of string header - because string is not a base type in C++) to a of C-string
//    cout << "\n";

// 2.5.3
//    char aChar = '\t' ;
//    int theCharInInt = (int) aChar;
//    cout << theCharInInt ;
//    cout << "\n";

// 2.5.4
//    unsigned int a = 5 ;
//    unsigned int b = 3 ;
//    
//    cout << b - a;
//    cout << "\n";
//    cout << pow(2, 32) ;
//    cout << "\n";
//    cout << b - a - pow(2, 32);
//    cout << "\n";
//
    
    
//    2.5.4 - using bitset to find binary representation
//    here we can see that, doing the substration in the binary representation (with 32 binary digits because 32-bit) would leed to the results
//    bitset<32> y(3) ;
//    cout << y << "\n" ;
//    bitset<32> x(5) ;
//    cout << x << "\n" ;
//    bitset<32> z(4294967294) ;
//    cout << z << "\n" ;
    
//    2.5.4 - final display - with chatgpt explanation
    
// C++ uses modular arithmetic for unsigned integers. So:
// result = (a - b) mod 2^32
// result = (-2) mod 4294967296
// result = 4294967296 - 2
// result = 4294967294
//    unsigned int a = 3;
//    unsigned int b = 5;
//    unsigned int result = a - b;
//    
//    cout << "a:       " << a << " (" << bitset<32>(a) << ")\n";
//    cout << "b:       " << b << " (" << bitset<32>(b) << ")\n";
//    cout << "a - b:   " << result << " (" << bitset<32>(result) << ")\n";
  
//    2.5.5 - converting lower case char to Upper case char
    
//    char aChar ;
//    cout << "Please enter a single char: " ;
//    cin >> aChar ;
////    cout << "\n" ;
//    cout << "You have selected the following char: " << aChar << "\n" ;
//    
//    int theCharAsInt = (int) aChar ;
//    cout << "\n--- Start of the information note --- \n" ;
//    cout << "The integer representation of your chosen char is: " << theCharAsInt << "\n" ;
//    
//// check to see if the char is lower case and convert
//    if (theCharAsInt >= 97 && theCharAsInt <= 122){
//        cout << "You have enter a lower case char \n" ;
//        cout << "The -32 rule will be use to convert to Upper case \n" ;
//
//        int upperCaseCharAsInt = theCharAsInt - 32 ; // manual test to deduce the equivalence
//        cout << "The integer representation of your chosen upeper case char is: " << upperCaseCharAsInt << "\n" ;
//        
//        cout << "--- End of the information note --- \n\n" ;
//        
//        char upperCaseChar = (char) upperCaseCharAsInt ;
//        cout << "The corresponding upper case char: " << upperCaseChar << "\n" ;
//    }
//
////    check to see if the char is Upper case and convert
//    else if(theCharAsInt >= 65 && theCharAsInt <= 90) {
//        cout << "You have enter an Upper case char \n" ;
//        cout << "The +32 rule will be use to convert to Upper case \n" ;
//
//        int lowerCaseCharAsInt = theCharAsInt + 32 ; // manual test to deduce the equivalence
//        cout << "The integer representation of your chosen upeper case char is: " << lowerCaseCharAsInt << "\n" ;
//        
//        cout << "--- End of the information note --- \n\n" ;
//        
//        char lowerCaseChar = (char) lowerCaseCharAsInt ;
//        cout << "The corresponding upper case char: " << lowerCaseChar << "\n" ;
//    }
//    
////    default case
//    
//    else {
//        cout << "You have not selected a letter \n" ;
//        cout << "no possible transofrmation \n" ;
//        cout << "--- End of the information note --- \n\n" ;
//    }

// 2.5.6 - cating
    
//    float afloat ;
//    
//    cout << "Enter a float: " ;
//    cin >> afloat ;
//
//    cout << "The float is " << afloat << "\n" ;
//    
//    int theFloatAsInt = (int) afloat ;
//    cout << "The nearest integrer using C-style cast is " << theFloatAsInt << "\n" ;
//
//    int theFloatAsInt_v2 = round(afloat) ;
//    cout << "The nearest integrer using cmath header is " << theFloatAsInt_v2 << "\n" ;
    
//    2.5.7 - correct the bug
    
//    int player1 ;
//    int player2 ;
//    
//    cout <<"Type 0 for stone, " ;
//    cout <<"1 for scissors, 2 for paper\n";
//    cout <<"Enter player 1's move\n" ;
//    cin >>player1 ;
//    cout <<"Enter player 2's move\n" ;
//    cin >>player2 ;
//    
//    if (player1==player2){
//        cout << "It's a draw\n" ;
//    } else {
//        int diff = player1 - player2 ;
//        if (diff==-2 || diff==1){
//            cout << "Player 1 won\n" ;
//        } else {
//            cout << "Player 2 won\n" ;
//        }
//    }
    
//    2.5.8 - check the output
    
//    int a = - 1 ;
//    unsigned int b = 0 ;
//    
//    if (a < b){
//        cout << "a is smaller\n" ;
//    } else {
//        cout << "a is bigger\n" ;
//    }
//    
//    cout << "because we're interpreting a to equal ";
//    unsigned int castValue = (unsigned int) a ;
//    cout << castValue ;
//    cout << "\n" ;
    
//    2.5.9 - play the bell character
//  doesn't not work directly woth xcode for some reasy
//    but work fine if you generate an executable and run it on the termina
//    step 1: generate the executable --> g++ main.cpp -o main
//    step 2: run the executable on the terminal --> ./main
    int limit ;
    cout <<"Please for how long you want to play the bell: " ;
    cin >> limit ;
    
    int i = 0 ;
    while ( i <= limit) {
        cout << "\a" ; // try to make a beep
        cout << i << "\n" ;
        i ++ ;
    }
    
    return 0;
}

