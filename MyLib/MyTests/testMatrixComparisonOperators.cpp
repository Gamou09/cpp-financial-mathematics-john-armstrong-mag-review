//
//  testMatrixComparisonOperators.cpp
//  MyTests
//
//  Created by Martial Aguessi on 25/10/2026.
//

#include "Matrix.hpp"
#include "matlib.h"
#include <iostream>


static void testGreaterThanOperator() {

    // Define matrices containing smaller, equal and greater elements
    Matrix x("1,2,3;-2,0,-1");
    Matrix y("2,2,1;-1,0,-2");

    // Compare matrices element by element
    Matrix result = (x > y);

    // Check dimensions
    ASSERT(result.nRows() == 2);
    ASSERT(result.nCols() == 3);

    // Check first row
    ASSERT_APPROX_EQUAL(result.begin()[0], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[1], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[2], 1.0, 1e-12);

    // Check second row
    ASSERT_APPROX_EQUAL(result.begin()[3], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[4], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[5], 1.0, 1e-12);

}


static void testGreaterThanOrEqualOperator() {

    // Define matrices
    Matrix x("1,2,3;-2,0,-1");
    Matrix y("2,2,1;-1,0,-2");

    // Compare matrices element by element
    Matrix result = (x >= y);

    // Check dimensions
    ASSERT(result.nRows() == 2);
    ASSERT(result.nCols() == 3);

    // Check first row
    ASSERT_APPROX_EQUAL(result.begin()[0], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[1], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[2], 1.0, 1e-12);

    // Check second row
    ASSERT_APPROX_EQUAL(result.begin()[3], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[4], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[5], 1.0, 1e-12);

}


static void testEqualOperator() {

    // Define matrices
    Matrix x("1,2,3;-2,0,-1");
    Matrix y("2,2,1;-1,0,-2");

    // Compare matrices element by element
    Matrix result = (x == y);

    // Check dimensions
    ASSERT(result.nRows() == 2);
    ASSERT(result.nCols() == 3);

    // Check first row
    ASSERT_APPROX_EQUAL(result.begin()[0], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[1], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[2], 0.0, 1e-12);

    // Check second row
    ASSERT_APPROX_EQUAL(result.begin()[3], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[4], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[5], 0.0, 1e-12);

}


static void testNotEqualOperator() {

    // Define matrices
    Matrix x("1,2,3;-2,0,-1");
    Matrix y("2,2,1;-1,0,-2");

    // Compare matrices element by element
    Matrix result = (x != y);

    // Check dimensions
    ASSERT(result.nRows() == 2);
    ASSERT(result.nCols() == 3);

    // Check first row
    ASSERT_APPROX_EQUAL(result.begin()[0], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[1], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[2], 1.0, 1e-12);

    // Check second row
    ASSERT_APPROX_EQUAL(result.begin()[3], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[4], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[5], 1.0, 1e-12);

}


static void testLessThanOperator() {

    // Define matrices
    Matrix x("1,2,3;-2,0,-1");
    Matrix y("2,2,1;-1,0,-2");

    // Compare matrices element by element
    Matrix result = (x < y);

    // Check dimensions
    ASSERT(result.nRows() == 2);
    ASSERT(result.nCols() == 3);

    // Check first row
    ASSERT_APPROX_EQUAL(result.begin()[0], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[1], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[2], 0.0, 1e-12);

    // Check second row
    ASSERT_APPROX_EQUAL(result.begin()[3], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[4], 0.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[5], 0.0, 1e-12);

}


static void testLessThanOrEqualOperator() {

    // Define matrices
    Matrix x("1,2,3;-2,0,-1");
    Matrix y("2,2,1;-1,0,-2");

    // Compare matrices element by element
    Matrix result = (x <= y);

    // Check dimensions
    ASSERT(result.nRows() == 2);
    ASSERT(result.nCols() == 3);

    // Check first row
    ASSERT_APPROX_EQUAL(result.begin()[0], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[1], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[2], 0.0, 1e-12);

    // Check second row
    ASSERT_APPROX_EQUAL(result.begin()[3], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[4], 1.0, 1e-12);
    ASSERT_APPROX_EQUAL(result.begin()[5], 0.0, 1e-12);

}


void testMatrixComparisonOperators() {

    std::cout << "\n.... Start of testMatrixComparisonOperators ....\n"
              << std::endl;

    TEST( testGreaterThanOperator );

    TEST( testGreaterThanOrEqualOperator );

    TEST( testEqualOperator );

    TEST( testNotEqualOperator );

    TEST( testLessThanOperator );

    TEST( testLessThanOrEqualOperator );

    std::cout << "\n ......................................... \n"
              << std::endl;
}
