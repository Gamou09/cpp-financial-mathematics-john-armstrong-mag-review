//
//  main.cpp
//  04_01_FlowOfControls
//
//  Created by Martial Aguessi on 14/05/2025.
//

#include <iostream>
#include <cmath>

using namespace std ;

// Test while looop
void launchRocket(){
    int count = 10 ;
    while (count > 0) {
        cout << count ;
        cout << "\n" ;
        count -- ; // unitary operator
    }
    cout << "Blast off!\n" ;
}

// Test do-while
void printPowerOf2(){
    int count = 0 ;
    int currentPower = 1 ;
    do {
        cout << "2^" << count << "=" ;
        cout << currentPower ;
        cout << "\n" ;
        currentPower *= 2 ;
        count++ ;
    } while (currentPower < 1000) ;
}

// possible with comma operator but not easily very reable
//void printPowerOf2_withCommaOperator(){
//    for (int i = 0, power = 1; count < 10 ; count++, power *=2){
//        cout << "2^" << count << "=" ;
//        cout << power ;
//        cout << "\n" ;
//    }
//}


// test for loop
void launchRocket_forloop(){
    for (int i = 0; i < 100; i +=10) {
        cout << i ;
        cout << "\n" ;
    }
    cout << "Blast off!\n" ;
}

// Test for break
// PS: Test - we can use "return" also to break a function
void sumAllPositiveNumber(){
    cout << "Enter positive numbers followed " ;
    cout << "by a negative number to quit: \n" ;
    int total = 0 ;
    while (true){
        int next ;
        cin >> next ;
        if(next < 0) break ;
        total += next ;
    }
    
    cout << "The total is " << total << "\n" ;
}

// Test for continue
// this function won't compile as we treat warning as error
//void sumAllPositiveNumber_continue(){
//    cout << "Enter positive numbers " ;
//    cout << "Type CTRL+C to quit\n" ;
//    int total = 0 ;
//    while (true){
//        int next ;
//        cin >> next ;
//        if(next < 0) continue ;
//        total += next ;
//    }
//    cout << "The total is " << total << "\n" ;
//}

// Test for throw exception
// prefer throw error to try and catch as it's better to throw error and correct than try fancy resolution (that's for expert)
#include <stdexcept>
double debitAccount(double balance, double amount){
    double newAmount = balance - amount ;
    if(newAmount < 0.0) throw logic_error("No overdraft agreed") ;
    return newAmount ;
}

// Test of switc
void printMessage(int score){
    switch (score) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            cout << "You have failed.\n" ;
            break;
        case 5:
        case 6:
            cout << "You have passed.\n" ;
            break;
        case 7:
            cout << "Merit.\n" ;
            break;
        case 8:
        case 9:
            cout << "Distinctions.\n" ;
            break;
        default:
            cout << "Invalid score.\n" ;
            break;
    }
    cout <<"Good luck in your future career\n" ;
}

// test ternary operator - flow of control in operator
// look fancy but sometime not straight forward to understand
int max(int a, int b){
    return a > b ? a : b ;
}

int main() {
    // insert code here...
    cout << "Hello, World!\n\n";
    
//    test while loop
    cout << "\n--- Test while loop --\n";
    launchRocket() ;
    
//    test while loop
    cout << "\n--- Test do while loop --\n";
    printPowerOf2() ;
    
//  test while loop
    cout << "\n--- Test for loop --\n";
    launchRocket_forloop() ;
    
//  test break keywords
//    cout << "\n--- Test for break keyword --\n";
//    sumAllPositiveNumber() ;
    
//    test throw
    cout << "\n--- Test for throw keyword --\n";
    cout << debitAccount(1000, 200) << "\n";
//    cout << debitAccount(1000, 1200) << "\n"; // throw error line
    cout << debitAccount(1000, 700) << "\n";
    
//  Test for switch case
    cout << "\n--- Test for throw keyword --\n";
    printMessage(6) ;
    cout << "\n" ;
    printMessage(9) ;
    cout << "\n" ;
    printMessage(-2) ;
    cout << "\n" ;
    
//    test ternary operator
    cout << "\n--- Test for ternary operator --\n";
    cout << max(5, 7) << "\n";
    
    return 0;
}

