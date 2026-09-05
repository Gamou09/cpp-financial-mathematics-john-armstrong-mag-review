//
//  main.cpp
//  ProfitCalculator
//
//  Created by Martial Aguessi on 07/05/2025.
//

#include <iostream>

using namespace std ;

int main() {
    
    // insert code here...
    double revenue ;
    double cost ;
    int taxRate ;
    double netProfit ;
    
    cout << "Please enter the revenue ? \n";
    cin >> revenue ;
    
    // for backslash do --> Option (⌥) + Shift (⇧) + : (colon key, located next to the "M" key)
    cout << "Please enter the cost ? \n" ;
    cin >> cost ;
    
    cout << "Please enter the tax rate (%) ? \n" ;
    cin >> taxRate ;
    
    double grossProfit = revenue - cost ;
    
    if (grossProfit > 0){
        netProfit = grossProfit * (1 - taxRate*0.01) ;
    } else {
        netProfit = grossProfit ;
    }
    
    cout << "The gross profit is " ;
    cout << grossProfit;
//    cout << "\n" ;
    
    cout << " and the net profit is " ;
    cout << netProfit;
    cout << "! \n" ;
    cout << "\n" ;
    
    return 0;
}
