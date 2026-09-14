//
//  main.cpp
//  chap_11_Arrays_String_Pointers_myReview
//
//  Created by Martial Aguessi on 12/09/2026.
//

#include <iostream>   // STL input/output streams: std::cout, std::cin
#include <chrono>     // STL time utilities: clocks, time points, durations
#include <cstdlib>    // C standard library utilities: rand(), srand()
#include <cassert>    // Standard C++ assertions for debugging/testing — key function: assert(condition)
#include "testing.hpp"

using namespace std ;

//
// Helper function - 11.1
//

// Passing the length as parameter
int sumArray (int toSum[], int length){
    int sum = 0 ;
    for (int i = 0; i < length; ++i) {
        sum += toSum[i] ;
    }
    
    return sum ;
}

// Not passing the length and trying to use the sizeOf trick
// does not work as warning: sizeof(toSum) will return the size of the point no the array itself
// why: toSum is not really an array parameter inside the function. In a function parameter, C++ adjusts it to a pointer
// sizeof(toSum) gives the size of an int*, not the size of the original array.
int sumArray2 (int toSum[]){
    int sum = 0 ;
    int length = sizeof(toSum) / sizeof(int) ;
    
    for (int i = 0; i < length; ++i) {
        sum += toSum[i] ;
    }
    
    return sum ;
}

// Function to attempt returning an array
#include <array>

std::array<int, 3> makeArray() {
    return {10, 20, 30};
}

// Sum using a Pointer basic
int sumUsingPointer(int* toSum, int length){
    int sum = 0 ;
    for (int i = 0; i < length; i++) {
        sum += toSum[i] ;
    }
    return sum;
}

// Sum using poiter expert C++
// hard to follow in the begin but uses a lot of c++ conventino which makes it easier with practice
// the first memory location is call begin, last end (found by doing pointer arithmetic)
// then just loop over pointers
// benfits: clean and slightly faster since you are directly using the memory address
int sumUsingForAndPlusPlus(int* begin, int n){
    int sum = 0 ;
    int* end = begin + n ;
    for (int* ptr = begin; ptr != end; ptr++) {
        sum += *ptr ;
    }
    return sum ;
}


//
// 11.3 - Pointers to Text helper
//

// using pointer to create strlen
int computeLengthOfString (const char* s){
    
    int length = 0 ;
    while ((*s) != 0) {
        s++ ;
        length++ ;
    }
    
    return length ;
    
}

//
// 11.4 Pass by pointer Helper
//

void polarToCartesian (double r, double theta, double* x, double* y) {
    *x = r*cos(theta) ;
    *y = r*sin(theta) ;
}

void testPolarToCartesian(){
    
    double r = 2 ;
    double theta = atan(1) ;
    
    double x;
    double y ;
    polarToCartesian(r, theta, &x, &y) ;
    ASSERT_APPROX_EQUAL(x, sqrt(2), 1e-4) ;
    ASSERT_APPROX_EQUAL(y, sqrt(2), 1e-4) ;
    
    cout << "All assert functions work\n" ;
}

//
// 11.5 - Help function
//
char* thisFunctionreturnsAnArray(){
    // WARNING: text is a local array and is destroyed when the function returns.
    // Returning text therefore returns a dangling pointer.
    char text[] = "Don't do this";
    return text ;
}

void someOtherFunction(){
    char text[] = "Alternative text\n" ;
    cout << text ;
    cout << "\n" ;
}

char* thisFunctionReturnsAPointer(){
    char text[] = "This works" ;
    int n = (int) strlen(text) ;
    
    char* ret = new char[n+1] ; // -> creates memory that survives the function
    /** we now get a compiler warning here */
    strcpy(ret, text) ; // -> copies the actual characters into that surviving memory
    return ret ;
}


class Pair {

public:
    double x;
    double y;

    Pair() : x(rand()), y(rand()) {}

    Pair(double x, double y)
        : x(x), y(y) {}
};


//
// Class Instrument and Position to text the concept of using pointer to share data
//

class Instrument {
    
public:
    string bloombergTicker ;
    string ricCode ;
    string companyName ;
    Instrument() {} ;
};

class Position {
    
public:
    string trader ;
    double quantity ;
    Instrument* instrument ; // Pointer to instrument
    explicit Position (Instrument* instrument) ;
} ;

