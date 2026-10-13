//
//  Matrix.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 13/10/2026.
//

#include "Matrix.hpp"

Matrix::Matrix(int nrows, int ncols, bool zeros): nrows(nrows), ncols(ncols) {
    
    int size = nrows * ncols ;
    data = new double[size] ;
    endPointer = data + size ;
    if (zeros) {
        
        // memset is an optimised low level function
        // that should be faster than looping
        memset(data, 0, sizeof(double)*size) ; 
        
    }
}
