//
//  Matrix.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 13/10/2026.
//

#include "Matrix.hpp"
#include <algorithm>
#include <sstream>
#include <stdexcept>

// Member function
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

// Default constructor: creates a 1x1 zero matrix
Matrix::Matrix()
    : Matrix(1, 1, true) {
}

// Construct a column vector or a row vector
Matrix::Matrix(const std::vector<double>& values, bool asRow)
    : Matrix(asRow ? 1 : static_cast<int>(values.size()),
             asRow ? static_cast<int>(values.size()) : 1,
             false) {

    ASSERT(!values.empty());

    // Copy all vector elements into the matrix
    std::copy(values.begin(), values.end(), data);
}

// Construct a 1x1 matrix containing a scalar
Matrix::Matrix(double scalar)
    : Matrix(1, 1, false) {

    *data = scalar;
}

// Construct a matrix from a string
Matrix::Matrix(const std::string& contents)
    : nrows(0), ncols(0), data(nullptr), endPointer(nullptr) {

    std::vector<double> values;

    std::stringstream rowStream(contents);
    std::string rowString;

    // Reject an empty string or a trailing row delimiter
    if (contents.empty() || contents.back() == ';') {
        throw std::invalid_argument("Invalid matrix string");
    }

    // Split the string into rows
    while (std::getline(rowStream, rowString, ';')) {

        if (rowString.empty() || rowString.back() == ',') {
            throw std::invalid_argument("Invalid matrix row");
        }

        std::stringstream colStream(rowString);
        std::string elementString;

        int currentCols = 0;

        // Split each row into elements
        while (std::getline(colStream, elementString, ',')) {

            std::size_t pos = 0;
            double value = std::stod(elementString, &pos);

            // Check that no invalid characters remain
            if (elementString.find_first_not_of(" \t\n\r", pos)
                != std::string::npos) {
                throw std::invalid_argument("Invalid matrix element");
            }

            values.push_back(value);
            ++currentCols;
        }

        // Check that every row has the same number of columns
        if (nrows == 0) {
            ncols = currentCols;
        } else if (currentCols != ncols) {
            throw std::invalid_argument("Inconsistent row lengths");
        }

        ++nrows;
    }

    // Allocate memory only after successful parsing
    int size = nrows * ncols;

    data = new double[size];
    endPointer = data + size;

    // Copy the parsed values into the matrix
    std::copy(values.begin(), values.end(), data);
}


// Multiply corresponding elements of two matrices
Matrix Matrix::times(const Matrix& other) const {

    ASSERT(nRows() == other.nRows() && nCols() == other.nCols());

    Matrix ret(nRows(), nCols(), 0);

    double* dest = ret.begin();
    const double* s1 = begin();
    const double* s2 = other.begin();
    const double* finish = end();

    /*
     * Walk through both matrices in the same storage order.
     * Multiply each pair of corresponding elements and
     * store the product in ret.
     *
     * The trailing const on times() protects this matrix;
     * const Matrix& protects other. Both inputs remain unchanged.
     */
    while (s1 != finish) {
        *(dest++) = *(s1++) * *(s2++);
    }

    return ret;
}

// Top level function - not member function

// Add two matrices
Matrix operator+ (const Matrix& x, const Matrix& y) {

    ASSERT( x.nRows() == y.nRows() && x.nCols() == y.nCols() );

    Matrix ret( x.nRows(), x.nCols(), 0 );

    /*
     * These pointers let us walk through the matrices' elements.
     * This assumes the elements are stored contiguously in the same order.
     *
     * ret is non-const, so ret.begin() returns double*:
     * we can write the calculated values into its elements.
     *
     * x and y are const, so their begin() functions return const double*:
     * we can read their elements, but cannot modify them through s1 or s2.
     * The pointers themselves can still move to the next element.
     */
    double* dest = ret.begin();
    const double* s1 = x.begin();
    const double* s2 = y.begin();

    /*
     * end points ONE PAST x's last element.
     * It marks where to stop; it must never be dereferenced.
     */
    const double* end = x.end();

    while (s1 != end) {
        /*
         * *p reads or writes the element that p points to.
         * p++ advances p to the next double, using its OLD position
         * in the current expression.
         *
         * Therefore, this line:
         *   1. Reads the current elements of x and y.
         *   2. Stores their sum in the current element of ret.
         *   3. Advances all three pointers for the next iteration.
         *
         * Equivalent, more explicit code:
         *
         *     *dest = *s1 + *s2;
         *     ++dest;
         *     ++s1;
         *     ++s2;
         *
         * Only the pointers move; the matrices' elements stay in place.
         */
        *(dest++) = *(s1++) + *(s2++);
    }

    return ret;
}