Position:: Position (Instrument* instrument) : instrument( instrument) {}

vector<Position> constructPositions(){
    // the caller of this functino
    // should call delete on the instrument
    // when they are done with all the positions
    vector<Position> positions ;
    
    Instrument* instrument = new Instrument ;
    instrument->companyName = "Google" ;
    instrument->bloombergTicker = "GOOG US Equity" ;
    instrument->ricCode = "GOOG.OQ" ;
    
    Position p1(instrument) ;
    p1.trader = "Han" ;
    p1.quantity = 100.00 ;
    positions.push_back(p1) ;
    
    Position p2(instrument) ;
    p2.trader = "Leia" ;
    p2.quantity = -100.00 ;
    positions.push_back(p2) ;
    
    return positions ;
}

void testConstructPositions(){
    vector<Position> r = constructPositions() ;
    int n = (int) r.size() ; // size function exist as a method of class vector
    for (int i = 0; i < n; i++) {
        cout << "Position " << i << "\n" ;
        Position& p = r[i] ;
        cout << "Trader " << p.trader << "\n" ;
        cout << "Quantity " << p.quantity << "\n" ;
        cout <<"Instrument ";
        cout << p.instrument->companyName << "\n";
        cout << "\n" ;
    }
    
    delete r[0].instrument ; // the call of the constructPositions has to know precisely how to call delete (this violates information hiding).
}

string getCompanyName (Position& position){
    if (position.instrument == nullptr) {
        return "Name not set" ;
    } else {
        return position.instrument->companyName ;
    }
}

class PositionV2 {
    
public:
    string trader ;
    double quantity ;
    shared_ptr<Instrument> instrument ;
    explicit PositionV2 (shared_ptr<Instrument> ins) ;
} ;

PositionV2:: PositionV2 (shared_ptr<Instrument> ins) : instrument( ins) {}

vector<PositionV2> constructPositionsV2(){
    // Since we qre using share_ptr,
    // no need for the caller to delete himself the object
    vector<PositionV2> positions ;
    
    shared_ptr<Instrument> ins = make_shared<Instrument> () ; // key difference is the function make_shared<> instead of new
    ins->companyName = "Google" ;
    ins->bloombergTicker = "GOOG US Equity" ;
    ins->ricCode = "GOOG.OQ" ;
    
    PositionV2 p1(ins) ;
    p1.trader = "Han" ;
    p1.quantity = 100.00 ;
    positions.push_back(p1) ;
    
    PositionV2 p2(ins) ;
    p2.trader = "Leia" ;
    p2.quantity = -100.00 ;
    positions.push_back(p2) ;
    
    return positions ;
}

void testConstructPositionsV2(){
    vector<PositionV2> r = constructPositionsV2() ;
    int n = (int) r.size() ; // size function exist as a method of class vector
    for (int i = 0; i < n; i++) {
        cout << "Position " << i << "\n" ;
        PositionV2& p = r[i] ;
        cout << "Trader " << p.trader << "\n" ;
        cout << "Quantity " << p.quantity << "\n" ;
        cout <<"Instrument ";
        cout << p.instrument->companyName << "\n";
        cout << "\n" ;
    }
    
    // delete r[0].instrument ; // No longer needed since we are using share_ptr; Error: Cannot delete expression of type share_ptr<>
}

//
// Main function
//

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    cout << "\nChap 11.1: Arrrays...........................................................\n" ;
    
