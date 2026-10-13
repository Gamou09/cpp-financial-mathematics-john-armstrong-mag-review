//
//  Matrix.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 13/10/2026.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include "testing.hpp"


class Matrix {

private:
    /* The number of the row in the matrix */
    int nrows ;
    
    /* The number of columns */
    int ncols ;
    
    /* The data in the matrix*/
    double* data ;
    
    /* Pointer to one after the end of the data*/
    double* endPointer;
    
public:
    /* The number of rows in the matrix */
    int nRows() const { return nrows ; }
    
    /* The number of columns in the matrix*/
    int nCols() const { return ncols ; }
    
    /*
     Retrieve the value at the given index
     
     using helper function offset()
         
     */
    double get(int i, int j) const {
        return data[ offset(i,j) ] ;
    }
    
    /* Set the value at the given index */
    void set( int i, int j, double value){
        data[ offset(i,j)] = value ;
    }
    
    /*offfset() performs the calculation of the whereabouts
     in the memory cell (i,j) is stored relative to the point data */
    int offset( int i, int j) const {
        
        ASSERT (i >= 0 && i < nrows && j >= 0 && j < ncols) ;
        return j*nrows + i ;
        
    }
    
    /* Constructor */
    Matrix(int nrows, int ncols, bool zeros = 1 ) ;
    
    /*
     Destructor function
     We don't have to inline the destructor
     
     Destructor rules:
     1/ A destructor is defined and declared just like a function except ...
     2/ it must have the same name as the class except with the addition of a tilde ~
     3/ it must have no return value (not even void)
     4/ it must have no parameters
     5/ it must not be const
     
     */
    
    // Danger: All classes that you wish to subclasses should have a virtual destructors !
    
    
    ~Matrix() { delete [] data ; }
};

#endif /* Matrix_hpp */
