//
//  main.cpp
//  PointerExamples
//
//  Created by Martial Aguessi on 31/08/2025.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <memory> // for smart pointer: shared_pointer

using namespace std ;

// functions defitions

// function to sum value of an array
// we can't dynamically pas the length of the array to a function so we need to pass another argument
// one more reason why vector is better - if vector we could have use the metho .size()
// int toSum[] is not really an array when passed to a function. It decays to a pointer int* toSum.
// sizeof (toSum)' will return the size of the pointer, not the array itself
// thus the trick izeof(toSum) / sizeof(int) no longer works
int sumArray (int toSum[], int length) ;

// Same function using pointer
int sumUsingPointer (int* toSum, int length) ;

// Same function using pointer as a pro
int sumUsingForAndPlusPlus (int* begin, int length) ;

// compute the length of a string - with pointers
int computeLengthOfString( const char* s) ;
void testComputeLengthOfString () ;

// Pass by pointer into a function
void polarToCartesian(double r, double theta, double* x, double* y);
void testPolarToCartesian ();

// Example of combination const and pass by pointer
void constPointerExamples();

// test that we shouldn't return pointers to local variable
// we can return a string tho as a new copy of the string is given to the caller. Same for vector (return by Value)
char* thisFunctionReturnsAnArray() ;
void someOtherFunction();
void testDontReturnArrays();

// valid function that return a Pointer but failed the convention of - if you create something, it's your job to delete it
char* thisFunctionReturnsAPointer();
void testReturnPointerJustAboutOK();

// Class
// creation of class Pair
class Pair{
    
public:
    double x ;
    double y ;
    Pair() {x = 0; y = 0 ; } ;
    Pair (double x, double y) ;
};

// Since we used numbers elements
// we can create this class
// this is awfully similar to the data type vector
class IntArray{
    
public:
    int* firstElement;
    int length ;
};

// Using pointers to share data
class Instrument{
    
public:
    string bloombergTicker ;
    string ricCode ;
    string companyName ;
    Instrument() {}
    
} ;

class Position {
    
public:
    string trader ;
    double quantity ;
    Instrument* instrument ;
    Position () = default ;
    explicit Position(Instrument* instrument);
    
    string getCompanyName( Position& position);
};

// construct position functions
vector<Position> constructPositions() ;
void testConstructionPositions() ;

// Sharing data with shared_ptr - most used smart pointer who solve the issue of delete []
// A smart pointer (from <memory>) that manages the lifetime of a dynamically allocated object.
// Unlike a raw pointer, it automatically deletes the object when it’s no longer used.
// It uses reference counting → multiple shared_ptrs can share ownership of the same object.
// When the last one goes out o scope, the object is destroyed.

// other smart pointer (opposite of smart pointer is called raw pointer):
// unique_ptr = sole owner
// shared_ptr = shared owners
// weak_ptr = observer, no ownership, avoid cycles, weak ref
// auto_ptr = ❌ don’t use, obsol
class PositionV2 {

public:
    string trader ;
    double quantity ;
    shared_ptr<Instrument> instrument ;
    PositionV2() = default ;
    explicit PositionV2( shared_ptr<Instrument> ins) ;
    
};

// construct position functions
vector<PositionV2> constructPositionsV2() ;
void testConstructionPositionsV2() ;

// Sharing data with references
class PositionV3 {

public:
    string trader ;
    double quantity ;
    Instrument& instrument ;
    explicit PositionV3( Instrument& instrument) ;
    
};

// construct position functions
vector<PositionV3> constructPositionsV3() ;
void testConstructionPositionsV3() ;