// Add a scalar to every element of a matrix
Matrix operator+ (const Matrix& m, double scalar) {
    
    Matrix ret( m.nRows(), m.nCols(), 0 );
    
    double* dest = ret.begin() ;
    const double* source = m.begin() ;
    const double* end = m.end() ;
    
    while (source != end) {
        *(dest++) = *(source++) + scalar ;
    }
    
    return ret ;
    
}

// Add a scalar to every element of a matrix (other way)
Matrix operator+ (double scalar, const Matrix& m){
    
    Matrix ret (m.nRows(), m.nCols(), 0) ;
    
    double* dest = ret.begin() ;
    const double* source = m.begin() ;
    const double* end = m.end() ;
    
    while (source != end) {
        *(dest++) = *(source++) + scalar ;
    }
    
    return ret ;
    
}

// Subtract two matrices
Matrix operator- (const Matrix& x, const Matrix& y) {

    ASSERT(x.nRows() == y.nRows() && x.nCols() == y.nCols());

    Matrix ret(x.nRows(), x.nCols(), 0);

    double* dest = ret.begin();
    const double* s1 = x.begin();
    const double* s2 = y.begin();
    const double* end = x.end();

    while (s1 != end) {
        *(dest++) = *(s1++) - *(s2++);
    }

    return ret;
}


// Subtract a scalar from every element of a matrix
Matrix operator- (const Matrix& m, double scalar) {

    Matrix ret(m.nRows(), m.nCols(), 0);

    double* dest = ret.begin();
    const double* source = m.begin();
    const double* end = m.end();

    while (source != end) {
        *(dest++) = *(source++) - scalar;
    }

    return ret;
}


// Subtract every element of a matrix from a scalar
Matrix operator- (double scalar, const Matrix& m) {

    Matrix ret(m.nRows(), m.nCols(), 0);

    double* dest = ret.begin();
    const double* source = m.begin();
    const double* end = m.end();

    /*
     * Order matters for subtraction:
     * scalar - m means scalar - each element.
     */
    while (source != end) {
        *(dest++) = scalar - *(source++);
    }

    return ret;
}


// Multiply two matrices using standard matrix multiplication
Matrix operator* (const Matrix& x, const Matrix& y) {

    ASSERT(x.nCols() == y.nRows());

    Matrix ret(x.nRows(), y.nCols(), 0);

    const double* left = x.begin();
    const double* right = y.begin();
    double* dest = ret.begin();

    /*
     * Each result element is the dot product of:
     *   - row i of x;
     *   - column j of y.
     *
     * With row-by-row storage:
     *   x(i, k)   is left[i * x.nCols() + k]
     *   y(k, j)   is right[k * y.nCols() + j]
     *   ret(i, j) is dest[i * y.nCols() + j]
     *
     * p[index] is equivalent to *(p + index).
     */
    for (int i = 0; i < x.nRows(); ++i) {
        for (int j = 0; j < y.nCols(); ++j) {

            double sum = 0.0;

            for (int k = 0; k < x.nCols(); ++k) {
                sum += left[i * x.nCols() + k]
                     * right[k * y.nCols() + j];
            }

            dest[i * y.nCols() + j] = sum;
        }
    }

    return ret;
}