//    // Create an unintialised array of length 5
//    // since unintialised the about number will be random
//    cout << "\n11.1.1 - Creation of an unintialised array (myArray) of length 5\n" ;
//    int myArray[5] ;
//    for (int i = 0; i < 5; ++i) {
//        cout << "Entry " << i << "=" ;
//        cout << myArray[i] ;
//        cout << "\n" ;
//    }
//    
//    // Create an initialised array of length 5
//    // output number as expected
//    cout << "\n11.1.2 - Creation of an initialised array (myArray2) of length given by input\n" ;
//    int myArray2[] = {1, 1, 2, 3, 5};
//    for (int i = 0; i < 5; ++i) {
//        cout << "Entry " << i << "=" ;
//        cout << myArray2[i] ;
//        cout << "\n" ;
//    }
//    
//    cout << "\n11.1.3 - Creation of an initialised array (myArray3) of length given by size but empty value\n" ;
//    // empty value is taken as 0 by default
//    int myArray3[5] = {};
//    for (int i = 0; i < 5; ++i) {
//        cout << "Entry " << i << "=" ;
//        cout << myArray3[i] ;
//        cout << "\n" ;
//    }
//    
//    cout << "\n11.1.4 - Creation of an initialised array (myArray4) of length given by size but providing less initialised value\n" ;
//    // First values will be as expected but missing one will be initiased to 0
//    int myArray4[5] = {1, 2, 3};
//    for (int i = 0; i < 5; ++i) {
//        cout << "Entry " << i << "=" ;
//        cout << myArray4[i] ;
//        cout << "\n" ;
//    }
//    
//    // Trick to determine the size of the an array
//    cout << "\n11.1.5 - Unlike vector, C array has no size function, we use sizeof(myArray)/sizeof(int) trick \n" ;
//    cout << "Size of my array is " << sizeof(myArray4)/sizeof(int) << "\n";
//    
//    cout << "\n11.1.6 - Given no size function, we need to pass the size when passing to another function. e.g - Sum elements \n" ;
//    cout << "Sum of elements of myArray4 passing length as argument (with function sumArray) is " << sumArray(myArray4, 5) << " - correct \n" ;
//    cout << "Sum of elements of myArray4 using the sizeof trick inside the function is (with function sumArray2) is " << sumArray2(myArray4) << " - Incorrect\n" ;
//
//    
//    cout << "\n11.1.7 - Although we can pass arrays to functions, you must never return them from a function \n" ;
//    cout << "Built-in C-style arrays cannot be returned by value because C++ does not copy them as whole objects; \n" ;
//    cout << "unlike types such as double, std::vector, or std::array. when passed to a function, they decay to a pointer to their first element.3 \n" ;
//    cout << "int Array[5]; is example of a Built in C-style array:\n" ;
//    cout << "std::array object (e.g. std::array<int, 5> Array; )from the C++ standard library.; \n" ;
//    // int[3] makeArray() ;
//    
//    cout << "\n11.1.8 - Create an initialised 3by5 array \n" ;
//    int myArray5 [][5] = {{1, 2, 3, 4, 5}, {2, 0, 0, 0, 0}, {3, 0, 0, 0, 0}} ;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0 ; j < 5; j++) {
//            cout << "Entry (" << i << "," << j << ")=" ;
//            cout << myArray5[i][j] ;
//            cout << "\n" ;
//        }
//    }
//
//    cout << "\n11.1.9 - Arrays are not very useful data structure for us because you cannotchange the length of an array, nor issert new value or add item at the end.\n" ;
//    cout << "The size of an array is fixed at compile time\n" ;
//    cout << "Arrays are only of interest if you know the size of your arrays when your code is compiled.\n" ;
//    
//    cout << "\n11.1. Tips: Don't use arrays. Vectors do everything you want to do with arrays and much more\n" ;
//    cout << "More nuance approach: std::vector when the number of elements can change\n" ;
//    cout << "Prefer std::array when the size is fixed and known at compile time; \n" ;
//    cout << "Rarely use raw built-in arrays in modern C++.\n" ;

    cout << "\nChap 11.2: Pointers ...........................................................\n" ;
    
    
//    cout << "\n11.2.1 - New and delete -  Pointers to work with sequence of data since Arrays are not flexible enough\n" ;
//    int n = 5 ; // Unlike array, you don't have to choose the size in advance, could to at run time. but the allocated array is still fixed-size after allocation
//    int* myArray6 = new int[n] ; // new int is creating a sequence of int data types in the memory (could have any other data types) - int* is a pointer to an int (the array start)
//    for (int i = 0; i < n; i++) {
//        cout << "Entry " << i << "=" ;
//        cout << myArray6[i] ;
//        cout << "\n" ;
//    }
//    
//    delete [] myArray6 ; // main downside is that the memory won't automatically delte when the variable goes out fo scope;  However you can safely return the data
//
//    cout << "\n11.2.1.b - Introducing a nez data type to show you can use new[] with about anything - Example Pair class \n" ;
//    const int dim = 5;
//
//    Pair* myPairs = new Pair[dim];
//
//    for (int i = 0; i < dim; i++) {
//
//        double xValue = myPairs[i].x;
//        double yValue = myPairs[i].y;
//
//        cout << "Pair (";
//        cout << xValue;
//        cout << ", ";
//        cout << yValue;
//        cout << ")\n";
//    }
//
//    delete[] myPairs;
//    
//    cout << "\n11.2.1.c - Memory leaks expirements \n" ;
//    cout << "Please uncomment the following lines of code if you need to see the experiment. Otherwise leave as is to save execution time\n" ;

    
    