// Main body
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n\n";
    
    cout << "11.1 - Arrays, the alternative to vector\n";
    
    // create an uninitialised array of length 5
    int myUninitialisedArray[5] ;
    for (int i = 0; i < 5; i++) {
        cout << "Entry " << i << "=" ;
        cout << myUninitialisedArray[i] ;
        cout << "\n" ;
    }
    
    // size of an array
    cout << "\n" ;
    cout << "Size of myArray is " << sizeof(myUninitialisedArray)/sizeof(int) << "\n";
    
    // create an initialised array of length 5 with set values
    cout << "\n" ;
    int myInitialisedArray[] = {100, 200, 300, 400, 500} ;
    for (int i = 0; i < 5; i++) {
        cout << "Entry " << i << "=" ;
        cout << myInitialisedArray[i] ;
        cout << "\n" ;
    }
    
    // create an initialised array of length 5 with set 0
    cout << "\n" ;
    int myInitialisedWithZeroArray[5] = {} ;
    for (int i = 0; i < 5; i++) {
        cout << "Entry " << i << "=" ;
        cout << myInitialisedWithZeroArray[i] ;
        cout << "\n" ;
    }
    
    // create an initialised array of length 7 with only 3 given value
    cout << "\n" ;
    int myInitialisedWithRestZeroArray[7] = {100, 200, 200} ;
    for (int i = 0; i < 7; i++) {
        cout << "Entry " << i << "=" ;
        cout << myInitialisedWithRestZeroArray[i] ;
        cout << "\n" ;
    }
    
    // test function sumArray
    cout << "\n" ;
    cout << "Sum of elements of myUninitialisedArray is " << sumArray(myUninitialisedArray, 5) << "\n" ;
    cout << "Sum of elements of myInitialisedArray is " << sumArray(myInitialisedArray, 5) << "\n" ;
    cout << "Sum of elements of myInitialisedWithZeroArray is " << sumArray(myInitialisedWithZeroArray, 5) << "\n" ;
    cout << "Sum of elements of myInitialisedWithRestZeroArray is " << sumArray(myInitialisedWithRestZeroArray, 5) << "\n" ;
    
    // create an initialised 3by5 array
    // the syntax is self-explanatory but only strange part is that we have to specify all the dimension but the first
    cout << "\n" ;
    int myMultiDimensionArray[][5] = {{1, 2, 3, 4, 5}, {10, 20, 30, 40, 50}, {100, 200, 300, 400, 500}} ;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Entry (" << i << "," << j << ")=";
            cout << myMultiDimensionArray[i][j] ;
            cout << "\n" ;
        }
    }
    
    // Creation of pointer (int*) with operator new []
    // we go to pointers after arrays as we can't return the array value from a function
    // when you return a double or vector from a function, the value is copied but that is impossible for array
    // so they won't outlive the scope of the function - stack memory
    // we need to think of them as returned by reference
    // so point will be help as allocating memory in the heap
    
    // Computer memory reminder
    // Small, short-lived variables → stack.
    // Large, flexible, or shared data → heap
    cout << "\n" ;
    cout << "11.2 - Pointers\n";
    
    int n = 5 ;
    int* myPointerArray = new int[n] ;
    for (int i = 0; i < n; i++) {
        cout << "Entry " << i << "=" ;
        cout << myPointerArray[i] ;
        cout << "\n" ;
    }
    delete [] myPointerArray ; // mandatory as the new memory allocated with the new [] operator is not delete automatically
    
    // Use the new [] operator other data types - point to a Pair
    cout << "\n" ;
    int numPairs = 5 ;
    Pair* myPairs = new Pair[numPairs] ;
    for (int i = 0; i < numPairs; i++) {
        double xValue = myPairs[i].x ;
        double yValue = myPairs[i].y ;
        
        cout << "Pair (" ;
        cout << xValue ;
        cout << ", ";
        cout << yValue ;
        cout << ")\n" ;
    }
    delete [] myPairs ;
    
    // Pointer operator 'new []' to create it or '&' to read the value of memory address designated by the pointer
    cout << "\n" ;
    
    int* fivePrimes = new int[5] ;
    fivePrimes[0] = 2 ;
    fivePrimes[1] = 3 ;
    fivePrimes[2] = 5 ;
    fivePrimes[3] = 7 ;
    fivePrimes[4] = 11 ;
    
    // memory address in the heap for the first prime - in the heap
    cout << "the memory address of the fivePrimes is " <<fivePrimes << "\n" ;
    // Pointer of pointer - memory address in the stack of the variable fivePrimes itself
    cout << "the memory address of the fivePrimes is " <<&fivePrimes << "\n" ; // memory address in the stack
    
    // secpnd illustration
    cout << "\n" ;
    int myVariable = 10 ;
    int* pointerToMyVariable = &myVariable ;
    
    cout << "memory location of myVariable " << pointerToMyVariable << "\n" ;
    cout << "memory location of myVariable " << &myVariable << "\n" ;
    cout << "Value of myVariable " << (*pointerToMyVariable) << "\n" ;
    
    // Another pointer operator '->'
    cout << "\n" ;
    Pair p ;
    Pair* pointerToP = &p ;
    
    // use -> to acces field via a pointer
    pointerToP -> x = 123.0 ;
    pointerToP -> y = 465.0 ;
    
    // we check that p has changed
    cout << "Value of x = " << p.x << "\n" ;
    cout << "Value of y = " << p.y << "\n" ;
    
    // we check that p with *
    cout << "Value of x = " << (*pointerToP).x << "\n" ;
    cout << "Value of y = " << (*pointerToP).y << "\n" ;
    
    // test function sumArray
    cout << "\n" ;
    cout << "Sum of elements of myInitialisedArray with sumArray is " << sumArray(myInitialisedArray, 5) << "\n" ;
    cout << "Sum of elements of myInitialisedArray with sumUsingPointer is " << sumUsingPointer(myInitialisedArray, 5) << "\n";
    cout << "Sum of elements of myInitialisedArray with sumUsingForAndPlusPlus is " << sumUsingForAndPlusPlus(myInitialisedArray, 5) << "\n";

    // Large, flexible, or shared data → heap
    cout << "\n" ;
    cout << "11.3 - Pointers to text\n";
    
    // the code number O in ASCII isn't used to represent any character or symbol
    // so it can be safely used to mark the end of a block of memory
    // "A' is encoded with 65, "1' with 49, "0" with 48
    // C-style string or "null-terminated string"
    char charArray1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    for (int i = 0; i < 6; i++) {
        cout << "ASCII value " ;
        char c = charArray1[i] ;
        cout << ((int) c) ;
        cout << "\n" ;
        
    }
    
    // using the char* type
    // we should avoid char* as much as possible - string to be prefered
    cout << "\n" ;
    const char* charArray2 = "Hello";
    for (int i = 0; i < 6; i++) {
        cout << "ASCII value " ;
        char c = charArray2[i] ;
        cout << ((int) c) ;
        cout << "\n" ;
    }
    
    // use of pointer to implement replicate the behaviour of strlen, strcpy
    cout << "\n" ;
    cout << "Number of array of " << charArray2 << " is " << computeLengthOfString(charArray2) << "\n" ;
    testComputeLengthOfString() ;
    
    // making sure to have an out of the bound check
    cout << "\n" ;
    char* shortText = new char[20] ;
    for (int i = 0; i < 1000; i++) {
        shortText[i] = 'x' ;
    }
    cout  << shortText << "\n";
    delete [] shortText ;
    
    // making sure to have an out of the bound check
    cout << "\n" ;
    testPolarToCartesian() ;
    
    // const char* or char* const
    cout << "\n" ;
    constPointerExamples() ;
    
    // test pointer to char data
    cout << "\n" ;
    testConstructionPositions();
    
    // test pointer to char data
    cout << "\n" ;
    testConstructionPositionsV2();
    
    // test pointer to char data
    cout << "\n" ;
    testConstructionPositionsV3();
    
    this_thread::sleep_for(std::chrono::seconds(5));
    
    cout << "\n" ;
    return 0;
}

