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

// testing frameworl
#include "testing.hpp"

#include <stdio.h>

#include <stdexcept>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cassert>

#endif /* stdafx_h */
