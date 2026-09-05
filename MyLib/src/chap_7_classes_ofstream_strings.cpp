//
//  chap_7_classes_ofstream_strings.cpp
//  MyLib
//
//  Created by Martial Aguessi on 29/05/2025.
//

#include "stdafx.h"

using namespace std ;

void useOfstreamToWriteFile(){
    
    cout << "-- Start creating and writing in the ofstream file -- \n" ;
    
//    creat an ofstream
    ofstream out ;
    
//    choose where to write
    out.open("myfile.txt") ;
    
//    write in the file
    out << "The first line\n" ;
    out << "The second line\n" ;
    out << "The third line\n" ;
    out << "The fourth line\n" ;
    
//    always close when you are finished
    out.close() ;
    
    cout << "-- End of modification of  ofstream file -- \n" ;
    cout << "-- No console output but a new file (myfile.txt) created -- \n" ;

}

// be carefull ostream is different from ofstream
// it's used to pass around an ofstream by reference
void writeHaiku( ostream &out ){
    out << "The wren\n" ;
    out << "Earns his living\n" ;
    out << "Noiselessly.\n" ;
}

void testWriteHaiku(){
    
    cout << " \n-- Test of the writehaiku function with passing ofstream by ref as ostream -- \n" ;
    
    // write a Haiku to cout
    cout << "-- using std::cout (console writting) as ofstream -- \n" ;
    writeHaiku( cout ) ;
    
    // writte a Haiku to a file
    cout << "-- using file hiaku.txt as ofstream -- \n" ;
    ofstream out ;
    out.open("haiku.txt") ;
    writeHaiku( out ) ;
    out.close() ;
    cout << "-- No console output but a new file (hiaku.txt) created -- \n" ;
    
}

void testStringBasic(){
    
    cout << " \n-- Test basic string manipulation-- \n" ;
    
    // Create a string
    string s("Some text.") ; // it has to be double quotation mark
    
    // write it to a stream
    cout << s << "\n" ;
    cout << "Contains "
         << s.size() <<
    " characters \n" ;
    
    // change it
    s.insert(5, "more ") ;
    cout << s << "\n" ;
    
    // Append to it with +
    s += " Yet more text.";
    cout << s << "\n";
    
    // Test equality
    ASSERT(s == "Some more text. Yet more text.") ;
    
    cout << " \n-- Test string build up -- \n" ;
    
    // Building up string
    // With "+" --> very slow way of bulding up string
    // by constantly resizing the string objects we waste computer effort
//    string ineffString(" ") ;
//    for (int i = 0; i < 100; i++) {
//        ineffString+="blah " ;
//    }
//    cout << ineffString << "\n";
//    
//    // better option to build
//    stringstream ss ;
//    for (int i = 0; i < 100; i++) {
//        ss << "blah ";
//    }
//    
//    string effString = " " + ss.str() ;
//    cout << effString << "\n";
//    
//    ASSERT( ineffString == effString) ;
    
    using namespace std::chrono;

        // Inefficient string building using '+='
        auto startIneff = high_resolution_clock::now();

        string ineffString(" ") ;
        for (int i = 0; i < 1000000; i++) {
            ineffString += "blah " ;
        }

        auto endIneff = high_resolution_clock::now();
        auto durationIneff = duration_cast<microseconds>(endIneff - startIneff);

//        cout << ineffString << "\n";
        cout << "Inefficient build time: " << durationIneff.count() << " microseconds\n"; // circa 10,687 microseconds

        // Efficient string building using stringstream
        auto startEff = high_resolution_clock::now();

        stringstream ss ;
        for (int i = 0; i < 1000000; i++) {
            ss << "blah ";
        }
        string effString = " " + ss.str() ;

        auto endEff = high_resolution_clock::now();
        auto durationEff = duration_cast<microseconds>(endEff - startEff);

//        cout << effString << "\n";
        cout << "Efficient build time: " << durationEff.count() << " microseconds\n"; // circa 32,245 microseconds
    
//    The time measurement test do not show the effeciency of the second method - to further analysis later

        ASSERT( ineffString == effString ) ;
    
}
