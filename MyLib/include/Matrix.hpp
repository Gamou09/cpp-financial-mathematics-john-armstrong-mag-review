//
//  Matrix.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 13/10/2026.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include "testing.hpp"

#include <vector>
#include <string>

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
    
    /* Default constructor: creates a 1x1 zero matrix */
    Matrix();

    /* Construct a column vector from a std::vector.
       Set asRow = true to construct a row vector instead. */
    explicit Matrix(const std::vector<double>& values,
                    bool asRow = false);

    /* Construct a 1x1 matrix containing a scalar */
    explicit Matrix(double scalar);

    /* Construct a matrix from a string.
       Example: "1,2,3;4,5,6" creates a 2x3 matrix. */
    explicit Matrix(const std::string& contents);
    
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
    
    /* Acces a pointer to the first element */
    /* For const objects: allows reading only. */
    const double* begin() const {
        return data;
    }

    /* Acces a pointer to the element after last */
    /* For const objects: marks the end of the read-only range. */
    const double* end() const {
        return endPointer;
    }

    /* Acces a pointer to the first element */
    /* For non-const objects: allows reading and modifying elements. */
    double* begin() {
        return data;
    }

    /* Acces a pointer to the element after last */
    /* For non-const objects: marks the end of the modifiable range. */
    double* end() {
        return endPointer;
    }

    /* Multiply corresponding elements of two matrices
        Hadamard or Shur product
     */
    Matrix times(const Matrix& other) const;
};

/* Add two matrices
 NB - not a member function */
Matrix operator+ (const Matrix& x, const Matrix& y) ;

/* Add a scalar to every element of a matrix
 NB - not a member function */
Matrix operator+ (const Matrix& m, double scalar) ;

/* Add a scalar to every element of a matrix (other way)
 NB - not a member function */
Matrix operator+ (double scalar, const Matrix& m) ;

/* Subtract two matrices
   NB - not a member function */
Matrix operator- (const Matrix& x, const Matrix& y);

/* Subtract a scalar from every element of a matrix
   NB - not a member function */
Matrix operator- (const Matrix& m, double scalar);

/* Subtract every element of a matrix from a scalar
   NB - not a member function */
Matrix operator- (double scalar, const Matrix& m);

/* Multiply two matrices using standard matrix multiplication
   NB - not a member function */
Matrix operator* (const Matrix& x, const Matrix& y);

/* Multiply every element of a matrix by a scalar
   NB - not a member function */
Matrix operator* (const Matrix& m, double scalar);

/* Multiply every element of a matrix by a scalar (other way)
   NB - not a member function */
Matrix operator* (double scalar, const Matrix& m);

// Overloading comparison operators

/* Comparison Operator
    NB: not a member function
 */
/* Elementwise greater than */
Matrix operator> (const Matrix& x, const Matrix& y);

/* Elementwise greater than or equal to */
Matrix operator>= (const Matrix& x, const Matrix& y);

/* Elementwise equal to */
Matrix operator== (const Matrix& x, const Matrix& y);

/* Elementwise not equal to */
Matrix operator!= (const Matrix& x, const Matrix& y);

/* Elementwise less than */
Matrix operator< (const Matrix& x, const Matrix& y);

/* Elementwise less than or equal to */
Matrix operator<= (const Matrix& x, const Matrix& y);

#endif /* Matrix_hpp */
