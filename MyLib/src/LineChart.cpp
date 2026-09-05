//
//  LineChart.cpp
//  MyLib
//
//  Created by Martial Aguessi on 26/06/2025.
//

#include "stdafx.h"

using namespace std ;

// definition of constructors
LineChart::LineChart() :  title("Default title"), numberOfPoints(50) {};
LineChart::LineChart(string& title_, int numberOfPoints_): title(title_), numberOfPoints(numberOfPoints_) {} ;

void LineChart::setTitle(const string& t){
    title = t ;
}

void LineChart::setNumberOfPoints(int inputNumberOfPoints){
    numberOfPoints = inputNumberOfPoints ;
}

int LineChart::getNumberOfPoints() const {
    return numberOfPoints;
}

// By setting labels and values as private in the declaration
// it is now impossibles for these two vectos to contain a different number of elements.
// because only addEntry add an element and do it for both everytime
void LineChart::addXEntry (double value) {
    x_values.push_back(value) ;
}

void LineChart::addYEntry (double value) {
    y_values.push_back(value) ;
}

static void writeTopBoilerPlateOfLineChart( ostream& out ){
    
    out << "<html>\n" ;
    out << "<head>\n" ;
    out << "<!-- Load the AJAX API -->\n" ;
    out << "<script type=\"text/javascript\" src=\"https://www.google.com/jsapi\"></script>\n" ;
    out << "<script type=\"text/javascript\">\n" ;
    out << "\n" ;
    out << "// Load the Visualization API\n" ;
    out << "// and the Line chart package\n" ;
    out << "google.load('visualization', '1.0', {'packages':['corechart']});\n" ;
    out << "\n" ;
    out << "// Set a callback to run when the\n" ;
    out << "// Google  Visualization API is loaded.\n" ;
    out << "google.charts.setOnLoadCallback(drawChart);\n" ;
    out << "\n" ;
    out << "// Callback that creates and populate a data table,\n" ;
    out << "// instantiate the Line chart, passes in the data and draws it\n" ;
    out << "function drawChart() {\n" ;
    out << "\n" ;
    out << " // Create the data table\n" ;
    out << " var data = new google.visualization.DataTable();\n" ;
    out << " data.addColumn('number', 'X') ;\n" ;
    out << " data.addColumn('number', 'Y') ;\n" ;

}

static void writeBottomBoilerPlateOfLineChart( ostream& out ){
    
    out << "\n" ;
    out << " // Set chart options\n" ;
    out << "    var options = {\n" ;
// remove the title as we want to use for different function
//    out << "        title: 'Square function: Y = X^2',\n" ;
    out << "        width : 900,\n" ;
    out << "        height : 500,\n" ;
    out << "        curveType: 'function',\n" ;
    out << "        legend: { position: 'bottom' }\n" ;
    out << "    };\n" ;
    out << "\n" ;
    out << " // Instantiate and draw our chart, passing in some options\n" ;
    out << "    var chart = new google.visualization.LineChart(document.getElementById('curve_chart'));\n" ;
    out << "    chart.draw(data, options);\n" ;
    out << "}\n" ;
    out << "\n" ;
    out << "</script>\n" ;
    out << "</head>\n" ;
    out << "<body>\n" ;
    out << "<!-- Div that will hold the Line chart -->\n" ;
    out << "<div id=\"curve_chart\" style=\"width: 900px; height: 500px\"></div>\n" ;
    out << "</body>\n" ;
    out << "</html>\n" ;
    out << "\n" ;
}

static void writeDataOfLineChart(ostream& out,
                                const vector<double>& x_values,
                                const vector<double>& y_values){
    out << "data.addRows([\n" ;
    int nLabels = (int)x_values.size() ;
    
    for (int i = 0; i <nLabels ; i++) {
        double x_value = x_values[i] ;
        double y_value = y_values[i] ;
        out << "  [" << x_value <<  ", " << y_value << "]" ;
        if (i != nLabels - 1) {
            out <<"," ;
        }
        out <<"\n" ;
    }
    out << "]);\n" ;
}


// void writeAsHTML ( std::ostream& out) const {}
void LineChart::writeAsHTML (const string& title) const {
    
    ofstream out ;
    out.open(title.c_str());
    writeTopBoilerPlateOfLineChart( out ) ;
    writeDataOfLineChart(out,x_values,y_values) ;
    writeBottomBoilerPlateOfLineChart( out ) ;
    out.close() ;
}



static void testSquareLineChartClass(){
    // just check that class compiles
    LineChart lineChart ;
    
    lineChart.setNumberOfPoints(100) ;
    int numberOfPoints = lineChart.getNumberOfPoints() ;
    
    for (int i = -1 * numberOfPoints; i <= numberOfPoints ; i++) {
        lineChart.addXEntry(i) ;
        lineChart.addYEntry(i*i) ; // because square function
    }
    
    lineChart.setTitle("Square Function New");
    lineChart.writeAsHTML("SquareFunctionNew.html") ;
}

static void testExpLineChartClass(){
    // just check that class compiles
    LineChart lineChart ;
    
    lineChart.setNumberOfPoints(100) ;
    int numberOfPoints = lineChart.getNumberOfPoints() ;
    
    for (int i = -1 * numberOfPoints; i <= numberOfPoints ; i++) {
        lineChart.addXEntry(i) ;
        lineChart.addYEntry(exp(i)) ; // because square function
    }
    
    lineChart.setTitle("Exponential Function");
    lineChart.writeAsHTML("ExponentialFunction.html") ;
}

static void testCosLineChartClass(){
    // just check that class compiles
    LineChart lineChart ;
    
    lineChart.setNumberOfPoints(100) ;
    int numberOfPoints = lineChart.getNumberOfPoints() ;
    
    for (int i = -1 * numberOfPoints; i <= numberOfPoints ; i++) {
        lineChart.addXEntry(i) ;
        lineChart.addYEntry(cos(i)) ; // because square function
    }
    
    lineChart.setTitle("Cosinus Function");
    lineChart.writeAsHTML("CosinusFunction.html") ;
}

// defintion of setSeries
void LineChart::setSeries(std::vector<double> input_x_values, std::vector<double> input_y_values){
    
    x_values = input_x_values;
    y_values = input_y_values;
}

void testLineChart(){
    
    TEST( testSquareLineChartClass ) ;
    TEST( testExpLineChartClass ) ;
    TEST( testCosLineChartClass ) ;
}