//    const int m = 100000;
//    const int repetitions = 10000;


    // ============================================================
    // TEST 1 - WITH delete[]
    // ============================================================

//    auto startWithDelete = chrono::high_resolution_clock::now();
//
//    for (int j = 0; j < repetitions; j++) {
//
//        Pair* myPairs = new Pair[m];
//
//        delete[] myPairs; // Memory is released after every iteration
//    }
//
//    auto endWithDelete = chrono::high_resolution_clock::now();
//
//    chrono::duration<double> elapsedWithDelete =
//        endWithDelete - startWithDelete;
//    
//    cout << "\nWITH delete[]\n";
//    cout << "Elapsed time: "
//         << elapsedWithDelete.count()
//         << " seconds\n";


    // ============================================================
    // TEST 2 - WITHOUT delete[]
    // ============================================================

//    auto startWithoutDelete = chrono::high_resolution_clock::now();
//
//    for (int j = 0; j < repetitions; j++) {
//
//        Pair* myPairs = new Pair[m];
//
//        // delete[] myPairs;
//        // Intentionally omitted -> memory leak
//    }
//
//    auto endWithoutDelete = chrono::high_resolution_clock::now();
//
//    chrono::duration<double> elapsedWithoutDelete =
//        endWithoutDelete - startWithoutDelete;
//    
//    cout << "\nWITHOUT delete[]\n";
//    cout << "Elapsed time: "
//         << elapsedWithoutDelete.count()
//         << " seconds\n";
//    
    // Memory leak experiment:
    //
    // WITH delete[]:
    // Elapsed time = 13.6528 s
    //
    // WITHOUT delete[]:
    // Elapsed time = 52.6043 s
    //
    // The leaking version was about 3.9x slower.
    // Repeated allocations without delete[] increase memory pressure,
    // which can force the OS to compress memory or use swap,
    // significantly slowing down the program.
    //
    // If memory usage becomes too high, macOS may forcibly terminate
    // the process. In Xcode this can appear as:
    //
    // Message from debugger: Terminated due to signal 9
    // Program ended with exit code: 9
    //
    // Signal 9 (SIGKILL) means the operating system forcibly killed
    // the process; in this experiment, excessive memory consumption
    // from the leak is the likely cause.

//    cout << "\n11.2.2 - Pointer Operator \n" ;
    
//     on a 32-bit system, a memory address is typically represented using 32 bits.
//     With 32 bits, you can form: 2^32 different binary values from 000..00 to 111...1111
//     if each distinct address refers to one byte (hardware/architecture design convention)
//     2^32 ~ 2GB
//     this explains why a double taking 8 bytes occupies 8 consecutive memory addresses,
//     while a char taking 1 byte occupies only 1 address.
    
