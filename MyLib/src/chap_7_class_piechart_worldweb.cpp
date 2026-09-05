//
//  chap_7_class_piechart_worldweb.cpp
//  MyLib
//
//  Created by Martial Aguessi on 05/06/2025.
//

#include "stdafx.h"

using namespace std ;

void writeCSVChartData(ostream &out,
                       const vector<double>& x,
                       const vector<double>& y){
    ASSERT(x.size() == y.size() ) ;
    int n = (int) x.size() ;
    for (int i = 0; i < n; i++) {
        out << x[i] << "," << y[i] << "\n" ;
    }
}

void writeCSVChart(const string& filename,
                   const vector<double>& x,
                   const vector<double>& y){
    /**
     This is a basic documentation for the writeCSVChart function
     */
    ofstream out ;
    // use c_str() to convert a string back into a char*
    // char* --> a pointer to a memory address containing a sequence of characters
    out.open( filename.c_str() ) ;
    writeCSVChartData( out, x, y) ;
    out.close() ;
    
}