// Multiply every element of a matrix by a scalar
Matrix operator* (const Matrix& m, double scalar) {

    Matrix ret(m.nRows(), m.nCols(), 0);

    double* dest = ret.begin();
    const double* source = m.begin();
    const double* end = m.end();

    while (source != end) {
        *(dest++) = *(source++) * scalar;
    }

    return ret;
}


// Multiply every element of a matrix by a scalar (other way)
Matrix operator* (double scalar, const Matrix& m) {

    /*
     * Reuse the Matrix * scalar overload above.
     * Both orders produce the same result.
     */
    return m * scalar;
}

/* Elementwise greater than */
Matrix operator> (const Matrix& x, const Matrix& y) {

    ASSERT(x.nRows() == y.nRows() && x.nCols() == y.nCols());

    Matrix ret(x.nRows(), x.nCols(), 0);

    /*
     * dest points to the next result element to write.
     * s1 and s2 point to the next input elements to compare.
     * The const pointers prevent modification of the input elements.
     * end points one position beyond the last element of x.
     *
     * Each pointer advances by one element after it is dereferenced.
     * A true comparison produces 1.0; a false comparison produces 0.0.
     */
    double* dest = ret.begin();
    const double* s1 = x.begin();
    const double* s2 = y.begin();
    const double* end = x.end();

    while (s1 != end) {
        *(dest++) = (*(s1++) > *(s2++)) ? 1.0 : 0.0;
    }

    return ret;
}

/* Elementwise greater than or equal to */
Matrix operator>= (const Matrix& x, const Matrix& y) {

    ASSERT(x.nRows() == y.nRows() && x.nCols() == y.nCols());

    Matrix ret(x.nRows(), x.nCols(), 0);

    double* dest = ret.begin();
    const double* s1 = x.begin();
    const double* s2 = y.begin();
    const double* end = x.end();

    while (s1 != end) {
        *(dest++) = (*(s1++) >= *(s2++)) ? 1.0 : 0.0;
    }

    return ret;
}

/* Elementwise equal to */
Matrix operator== (const Matrix& x, const Matrix& y) {

    ASSERT(x.nRows() == y.nRows() && x.nCols() == y.nCols());

    Matrix ret(x.nRows(), x.nCols(), 0);

    double* dest = ret.begin();
    const double* s1 = x.begin();
    const double* s2 = y.begin();
    const double* end = x.end();

    while (s1 != end) {
        *(dest++) = (*(s1++) == *(s2++)) ? 1.0 : 0.0;
    }

    return ret;
}

/* Elementwise not equal to */
Matrix operator!= (const Matrix& x, const Matrix& y) {

    ASSERT(x.nRows() == y.nRows() && x.nCols() == y.nCols());

    Matrix ret(x.nRows(), x.nCols(), 0);

    double* dest = ret.begin();
    const double* s1 = x.begin();
    const double* s2 = y.begin();
    const double* end = x.end();

    while (s1 != end) {
        *(dest++) = (*(s1++) != *(s2++)) ? 1.0 : 0.0;
    }

    return ret;
}

/* Elementwise less than */
Matrix operator< (const Matrix& x, const Matrix& y) {

    ASSERT(x.nRows() == y.nRows() && x.nCols() == y.nCols());

    Matrix ret(x.nRows(), x.nCols(), 0);

    double* dest = ret.begin();
    const double* s1 = x.begin();
    const double* s2 = y.begin();
    const double* end = x.end();

    while (s1 != end) {
        *(dest++) = (*(s1++) < *(s2++)) ? 1.0 : 0.0;
    }

    return ret;
}

/* Elementwise less than or equal to */
Matrix operator<= (const Matrix& x, const Matrix& y) {

    ASSERT(x.nRows() == y.nRows() && x.nCols() == y.nCols());

    Matrix ret(x.nRows(), x.nCols(), 0);

    double* dest = ret.begin();
    const double* s1 = x.begin();
    const double* s2 = y.begin();
    const double* end = x.end();

    while (s1 != end) {
        *(dest++) = (*(s1++) <= *(s2++)) ? 1.0 : 0.0;
    }

    return ret;
}
