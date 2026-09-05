//
//  stdafx.h
//  MyLib
//
//  Created by Martial Aguessi on 21/05/2025.
//

#ifndef stdafx_h
#define stdafx_h

// Windows convention expanded to all operating systems
// very usefull to save time typing
// also fasten the pre-processing step during compilation

// Associated header file
// don't forgot the use convention to gather all header in a stdafx.h header file
#include "matlib.h"

// for geo
#include "geometry.hpp"

// for derivatives
#include "derivatives.hpp"

// include built in library
#include <cmath>
#include <stdexcept>
 
// testing framework
#include "testing.hpp"

#include <stdio.h>

#include <stdexcept>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cassert>

// Adding include for chap 7 - using c++ classes

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>

#include "chap_7_classes.hpp"
#include "chap_7_classes_ofstream_strings.hpp"
#include "chap_7_class_piechart_worldweb.hpp"

#include "charts.h"

#include "chap_7_solutions_to_exercises.hpp"

#include <numeric> // std::accumulate

#include <cstdlib>     /* srand, rand */
#include <random>

#include <algorithm> // std::sort ()

// from Chapter 10 - Interface but need to be include before any class implementing that interface since Compiler reads linearly
#include "PathIndependentOption.hpp"


// chap 8
#include "BlackScholesModel.hpp"

#include "CallOption.hpp"

#include "PieChart.hpp"

#include "PutOption.hpp"

#include "LineChart.hpp"

#include "Polynomial.hpp"

// chap 9
#include "MonteCarloPricer.hpp"


#endif /* stdafx_h */


