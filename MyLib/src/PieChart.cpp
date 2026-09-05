//
//  PieChart.cpp
//  MyLib
//
//  Created by Martial Aguessi on 25/06/2025.
//

#include "stdafx.h"

using namespace std ;

// definition of constructor
PieChart::PieChart(): title("Default Ttitle"), labels(vector<string>({"Default value"})), values(vector<double>(10)) {};

PieChart::PieChart(string& title_, vector<string> labels_, vector<double> values_): title(title_), labels(labels_), values(values_) {};

void PieChart::setTitle(const string& t){
    title = t ;
}

// By setting labels and values as private in the declaration
// it is now impossibles for these two vectos to contain a different number of elements.
// because only addEntry add an element and do it for both everytime
void PieChart::addEntry(const string& label, double value){
    labels.push_back(label) ;
    values.push_back(value) ;
}

static void writeTopBoilerPlateOfPieChart( ostream& out ){
    
    out << "<html>\n" ;
    out << "<head>\n" ;
    out << "\n" ;
    out << "<!-- Load the AJAX API -->\n" ;
    out << "<script type=\"text/javascript\"" ;
    out << "src=\"https://www.google.com/jsapi\">\"</script>\n" ;
    out << "<script type=\"text/javascript\">\n" ;
    out << "\n" ;
    out << "// Load the Visualization API\n" ;
    out << "// and the pie chart package\n" ;
    out << "google.load('visualization', '1.0', {'packages':['corechart']});\n" ;
    out << "\n" ;
    out << "// Set a callback to run when the\n" ;
    out << "// Google  Visualization API is loaded.\n" ;
    out << "google.charts.setOnLoadCallback(drawChart);\n" ;
    out << "\n" ;
    out << "// Callback that createq  and populate a data table,\n" ;
    out << "// instantiate the pie chart, passes in the data and draws it\n" ;
    out << "function drawChart() {\n" ;
    out << "\n" ;
    out << " // Create the data table\n" ;
    out << " var data = new google.visualization.DataTable();\n" ;
    out << " data.addColumn('string', 'Label') ;\n" ;
    out << " data.addColumn('number', 'Value') ;\n" ;

}

static void writeBottomBoilerPlateOfPieChart( ostream& out ){
    
    out << "\n" ;
    out << " // Set chart options\n" ;
    out << " var options = {\n" ;
    out << "  'title' : 'Pizza Toppings',\n" ;
    out << "  'width' : 400,\n" ;
    out << "  'height' : 300\n" ;
    out << " };\n" ;
    out << "\n" ;
    out << " // Instantiate and draw our chart, passing in some options\n" ;
    out << " var chart = new google.visualization.PieChart(document.getElementById('chart_div'));\n" ;
    out << " chart.draw(data, options);\n" ;
    out << "}\n" ;
    out << "\n" ;
    out << "</script>\n" ;
    out << "</head>\n" ;
    out << "<body>\n" ;
    out << "<!-- Div that will hold the pie chart -->\n" ;
    out << "<div id=\"chart_div\"></div>\n" ;
    out << "</body>\n" ;
    out << "</html>\n" ;
    out << "\n" ;
}

static void writeDataOfPieChart( ostream& out,
                                 const vector<string>& labels,
                                 const vector<double>& values){
    out << "data.addRows([\n" ;
    int nLabels = (int)labels.size() ;
    
    for (int i = 0; i <nLabels ; i++) {
        string label = labels[i] ;
        double value = values[i] ;
        out << "  ['" << label <<  "', " << value << "]" ;
        if (i != nLabels - 1) {
            out <<"," ;
        }
        out <<"\n" ;
    }
    out << "]);\n" ;
}

// void writeAsHTML ( std::ostream& out) const {}
void PieChart::writeAsHTML (const string& title) const {
    
    ofstream out ;
    out.open(title.c_str());
    writeTopBoilerPlateOfPieChart( out ) ;
    writeDataOfPieChart(out, labels, values) ;
    writeBottomBoilerPlateOfPieChart( out ) ;
    out.close() ;
}

static void testPieChartClass(){
    // just check that class compiles
    PieChart pieChart ;
    pieChart.addEntry("Mushroom", 200) ;
    pieChart.addEntry("Salami", 100) ;
    pieChart.addEntry("Spinach", 150) ;
    pieChart.setTitle("Pizza Topping");
    
    pieChart.writeAsHTML("PizzaPie.html") ;
}


void testPieChart(){
    
    TEST( testPieChartClass) ;
}
