//
//  charts.cpp
//  MyLib
//
//  Created by Martial Aguessi on 06/06/2025.
//


#include "stdafx.h"

using namespace std ;

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

static void writeFixedPieChartData( ostream& out ){
    out << " data.addRows([\n" ;
    out << "  ['Bananas', 100],\n" ;
    out << "  ['Apples', 200],\n" ;
    out << "  ['Kumquats', 150]\n" ;
    out << " ]);\n" ;
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

static void testFixedPieChart(){
    ofstream out ;
    out.open("FixedPieChart.html") ;
    writeTopBoilerPlateOfPieChart(out) ;
    writeFixedPieChartData(out) ;
    writeBottomBoilerPlateOfPieChart(out) ;
    out.close() ;
}

static void testPieChartData(){
    
    // this test automates the checking
    stringstream out ;
    vector<string> labels(3) ;
    vector<double> values(3) ;
    for (int i=0; i < 3; i++) {
        stringstream ss ;
        ss << "A Label "<<i ;
        labels[i] = ss.str() ;
        INFO( labels[i] ) ;
        values[i] = (double) i ;
    }
    
    writeDataOfPieChart(out, labels, values) ;
    
    string asString = out.str() ;
    
    INFO(asString) ;
    
    stringstream expected ;
    expected << "data.addRows([\n" ;
    expected << "  ['A Label 0', 0],\n" ;
    expected << "  ['A Label 1', 1],\n" ;
    expected << "  ['A Label 2', 2]\n" ;
    expected << "]);\n" ;
    
    string expectedStr = expected.str() ;
    
    INFO(expectedStr) ;
    
    ASSERT( asString == expectedStr ) ;
}

void pieChart(const string& file,
              const vector<string>& labels,
              const vector<double>& values){
    ofstream out ;
    out.open(file.c_str());
    writeTopBoilerPlateOfPieChart( out ) ;
    writeDataOfPieChart(out, labels, values) ;
    writeBottomBoilerPlateOfPieChart( out ) ;
    out.close() ;
}

// 7.7.8 - Line chart & option payoff

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

static void writeDataSquareLineChart( ostream& out,
                                 const int numberOfPoints){
    out << "data.addRows([\n" ;
    
    for (int i = -1 * numberOfPoints; i <= numberOfPoints ; i++) {
        out << "  [" << i <<  ", " << i*i << "]" ;
        if (i != numberOfPoints) {
            out <<"," ;
        }
        out <<"\n" ;
    }
    out << "]);\n" ;
}

static void testSquareLineChartData(){
    
    // this test automates the checking
    stringstream out ;
    int numberOfPoints = 5 ;
    writeDataSquareLineChart(out, numberOfPoints) ;
    
    string asString = out.str() ;
    
    INFO(asString) ;
    
    stringstream expected ;
    expected << "data.addRows([\n" ;
    expected << "  [-5, 25],\n" ;
    expected << "  [-4, 16],\n" ;
    expected << "  [-3, 9],\n" ;
    expected << "  [-2, 4],\n" ;
    expected << "  [-1, 1],\n" ;
    expected << "  [0, 0],\n" ;
    expected << "  [1, 1],\n" ;
    expected << "  [2, 4],\n" ;
    expected << "  [3, 9],\n" ;
    expected << "  [4, 16],\n" ;
    expected << "  [5, 25]\n" ;
    expected << "]);\n" ;
    
    string expectedStr = expected.str() ;
    
    INFO(expectedStr) ;
    
    ASSERT( asString == expectedStr ) ;
}

void SquareLineChart(const string& file, const int numberOfPoints){
    ofstream out ;
    out.open(file.c_str());
    writeTopBoilerPlateOfLineChart( out ) ;
    writeDataSquareLineChart(out, numberOfPoints) ;
    writeBottomBoilerPlateOfLineChart( out ) ;
    out.close() ;
}

static void testSquartLineChart(){
    
    string file = "SquareFunctionLineChart.html" ;
    int numberOfPoints = 30 ;
    SquareLineChart(file, numberOfPoints) ;
}

// Write put option price
// NO test for this function since we have already test black and should function
static void writeDataPutOptionChart(ostream& out,
                                     const double K,
                                     const double r, const double sigma, const double T){
    out << "data.addRows([\n" ;
    
    int maxUnderlying = (int)5*K ;
    
    for (int S = 0; S <= maxUnderlying ; S++) {
        out << "  [" << S <<  ", " << black_scholes_put(S, K, r, sigma, T) << "]" ;
        if (S != maxUnderlying) {
            out <<"," ;
        }
        out <<"\n" ;
    }
    out << "]);\n" ;
    
}

static void putOptionChart(const string& file,
                            const double K,
                            const double r, const double sigma, const double T){
    ofstream out ;
    out.open(file.c_str());
    writeTopBoilerPlateOfLineChart( out ) ;
    writeDataPutOptionChart(out, K, r, sigma, T) ;
    writeBottomBoilerPlateOfLineChart( out ) ;
    out.close() ;
}


void testPutOptionChart(){
    
    string file = "PutOptionLineChart.html" ;
    double K = 100.0 ;
    double sigma = 0.2 ;
    double r = 0.05 ;
    double T = 1 ;
    putOptionChart(file,K, r, sigma, T) ;
}

// Write put option price
// NO test for this function since we have already test black and should function
static void writeDataCallOptionChart(ostream& out,
                                     const double K,
                                     const double r, const double sigma, const double T){
    out << "data.addRows([\n" ;
    
    int maxUnderlying = (int) 5*K ;
    
    for (int S = 0; S <= maxUnderlying ; S++) {
        out << "  [" << S <<  ", " << black_scholes_call(S, K, r, sigma, T) << "]" ;
        if (S != maxUnderlying) {
            out <<"," ;
        }
        out <<"\n" ;
    }
    out << "]);\n" ;
    
}

static void callOptionChart(const string& file,
                            const double K,
                            const double r, const double sigma, const double T){
    ofstream out ;
    out.open(file.c_str());
    writeTopBoilerPlateOfLineChart( out ) ;
    writeDataCallOptionChart(out, K, r, sigma, T) ;
    writeBottomBoilerPlateOfLineChart( out ) ;
    out.close() ;
}


void testCallOptionChart(){
    
    string file = "CallOptionLineChart.html" ;
    double K = 100.0 ;
    double sigma = 0.2 ;
    double r = 0.05 ;
    double T = 1 ;
    callOptionChart(file,K, r, sigma, T) ;
}


// 7.7.9 - percentile

double prctile (vector<double> vec, double p){
    
    // need to create a copy of vec since sort modify the vector
    vector<double> vec_copy = vec ;
    sort(vec_copy.begin(), vec_copy.end()) ;
    
    double raw_position_p = ( (p/100) * (vec_copy.size() - 1) )  ;
    
    if (floor(raw_position_p) == raw_position_p) {
        return vec_copy[raw_position_p];
    } else {
        double floor_position_p = floor(raw_position_p) ;
        double ceil_position_p = ceil(raw_position_p) ;
        double frac_raw_pos_p = (raw_position_p - floor_position_p) ;
        double delta_neighbours = vec_copy[ceil_position_p] - vec_copy[floor_position_p] ;
        double res = vec_copy[floor_position_p] + frac_raw_pos_p * delta_neighbours ;
        return  res ;
    }
    
}

void testPrctile(){
    
    // Test vector all positive
    vector<double> vec = make_vector({22, 11, 55, 4}) ;
    
    // test O-pth to be the smallest always
    double res_0 = prctile(vec, 0) ;
    assert( res_0 == 4) ;
    
    // test 100-pth to be the largest always
    double res_100 = prctile(vec, 100) ;
    assert( res_100 == 55) ;
    
    // test 100-pth to be the largest always
    double res_60 = prctile(vec, 60) ;
    ASSERT_APPROX_EQUAL(res_60, 19.8, 1e-1) ;
    
    // Test vector for mix
    vector<double> vec_2 = make_vector({22, 0, -55, 4}) ;
    
    // test O-pth to be the smallest always
    double res_2_0 = prctile(vec_2, 0) ;
    assert( res_2_0 == -55) ;
    
    // test 100-pth to be the largest always
    double res_2_100 = prctile(vec_2, 100) ;
    assert( res_2_100 == 22) ;
    
    // test 100-pth to be the largest always
    double res_2_60 = prctile(vec_2, 60) ;
    ASSERT_APPROX_EQUAL(res_2_60, 3.2, 1e-1) ;
}

void testCharts (){
    cout << "\n-- Start Test Charts -- \n" ;
    TEST( testFixedPieChart ) ;
    TEST( testPieChartData ) ;
    TEST( testSquareLineChartData ) ;
    TEST( testSquartLineChart ) ;
    TEST( testPutOptionChart ) ;
    TEST( testCallOptionChart ) ;
    TEST( testPrctile ) ;
}