// Function declaration
int sumArray(int toSum[], int length){
    
    int sum = 0 ;
    for (int i = 0; i < length; i++) {
        sum += toSum[i] ;
    }
    
    return sum;
    
}

int sumUsingPointer (int* toSum, int length){
  
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += toSum[i] ;  // no difference with when we pass an array
    }
    return sum ;
}

int sumUsingForAndPlusPlus (int* begin, int length){
    
    int sum = 0;
    int* end = begin + length ; // pointer arithmetic
    for (int* ptr = begin; ptr != end ; ptr++) {
        sum += *ptr ;  // add the value store in memore
    }
    return sum ;
    
}

int computeLengthOfString( const char* s){
    
    int length = 0 ;
    while ( (*s) != 0) {
        s++;
        length++;
    }
    
    return length ;
    
}

void testComputeLengthOfString (){
    
    const char* quotation = "To be or not to be" ;
    int l1 = computeLengthOfString(quotation) ;
    int l2 = (int)strlen(quotation) ; // built-in
    
    cout << "Comparison is " << l1 << ", " << l2 << "\n" ;
    
}

// Pass by pointer into a function
void polarToCartesian(double r, double theta, double* x, double* y){
    
    *x = r*cos(theta) ;
    *y = r*sin(theta) ;
}

