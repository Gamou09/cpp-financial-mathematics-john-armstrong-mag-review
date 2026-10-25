//
//  testMatrixConstructors.cpp
//  MyTests
//
//  Created by Martial Aguessi on 25/10/2026.
//

#include "Matrix.hpp"
#include "matlib.h"
#include <iostream>
#include <vector>


static void testDefaultConstructor() {

    // Define a matrix using the default constructor
    Matrix m;

    // Check dimensions
    ASSERT(m.nRows() == 1);
    ASSERT(m.nCols() == 1);

    // Check that the unique element is zero
    ASSERT_APPROX_EQUAL(*m.begin(), 0.0, 1e-12);

}


static void testVectorConstructor() {

    // Define a vector
    std::vector<double> values = {1.0, 2.0, 3.0};

    // Construct a column vector
    Matrix m1(values);

    // Check dimensions
    ASSERT(m1.nRows() == 3);
    ASSERT(m1.nCols() == 1);

    // Check elements
    ASSERT_APPROX_EQUAL(m1.begin()[0], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(m1.begin()[1], 2.0, 1e-12);
    ASSERT_APPROX_EQUAL(m1.begin()[2], 3.0, 1e-12);

    // Construct a row vector
    Matrix m2(values, true);

    // Check dimensions
    ASSERT(m2.nRows() == 1);
    ASSERT(m2.nCols() == 3);

    // Check elements
    ASSERT_APPROX_EQUAL(m2.begin()[0], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(m2.begin()[1], 2.0, 1e-12);
    ASSERT_APPROX_EQUAL(m2.begin()[2], 3.0, 1e-12);

}


static void testScalarConstructor() {

    // Construct a matrix from a scalar
    Matrix m(5.0);

    // Check dimensions
    ASSERT(m.nRows() == 1);
    ASSERT(m.nCols() == 1);

    // Check element
    ASSERT_APPROX_EQUAL(*m.begin(), 5.0, 1e-12);

}


static void testStringConstructor() {

    // Construct a matrix from a string
    Matrix m("1,2,3;4,5,6");

    // Check dimensions
    ASSERT(m.nRows() == 2);
    ASSERT(m.nCols() == 3);

    // Check first row
    ASSERT_APPROX_EQUAL(m.begin()[0], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(m.begin()[1], 2.0, 1e-12);
    ASSERT_APPROX_EQUAL(m.begin()[2], 3.0, 1e-12);

    // Check second row
    ASSERT_APPROX_EQUAL(m.begin()[3], 4.0, 1e-12);
    ASSERT_APPROX_EQUAL(m.begin()[4], 5.0, 1e-12);
    ASSERT_APPROX_EQUAL(m.begin()[5], 6.0, 1e-12);

}


void testMatrixConstructors() {

    std::cout << "\n.... Start of testMatrixConstructors ....\n"
              << std::endl;

    TEST( testDefaultConstructor );

    TEST( testVectorConstructor );

    TEST( testScalarConstructor );

    TEST( testStringConstructor );

    std::cout << "\n ......................................... \n"
              << std::endl;
}
