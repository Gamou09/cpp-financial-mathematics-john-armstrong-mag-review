//
//  main.cpp
//  Operators
//
//  Created by Martial Aguessi on 09/05/2025.
//

#include <iostream>
#include <cmath>

using namespace std ;

int main(int argc, const char * argv[]) {

//  insert code here...
    cout << "Hello, World!\n";
    cout << "\n";
    
//  The sizeof operqtor
    size_t charSize = sizeof(char) ;
    cout << "A char takes up " ;
    cout << charSize << " bytes \n" ;
    cout << "\n";
    
//  The mathematical operqtor
    
//  operation #1
    double x = 2.3456 ;
    double y = sin(x) + cos(1.234) ;
    cout << "The answer is " << y << "\n" ;
    cout << "\n";
    
//  operation #2
//  for more info on cmath check --> https://cplusplus.com/reference/cmath/
    cout << "The 32nd power of 2 is ";
    cout << pow(2, 32) ;
    cout << "\n";
    cout << "\n";
    
//   operation #3
    double a = 2.3456 ;
    double b = sin(x) + cos(1.234) ;
    bool res = a > b ;
    cout << res ;
    cout << "\n";
    cout << "\n";
    
//   operation #4 - assignment operator
    int i = 3 ;
    int j = 0 ;
    j = ( i += 4);
    cout << "The value of i is " << i << "\n";
    cout << "The value of j is " << j << "\n";
    cout << "\n";
    
//   operation #4 - assignment operator
    int k = 3 ;
    int l = 0 ;
    l = 3 * ( k += 4);
    cout << "The value of k is " << k << "\n";
    cout << "The value of l is " << l << "\n";
    cout << "\n";

//   operation #4 - assignment operator
    int u = 3 ;
    u++;
    cout << "The value of u is " << u << "\n";
    cout << "\n";
    
//   operation #4 - assignment operator
    int z = 5 ;
    int q = ++z;
    cout << "The value of z is " << z << "\n";
    cout << "The value of q is " << q << "\n";
    cout << "\n";

//   operation #5 - assignment operator
    int s = 15 ;
    int t = s++;
    cout << "The value of s is " << s << "\n";
    cout << "The value of t is " << t << "\n";
    cout << "\n";

    
//   operation #6 - assignment operator
//    the value 0 is interpreted as false and other values are interpreted as true
    if (-1.743){
        cout << "Test passed \n" ;
    }
    cout << "\n";

//   operation #5 - assignment operator
    int var1 = 1 ;
    int var2 = 3 ;
    if (var1 == var2){
            cout << "var1 is equal to var2 \n" ;
    }
    cout << "\n";
    
    return 0;

}