//    cout << "\n11.2.2.a - Extract the memory address of any variable with &(before) and *(before) dereference the pointer → value at that address \n" ;
//    // One small terminology correction: * does not “access the pointer”; it dereferences the pointer/address to access the value.
//    //    ptr  --> access the pointer itself → address
//    //    *ptr --> dereference the pointer → value at that address
//    //    &ptr --> address of the pointer variable itself
//    
//    int myVariable = 10 ;
//    int* pointerToMyVariable = &myVariable ;
//    
//    cout << "Memory location of myVariable: " ;
//    cout << pointerToMyVariable ;
//    cout << "\n" ;
//    
//    cout << "Memory location of myVariable +1: " ;
//    cout << pointerToMyVariable + 1 ; // The difference is 4 bytes because an int on your system is 4 bytes.
//    cout << "\n" ;
//    
//    cout << "Value of myVariable:  " ;
//    cout << *pointerToMyVariable ;
//    cout << "\n" ;
//    
//    cout << "\n11.2.2.b - Using -> as operator operator \n" ;
//    Pair p;
//    Pair* pointerToP = &p ;
//    
//    // use --> to acess fields via pointer
//    pointerToP->x = 123.0 ;
//    pointerToP->y = 456.0 ;
//    
//    // We check that c has changed
//    assert( p.x == 123.0 ) ;
//    assert( p.y == 456.0 ) ;
//    
//    // You could use * and .
//    assert( (*pointerToP).x == 123.0) ;
//    assert( (*pointerToP).y == 456.0) ;
//    
//    cout << "All asserts test passed \n" ;
//    
//    cout << "\n11.2.3 - Looping with pointers \n" ;
//    cout << "You can pass a pointer to a function much as we passed an array to function" ;
//    
//    int myArray7[5] = {1, 2, 3};
//    for (int i = 0; i < 5; ++i) {
//        cout << "Entry " << i << "=" ;
//        cout << myArray7[i] ;
//        cout << "\n" ;
//    }
//    
//    cout << "Sum of elements of myArray7 passing pointer and length as argument (with function sumUsingPointer) is " << sumUsingPointer(myArray7, 5) << "\n" ;
//    cout << "Sum of elements of myArray7 using the C++ pro version with pointer and length (with function sumUsingForAndPlusPlus) " << sumUsingForAndPlusPlus(myArray7, 5) << "\n" ;
//    
//    cout << "\n11.2.3.bis - Interview question: array indexing vs pointer arithmetic\n";
//    
//    cout << "For built-in arrays: a[i] is equivalent to *(a + i). \n" ;
//    cout << "The same rule can be applied repeatedly to multidimensional arrays. \n" ;
//    
//    // For built-in arrays, a[i] is equivalent to *(a + i).
//    // In most expressions, a decays to a pointer to its first element: a == &a[0].
//    // a + i moves the pointer forward by i elements, not by i bytes.
//    // *(a + i) dereferences that address and returns the value stored in element i.
//    // Therefore: a[i] == *(a + i).
//
//    int a[2][2][2][2] = {
//        {
//            {{1, 2}, {3, 4}},
//            {{5, 6}, {7, 8}}
//        },
//        {
//            {{9, 10}, {11, 12}},
//            {{13, 14}, {15, 16}}
//        }
//    };
//    
//    cout << "\nOur example 2x2x2x2 Array\n" ;
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < 2; j++) {
//            for (int k = 0; k < 2; k++) {
//                for (int l = 0; l < 2; l++) {
//
//                    cout << "a[" << i << "][" << j << "]["
//                         << k << "][" << l << "] = "
//                         << a[i][j][k][l] << "\n";
//
//                }
//            }
//        }
//    }
//
//    cout <<"\nVerification that both Normal Array and Pointer arithmetic matches\n" ;
//    int i = 1;
//    int j = 0;
//    int k = 1;
//    int l = 1;
//    
//    cout << "i= " << i << ", j= " << j << ", k= " << k << ", l= " << l << "\n";
//
//
//    // Normal array notation
//    int arrayValue = a[i][j][k][l];
//
//    // Equivalent pointer arithmetic
//    int pointerValue = *(*(*(*(a + i) + j) + k) + l);
//
//    cout << "Normal array version: a[i][j][k][l] = " << arrayValue << "\n";
//    cout << "Pointer version: *(*(*(*(a + i) + j) + k) + l) = " << pointerValue << "\n";
//
//    // Both expressions must access exactly the same int.
//    assert(arrayValue == pointerValue);
//    
//
//    cout << "\n11.2.4 - Using pointers in practice \n" ;
//
//    class intArray {
//        
//    public:
//        int* firstElement ;
//        int length ;
//    };
//
//    int myArray8[] = {10, 20, 30, 40, 50};
//
//    intArray myIntArray;
//
//    myIntArray.firstElement = myArray8;
//    myIntArray.length = 5;
//
//    cout << "Length of my myIntArray: "
//         << myIntArray.length << "\n";
//
//    cout << "Pointer to the first element of my myIntArray: "
//         << myIntArray.firstElement << "\n";
//
//    cout << "First element of my myIntArray: "
//         << *(myIntArray.firstElement) << "\n";
//    
//    cout << "Fourth element of my myIntArray: "
//         << *(myIntArray.firstElement + 3) << "\n";
//    
//    cout << "\n" ;
//    cout << "Above defined intArray class with a pointer to first element and length is just vector<int> \n" ;
//    cout << "Let simply use the standard class unless we believe we can write a more efficient object than the standard vector<int> \n" ;
    
    cout << "\nChap 11.3: Pointers to text ...........................................................\n" ;

//    // in C, we don't have classes, especially no class string
//    // In C standard convention, text is represented using a block of memory containing characters terminated by the character code 0
//    // the code number 0 isn't used for any character symbols so it can be safely used to mark the end of a code block
//    
//    cout << "\n11.3.a - ASCII equivalent of the text Hello using type cast (int)c with char c \n" ;
//    // the single quote are mandatory for char type
//    cout << "charArray1 is created as follow char charArray1[] = {'H', 'e', 'l', 'l', 'O', '\\0'} ; \n" ;
//    char charArray1[] = {'H', 'e', 'l', 'l', 'O', '\0'} ;
//    for (int i = 0; i < 6; i++) {
//        cout << "ASCII value ";
//        char c = charArray1[i] ;
//        cout << ((int) c) ;
//        cout << "\n" ;
//    }
//    
//    cout << "\n11.3.b - C-shortcut for creating a sequence of characaters - using double quote - C-style string or null terminated string \n" ;
//    // double quote for a string - sequence of characters
//    cout << "charArray2 is created as follow const char* charArray2 = \"Hello\" ; \n" ;
//
//    const char* charArray2 = "Hello" ;
//    for (int i = 0; i < 6; i++) {
//        cout << "ASCII value ";
//        char c = charArray2[i] ;
//        cout << ((int) c) ;
//        cout << "\n" ;
//    }
//    
//    cout << "\n11.3.c - Using pointers to directly replicate the behaviour of the strlen, strcpy, ... \n" ;
//    
//    cout << "Testing computeLengthOfString helper function \n" ;
//    const char* quotation = "To be or not to be" ;
//    int l1 = computeLengthOfString(quotation) ;
//    int l2 = (int) strlen(quotation) ; // built in strlen() returns std::size_t; So make the conversion from size_t to int explicit to avoid implicit conversion warning
//
//    cout << "Lenght of quotation using computeLengthOfString function: " << l1 << "\n";
//    cout << "Lenght of quotation using built in strlen function: " << l2 << "\n";
//    
//    cout << "\n11.3.c - Warning: Be careful not to access data outside the bounds of an array\n";
//
//    cout << "Below is a failing test. Uncomment only to demonstrate out-of-bounds access.\n";
//
////     char* shortText = new char[20];   // Valid indexes are 0 to 19
////    
////     for (int i = 0; i < 1000; i++) {
////         shortText[i] = 'x';           // ERROR from i = 20 onward:
////                                       // writing outside allocated memory
////     }
////    
////     delete[] shortText;
//    
    cout << "\nChap 11.4: Pass by Pointer ...........................................................\n" ;

//    cout << "\n11.4.a - testing polarToCartesian using the function testPolarToCartesian \n" ;
//    testPolarToCartesian() ;
//    
//    cout << "\nNote: \n" ;
//    cout << "- There is very little pratical difference between passing data using a pointer and reference\n" ;
//    cout << "- In the C langauafe, you have to use pass by pointer because, the concept of pass by reference does not exist\n" ;
//    cout << "-- In the C++ language, using pass by reference is the preferred approach\n" ;
//    
//    cout << "\n11.4.b - Combining keyword const and *\n";
//
//
//    // ------------------------------------------------------------
//    // 1. const char* ptr
//    // ------------------------------------------------------------
//
//    // const char* ptr means: I may move the pointer somewhere else, but I promise not to modify the data through this pointer.
//    // This is useful when a function needs to read text but should not change it.
//    cout << "\nconst char* ptr -> the DATA pointed to cannot be modified, "
//            "but the pointer itself can be modified\n";
//
//    const char* ptr = "A string";
//
//    cout << "ptr contains address: "
//         << static_cast<const void*>(ptr)
//         << " | *ptr = " << *ptr
//         << " | string from ptr = " << ptr << "\n";
//
//    ptr = ptr + 2;   // Allowed: ptr itself is not const
//
//    cout << "After ptr = ptr + 2\n";
//
//    cout << "ptr contains address: "
//        // static_cast<const void*>(ptr) converts ptr to a generic pointer type,
//        // so cout prints the memory address stored inside ptr instead of the string.
//         << static_cast<const void*>(ptr)
//         << " | *ptr = " << *ptr
//         << " | string from ptr = " << ptr << "\n";
//
//    // *ptr = 'a'; // ERROR: the data pointed to by const char* cannot be modified
//
//
//    // ------------------------------------------------------------
//    // 2. char* const constPtr
//    // ------------------------------------------------------------
//
//    // char* const ptr means: “This pointer must always point to the same place, but I am allowed to modify the data stored there.”
//    // This is useful when you want a permanent reference to one buffer or object, but the contents themselves are meant to change.
//    cout << "\nchar* const constPtr -> the POINTER itself cannot be modified, "
//            "but the data it points to can be modified\n";
//
//    char* fiveChars = new char[5]{'H', 'e', 'l', 'p', '\0'};
//
//    char* const constPtr = fiveChars;
//
//    cout << "constPtr contains address: "
//         << static_cast<void*>(constPtr)
//         << " | *constPtr = " << *constPtr
//         << " | string = " << constPtr << "\n";
//
//    // constPtr++; // ERROR: constPtr itself is const and cannot point somewhere else
//
//    *constPtr = 'h';   // Allowed: the pointed-to data is not const
//
//    cout << "After *constPtr = 'h'\n";
//
//    cout << "constPtr contains address: "
//         << static_cast<void*>(constPtr)
//         << " | *constPtr = " << *constPtr
//         << " | string = " << constPtr << "\n";
//
//    delete[] fiveChars;
//
//
//    // ------------------------------------------------------------
//    // 3. const char* const ptr
//    // ------------------------------------------------------------
//
//    // const char* const ptr means: “The pointer must always point to the same place, and the data must not be changed through this pointer either.”
//    // This is useful for something that should be completely read-only and fixed.
//    cout << "\nconst char* const fixedPtr -> neither the POINTER "
//            "nor the DATA it points to can be modified\n";
//
//    const char* const fixedPtr = "A string";
//
//    cout << "fixedPtr contains address: "
//         << static_cast<const void*>(fixedPtr)
//         << " | *fixedPtr = " << *fixedPtr
//         << " | string = " << fixedPtr << "\n";
//
//    // fixedPtr++; // ERROR: the pointer itself is const
//
//    // *fixedPtr = 'a'; //ERROR: the pointed-to data is also const
//    
    cout << "\nChap 11.5: Don't return pointers to local variables ...........................\n" ;

//    cout << "\nNote: Never return a pointer to a local variable that is about to be destroyed (same caution as with Array).\n";
//    
//    cout << "\n11.5.a - Returning a pointer to a local array creates a dangling pointer\n";
//
//    cout << "\nStep 1 - thisFunctionreturnsAnArray() creates a local array:\n";
//    cout << "         \"Don't do this\"\n";
//
//    char* text = thisFunctionreturnsAnArray();
//
//    cout << "\nStep 2 - The function has returned, so its local array has been destroyed.\n";
//    cout << "         text is now a dangling pointer.\n";
//    cout << "Note: The address itself is still a perfectly valid number. The problem is that there is no longer a valid local array living at that address.\n" ;
//
//    cout << "\nStep 3 - another function uses stack memory:\n";
//    someOtherFunction();
//
//    cout << "\nStep 4 - Reading through the dangling pointer gives undefined behaviour:\n";
//    cout << text << "\n";
//    
//    cout << "\n11.5.b - Returning a pointer to dynamically allocated memory\n";
//
//    cout << "\nStep 1 - The function allocates memory with new[] and copies the local text into it using strcpy().\n";
//
//    char* text2 = thisFunctionReturnsAPointer();
//
//    cout << "\nStep 2 - The function has returned, but the allocated memory still exists.\n";
//    cout << "         text2 still points to valid memory.\n";
//
//    cout << "\nStep 3 - another function (someOtherFunction) uses stack memory:\n";
//    someOtherFunction();
//
//    cout << "\nStep 4 - text2 is still valid because its data was allocated with new[]:\n";
//    cout << text2 << "\n";
//
//    cout << "\nStep 5 - Free the dynamically allocated memory with delete[].\n";
//    delete[] text2;
//
//    
//    cout << "Note: \n" ;
//    cout << " - Never return a pointer to a local variable\n" ;
//    cout << " - if you wish to do so, you may return pointers to member variables of an object\n" ;
//    cout << " - in the second case, it's always the object's job to make sure the data is deleted rather than the job of the caller (using destructor)\n" ;
    
    cout << "\nChap 11.6: Using pointers to share data ...........................\n" ;
    
    cout <<"\nNote: \n" ;
    cout <<" - Similar to work with array and pointers, we can use new keyword to create a long term storage for data \n";
    cout <<" - Also this long-term storage will need to be delete manually with key word delete\n" ;
    cout <<" - Subtle difference between new[] vs new, delete[] vs delete\n" ;
    
    cout << "\n11.6.a - Example of usage of new and delete\n" ;
    Pair* myPair2 = new Pair ;
    myPair2->x = 1.3 ;
    myPair2->y = 2.5 ;
    
    cout << "Pair (" ;
    cout << (myPair2->x);
    cout << ", " ;
    cout << (myPair2->y);
    cout << ")\n" ;

    delete myPair2 ;
    
    cout << "\n11.6.b - Testing the concept of Using pointer to share data with class Positions and Instruments\n" ;
    
    cout << "\nCalling testConstructPositions to test: Position, Instrument and constructPositions()\n" ;
    testConstructPositions() ;
    
    cout << "\n11.6.c - Danger: Always initialise pointers and check for nullptr\n";

    cout << "\nTest 1: Valid pointer\n";

    // constructPositions() creates Position objects whose instrument pointers
    // point to real Instrument objects.
    vector<Position> ptf = constructPositions();

    cout << "The company name for position is "
         << getCompanyName(ptf[0]) << "\n";


    cout << "\nTest 2: nullptr guardrail\n";

    // Initialise the pointer explicitly to nullptr.
    // This means the pointer deliberately points to no Instrument.
    Instrument* instrument = nullptr;

    Position p(instrument);

    // getCompanyName() checks for nullptr before dereferencing the pointer,
    // so this call is safe and should return "Name not set".
    cout << "The company name for position is "
         << getCompanyName(p) << "\n";


    /*
     IMPORTANT:

     Instrument* instrument;            // BAD: uninitialised pointer
     Instrument* instrument = nullptr;  // SAFE: explicitly points nowhere

     An uninitialised pointer contains an indeterminate address.
     It may therefore NOT compare equal to nullptr.

     In that case, a check such as:

         if (position.instrument == nullptr)

     would not necessarily protect us, and dereferencing the garbage address
     could cause EXC_BAD_ACCESS.

     Therefore:
         1. Always initialise pointers.
         2. Use nullptr when the pointer intentionally points to nothing.
         3. Check for nullptr before dereferencing when nullptr is possible (if not nasty error also).
    */
    
    cout << "\n11.6.1 - Sharing with shared_ptr\n";

    cout <<"Note: \n" ;
    cout <<" - shared_ptr (an example of smart pointer) solves the delete problem. \n" ;
    cout <<" - shared_ptr keep track of how often it has been copied\n" ;
    cout <<" - Once the number of copies of shared_ptr in existence drops to zero, the data pointed to will be deleted \n";
    cout <<" - To use shared_ptr, you need to #include <memory>\n" ;
    cout <<" - Do shared_ptr<Instrument> rather than Instrument* instrument \n" ;
    
    cout << "\nCalling testConstructPositionsV2 to test: PositionV2, Instrument and constructPositionsV2()\n" ;
    testConstructPositionsV2() ;
    
    cout << "\nFinal note:\n";
    cout << "- std::shared_ptr works well for many practical cases where ownership is shared.\n";
    cout << "- Main danger: circular references can keep the reference count above 0,\n";
    cout << "  so the objects are never deleted -> memory leak.\n";
    cout << "- Solution: break ownership cycles with std::weak_ptr,\n";
    cout << "  or design the relationships so that circular ownership does not occur.\n";
    
    cout << "\nCircular reference solutions:\n";
    cout << "- Solution 1: use std::weak_ptr for references that should not own the object.\n";
    cout << "- Solution 2: redesign ownership so only one direction owns the object,\n";
    cout << "  while the reverse relationship is only a non-owning reference.\n";
    cout << "- The key question is: who actually owns the lifetime of the object?\n";
    
    /*
     shared_ptr = "I share ownership of this object."

     weak_ptr = "I know about this object, but I do not keep it alive."

     raw pointer/reference = "I can access this object, but someone else owns it."
    
     */

    
    return EXIT_SUCCESS;
}
