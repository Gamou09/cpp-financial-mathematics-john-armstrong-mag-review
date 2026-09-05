//
//  LineChart.hpp
//  MyLib
//
//  Created by Martial Aguessi on 26/06/2025.
//

#ifndef LineChart_hpp
#define LineChart_hpp

#include "stdafx.h"

class LineChart {
    
public:
    // Constructor declaration
    LineChart() ;
    LineChart(std::string& title_, int numberOfPoints_) ;
    
    
    void setTitle (const std::string& title) ;
    void setNumberOfPoints (int numberOfPoints) ;
    void setSeries(std::vector<double> input_x_values, std::vector<double> input_y_values) ;
    
    void addXEntry (double value) ;
    void addYEntry (double value) ;
    void writeAsHTML (std::ostream& out) const ;
    void writeAsHTML (const std::string& title) const ;
    
    int getNumberOfPoints() const ; 
    
// By marking below member variable as private, only the member function of PieChart can see these variables
// That is the concept of encapsulation which refers to two things:
    // 1. the building together of related items into a single object
    // 2. preventing direct messing with the internal data of an object
private:
//    int numberOfPoints;
    std::string title;
    std::vector<double> x_values ;
    std::vector<double> y_values ;
    int numberOfPoints ;
    
};

void testLineChart() ;


#endif /* LineChart_hpp */
