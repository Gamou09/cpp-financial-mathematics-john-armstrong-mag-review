//
//  PieChart.hpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#ifndef PieChart_hpp
#define PieChart_hpp

#include "stdafx.h"

class PieChart {
    
public:
    // declaration of constructor(s)
    PieChart() ;
    PieChart(std::string& title_, std::vector<std::string> labels_, std::vector<double> values_) ;
    
    void setTitle (const std::string& title) ;
    void addEntry (const std::string& label, double value) ;
    void writeAsHTML ( std::ostream& out) const ;
    void writeAsHTML (const std::string& title) const ;
    
// By marking below member variable as private, only the member function of PieChart can see these variables
// That is the concept of encapsulation which refers to two things:
    // 1. the building together of related items into a single object
    // 2. preventing direct messing with the internal data of an object
private:
    std::string title;
    std::vector<std::string> labels ;
    std::vector<double> values ;
    
};

void testPieChart() ;

#endif /* PieChart_hpp */