void testPolarToCartesian (){
    
    double r = 2 ;
    double theta = atan(1) ;
    double x, y ;
    polarToCartesian(r, theta, &x, &y) ;
    cout << "Check value of x and sqrt(2) : " << x << ", " << sqrt(2) << "\n";
    cout << "Check value of y and sqrt(2) : " << y << ", " << sqrt(2) << "\n";
}

// Example of combination const and pass by pointer
void constPointerExamples(){
    
    const char* ptr = "A string"; // with const at the left end side, the data that is pointed to cannot be modified
    
    ptr++;
    cout << (*ptr) ;
    // (*ptr) = 'a' ; // You can't change the data using const char*
    
    char* fiveChars = new char[5] ;
    char * const constPtr = fiveChars ; // with const at the right end side, the pointer itself cannot be modified
    // constPtr++ ; // You can't change the pointer using const char*
    (*constPtr) = 'h' ; // but we can change what it points to

}

/*
 // Commented since we have ask IDE to consider warning as error
// test that we shouldn't return pointers to local variable
char* thisFunctionReturnsAnArray(){
    
    // This prodices a compiler warning
    char text[] = "Don't do this" ;
    return text ;
    
}


void someOtherFunction(){
    
    char text[] = "Alternative text\n" ;
    cout << text ;
    cout << "\n" ;
    
}

 // Commented since we have ask IDE to consider warning as error
void testDontReturnArrays(){
    char* text = thisFunctionReturnsAnArray() ;
    someOtherFunction() ;
    cout << text ;
    cout << "\n" ;
}


// valid function that return a Pointer but failed the convention of - if you create something, it's your job to delete it
char* thisFunctionReturnsAPointer(){
    char text[] = "This works";
    int n = (int) strlen(text) ;
    char* ret = new char[n+1];
    // We now get a compiler warning here
    strcpy(ret, text) ;
    return ret ;
}

void testReturnPointerJustAboutOK(){
    char* text = thisFunctionReturnsAnArray() ;
    someOtherFunction() ;
    cout << text ;
    cout << "\n" ;
    // don't forget to free the memory
    delete [] text ;
}

 */

Position::Position ( Instrument* instrument ): instrument( instrument) {} ;

// construct position functions
vector<Position> constructPositions(){
    
    // the caller of this function
    // should call delete on the instrument
    // when they are done with all the positions
    vector<Position> positions ;
    
    // Instrument* instrument  ; // Never do that; you should always initialised a point before using
    // maybe initialised in that case to nullptr
    Instrument* instrument = new Instrument;
    instrument -> companyName = "Google" ;
    instrument -> bloombergTicker = "GOOG US Equity" ;
    instrument -> ricCode = "GOOG.OQ" ;
    
    Position p1(instrument) ;
    p1.trader = "Han" ;
    p1.quantity = 100.0;
    positions.push_back(p1);
    
    Position p2(instrument) ;
    p2.trader = "Leia" ;
    p2.quantity = -100.0;
    // p2.instrument = instrument ;
    positions.push_back(p2);
    
    Position p3 ;
    p3.trader = "Martial" ;
    p3.quantity = 50.0;
    p3.instrument = instrument ;
    positions.push_back(p3);
    
    return  positions ;
}

void testConstructionPositions(){
    vector<Position> r = constructPositions() ;
    int n = (int) r.size() ;
    
    for (int i = 0; i < n; i++) {
        cout << "Position " << i+1 << "\n" ;
        Position& p = r[i] ;
        cout << "Trader: " << p.trader << "\n" ;
        cout << "Quantity: " << p.quantity << "\n" ;
        cout << "Instrument: ";
        cout << p.instrument -> companyName << "\n" ;
        cout << "\n" ;
    }
    
    delete r[0].instrument ;
}

// use of null pointer when we want to first use initialisation to nothing
string Position::getCompanyName( Position& position){
    if (position.instrument == nullptr) {
        return "Name not set" ;
    } else {
        return position.instrument -> companyName ;
    }
}

PositionV2::PositionV2( shared_ptr<Instrument> ins): instrument(ins) {} ;

// construct position functions
vector<PositionV2> constructPositionsV2(){
    
    // the caller of this function
    // should call delete on the instrument
    // when they are done with all the positions
    vector<PositionV2> positions ;
    
    // use share pointer
    shared_ptr<Instrument> ins = make_shared<Instrument>() ;
    
    ins -> companyName = "AAPL" ;
    ins -> bloombergTicker = "AAPL US Equity" ;
    ins -> ricCode = "AAPL.OQ" ;
    
    PositionV2 p1(ins) ;
    p1.trader = "Han" ;
    p1.quantity = 50.0;
    positions.push_back(p1);
    
    PositionV2 p2(ins) ;
    p2.trader = "Leia" ;
    p2.quantity = -50.0;
    // p2.instrument = instrument ;
    positions.push_back(p2);
    
    PositionV2 p3 ;
    p3.trader = "Martial" ;
    p3.quantity = 150.0;
    p3.instrument = ins ;
    positions.push_back(p3);
    
    return  positions ;
}

void testConstructionPositionsV2(){
    vector<PositionV2> r = constructPositionsV2() ;
    int n = (int) r.size() ;
    
    for (int i = 0; i < n; i++) {
        cout << "Position " << i+1 << "\n" ;
        PositionV2& p = r[i] ;
        cout << "Trader: " << p.trader << "\n" ;
        cout << "Quantity: " << p.quantity << "\n" ;
        cout << "Instrument: ";
        cout << p.instrument -> companyName << "\n" ;
        cout << "\n" ;
    }
    
    // delete r[0].instrument ; // main difference with original implementation
}


// construct position functions with pass reference
PositionV3::PositionV3( Instrument& instrument): instrument(instrument) {} ;

vector<PositionV3> constructPositionsV3(){
    // This function doesn't work
    // the instrument is deleted
    // so all the returned positions contain broken references
    vector<PositionV3> positions ;
    
    Instrument instrument ;
    instrument.companyName = "TSLA" ;
    instrument.bloombergTicker = "TSLA US Equity" ;
    instrument.ricCode = "TSLA.OQ" ;
    
    PositionV3 p1(instrument) ;
    p1.trader = "Han" ;
    p1.quantity = 150.0;
    positions.push_back(p1);
    
    PositionV3 p2(instrument) ;
    p2.trader = "Leia" ;
    p2.quantity = -150.0;
    // p2.instrument = instrument ;
    positions.push_back(p2);
    
    PositionV3 p3(instrument) ; ;
    p3.trader = "Martial" ;
    p3.quantity = 250.0;
    p3.instrument = instrument ;
    positions.push_back(p3);

    return positions;
    
}
void testConstructionPositionsV3(){
    
    vector<PositionV3> positions = constructPositionsV3() ;
    int n = (int) positions.size() ;
    
    for (int i = 0; i < n; i++) {
        cout << "Position " << i+1 << "\n" ;
        PositionV3 p = positions[i] ;
        cout << "Trader: " << p.trader << "\n" ;
        cout << "Quantity: " << p.quantity << "\n" ;
        cout << "Instrument: ";
        cout << p.instrument.companyName << "\n" ;
        cout << "\n" ;
    }
    
    // delete positions[0].instrument;
}
