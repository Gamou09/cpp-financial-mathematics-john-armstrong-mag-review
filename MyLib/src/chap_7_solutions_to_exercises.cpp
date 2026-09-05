//
//  chap_7_solutions_to_exercises.cpp
//  MyLib
//
//  Created by Martial Aguessi on 07/06/2025.
//

#include "stdafx.h"

using namespace std ;

// 7.7.1
int solveQuadratic_mag(double& a, double& b, double& c) {
 
    cout << "Solving for the root with " ;
    cout <<"a = " << a << ", ";
    cout <<"b = " << b << ", ";
    cout <<"c = " << c << "\n" ;
    
    int n ;
    
    // use the quadratic formula to find the number of roots
    double delta = b*b - 4*a*c ;
    
    if (delta > 0) {
        n = 2 ;
        a = ( - b - sqrt(delta) ) / (2*a);
        b = ( - b + sqrt(delta) ) / (2*a);
        c = NAN ;
    }
    else if (delta == 0 ) {
        n = 1 ;
        a = ( - b ) / (2*a);
        b = NAN ;
        c = NAN ;
    }
    else {
        n = 0 ;
        a = NAN;
        b = NAN ;
        c = NAN ;
    }
    
    cout <<"The polynom has/have " << n << " solution(s)." <<"\n";
    cout <<"Solution(s) is/are " << a << ", " << b << ", "<< c << ", " <<"\n";
    return n ;
}

int solveQuadratic(double& x1, double& x2, double& unused) {
 
    cout << "Solving the quadratic equation with: ";
    cout << "a = " << x1 << ", b = " << x2 << ", c = " << unused << "\n";

    double a = x1;
    double b = x2;
    double c = unused;

    double delta = b * b - 4 * a * c;
    int n = 0;

    if (a == 0) {
        cerr << "Not a quadratic equation (a = 0).\n";
        x1 = x2 = unused = numeric_limits<double>::quiet_NaN();
        return -1; // Signal invalid input
    }

    if (delta > 0) {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        unused = numeric_limits<double>::quiet_NaN();
        n = 2;
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        x2 = unused = numeric_limits<double>::quiet_NaN();
        n = 1;
    } else {
        x1 = x2 = unused = numeric_limits<double>::quiet_NaN();
        n = 0;
    }

    cout << "The polynomial has " << n << " real solution(s).\n";
    cout << "Solutions: " << x1 << ", " << x2 << ", " << unused << "\n\n";
    return n;
}

vector<double> solveQuadratic_vector(double a, double b, double c){
 
    cout << "Solving for the root with " ;
    cout <<"a = " << a << ", ";
    cout <<"b = " << b << ", ";
    cout <<"c = " << c << "\n" ;
    
    vector<double> res ;
    
    // use the quadratic formula to find the number of roots
    double delta = b*b - 4*a*c ;
    
    if (delta > 0) {
        res.push_back( (- b - sqrt(delta) ) / (2*a));
        res.push_back( (- b + sqrt(delta) ) / (2*a) );
    }
    else if (delta == 0 ) {
        res.push_back( (- b ) / (2*a) );

    }
    else {
        // No real roos,

    }
    
    cout << "The polynomial has " << res.size() << " real solution(s)." << "\n";
    
    for (size_t i = 0; i < res.size(); ++i) {
        cout << "Solution " << i + 1 << ": " << res[i] << "\n";
    }
    
    cout << "\n" ;

    return res;
}

void testSolveQuadratic_vector() {
    auto r1 = solveQuadratic_vector(1, -3, 2);
    assert(r1.size() == 2);
    assert(abs(r1[0] - 1.0) < 1e-6 || abs(r1[1] - 1.0) < 1e-6);

    auto r2 = solveQuadratic_vector(1, 2, 1);
    assert(r2.size() == 1);
    assert(abs(r2[0] + 1.0) < 1e-6);

    auto r3 = solveQuadratic_vector(1, 1, 1);
    assert(r3.empty());
}

void testSolveQuadratic() {
    
    double a, b, c;

    // Case 1: Two real roots
    a = 1; b = -3; c = 2;
    int n1 = solveQuadratic(a, b, c);
    assert(n1 == 2);
    assert(abs(a - 1.0) < 1e-6 || abs(a - 2.0) < 1e-6);
    assert(abs(b - 1.0) < 1e-6 || abs(b - 2.0) < 1e-6);

    // Case 2: One real root
    a = 1; b = 2; c = 1;
    int n2 = solveQuadratic(a, b, c);
    assert(n2 == 1);
    assert(abs(a + 1.0) < 1e-6);

    // Case 3: No real roots
    a = 1; b = 1; c = 1;
    int n3 = solveQuadratic(a, b, c);
    assert(n3 == 0);
    assert(isnan(a) && isnan(b) && isnan(c));

    // Case 4: Not a quadratic
    a = 0; b = 2; c = 3;
    int n4 = solveQuadratic(a, b, c);
    assert(n4 == -1);
    assert(isnan(a) && isnan(b) && isnan(c));
    
}


// 7.7.2

double mean_function( vector<double> nums){
    
    double total = 0.0 ;
    
    int numsLength = (int) nums.size() ;
    
    for ( int i = 0; i < numsLength; i ++) {
        total += nums[i] ;
    }
    
    return total / numsLength ; ;
}

void testMean (){
    
    // Test with known values positive double
    vector<double> nums1 = {1.0, 2.0, 3.0} ;
    double average1 = mean_function(nums1) ;
    assert( average1 == 2) ;
    
    // Test with known values - mixed positive negative
    vector<double> nums2 = {1.0, 2.0, -3.0, 5.0, 10.0} ;
    double average2 = mean_function(nums2) ;
    assert( average2 == 3) ;
    
    // Test with unique value
    vector<double> nums3 = {1.0} ;
    double average3 = mean_function(nums3) ;
    assert( average3 == 1.0) ;
}

double mean_function_v2(const vector<double>& nums) {
    if (nums.empty()) {
        throw invalid_argument("Empty vector passed to mean_function");
    }
    double total = accumulate(nums.begin(), nums.end(), 0.0); // std::accumulate from <numeric>
    return total / nums.size();
}

void testMean_v2() {
    
    // not needed as we already define an ASSERT_APPROX_EQUAL macro
    auto approxEqual = [](double a, double b, double eps = 1e-9) {
        return std::abs(a - b) < eps;
    };

    // test with different know values
    ASSERT_APPROX_EQUAL(mean_function_v2({1.0, 2.0, 3.0}), 2.0,1e-9);
    ASSERT_APPROX_EQUAL(mean_function_v2({1.0, 2.0, -3.0, 5.0, 10.0}), 3.0,1e-9);
    ASSERT_APPROX_EQUAL(mean_function_v2({1.0}), 1.0,1e-9);
    
    // Edge case: very large values
    assert(approxEqual(mean_function_v2({1e9, 1e9, 1e9}), 1e9));

    // Edge case: throws on empty input
    try {
        mean_function_v2({});
        assert(false); // Should not reach here
    } catch (const std::invalid_argument&) {
        assert(true);
    }
}

// 7.7.3

double standardDeviation(const vector<double> nums, bool sample_std = true){
    
    double res ;
    
    // compute the mean of the vector
    double mean_nums = mean_function_v2(nums) ;
    
    // loop to compute the square differences
    int nums_lengths = (int) nums.size() ;
    double square_diff = 0.0 ;
    
    for (int i = 0; i < nums_lengths; i++) {
        square_diff += (nums[i] - mean_nums)*(nums[i] - mean_nums) ;
    }
    
    // decision if sample std or population std
    if (sample_std) {
        res = sqrt( square_diff / (nums_lengths - 1) );
    } else {
        res = sqrt ( square_diff / nums_lengths ) ;
    }
    
    return res ;
}

void testStandardDeviation(){
    
    vector<double> data1 = {1, 2, 3, 4, 5};
    ASSERT_APPROX_EQUAL(standardDeviation(data1, false), 1.414213562, 1e-9);  // population
    ASSERT_APPROX_EQUAL(standardDeviation(data1, true), 1.58113883, 1e-9);  // sample
        
    vector<double> data2 = {5, 5, 5, 5};
    ASSERT_APPROX_EQUAL(standardDeviation(data2, true), 0, 1e-9);
}

// 7.7.4

double min_max(const vector<double>& nums, bool is_min = true){
    
    // check if empty
    if (nums.empty()) {
        throw invalid_argument("Empty vector passed to min_max");
    }
    
    // brute force
    double res = nums[0] ;
    
    if (is_min) {
        for (auto x : nums) {
            if ( x < res ) res = x ;
        }
    } else {
        for (auto x : nums) {
            if ( x > res ) res = x ;
        }
    }
    
    return res ;
    
}

void test_min_max(){
    
    // test all positive
    vector<double> data1 = {1, 2, 3, 4, 5};
    assert( 1 == min_max(data1)) ;
    assert( 5 == min_max(data1, false)) ;
    
    // test mix positive and negative
    vector<double> data2 = {1, 2, -3, 4, 5};
    assert( -3 == min_max(data2)) ;
    assert( 5 == min_max(data2, false)) ;
    
    // test all negative
    vector<double> data3 = {-1, -2, -3, -4, -5};
    assert( -5 == min_max(data3)) ;
    assert( -1 == min_max(data3, false)) ;
    
    // test one element
    vector<double> data4 = {1};
    assert( 1 == min_max(data4)) ;
    assert( 1 == min_max(data4, false)) ;
    
}

// helper function to create a vector
vector<double> make_vector(initializer_list<double> values) {
    return vector<double>(values);
}

vector<string> make_vector(std::initializer_list<string> values){
    return vector<string>(values);
}


void test_make_vector() {
    vector<double> vec1 = make_vector({1.0, 2.5, 3.3});
    assert(vec1.size() == 3);
    assert(vec1[0] == 1.0);
    assert(vec1[1] == 2.5);
    assert(vec1[2] == 3.3);

//    std::vector<double> vec2 = make_vector({});
//    assert(vec2.size() == 0);

    std::vector<double> vec3 = make_vector({-5.0});
    assert(vec3.size() == 1);
    assert(vec3[0] == -5.0);
}

// 7.7.5

vector<double> randuniformOld(const int n = 1){

    // using rand() from <cstdlib> --> https://cplusplus.com/reference/cstdlib/rand/
    vector<double> res ;
    
    // loop to generate the n number
    for (int i = 0; i < n ; i++) {
        res.push_back( (1.0*rand()) / RAND_MAX) ;
    }
    
    return res;
    
}



void test_randomuniform(){
    
    vector<double> nums = randuniformOld(10) ;
    
    // check that all values are within 0 and 1
    for (auto x : nums) {
        assert( x >= 0 && x <=  1) ;
    }
    
}

static mt19937 mersenneTwister ;

vector<double> randuniform (int n){
    vector<double> ret(n, 0.0) ;
    for (int i=0; i < n; i++) {
        ret[i] = (mersenneTwister() + 0.5)/(mersenneTwister.max() + 1.0) ;
    }
    
    return ret ;
}


// Use C++11 <random> engine and distribution
vector<double> randuniform_v2(const int n = 1) {
    
    vector<double> res;
    // Without reserve(n), the vector may reallocate memory multiple times as it grows.
    // With reserve(n), memory is allocated once, improving performance and efficiency
    // especially for large n.
    res.reserve(n);
    
    // Random number generator and distribution
    random_device rd;  // Seed
    mt19937 gen(rd()); // Mersenne Twister engine
    // mt19937 gen(42); // Replaces random_device with fixed seed
    uniform_real_distribution<> dis(0.0, 1.0); // Range [0.0, 1.0)

    for (int i = 0; i < n; ++i) {
        res.push_back(dis(gen));
    }

    return res;
}

// Test function
void test_randomuniform_v2() {
    vector<double> nums = randuniform(10);

    for (auto x : nums) {
        assert(x >= 0.0 && x <= 1.0);  // Now correct
    }

}

// 7.7.6
vector<double> randn(const int n = 1) {
    
    vector<double> res;
    // Without reserve(n), the vector may reallocate memory multiple times as it grows.
    // With reserve(n), memory is allocated once, improving performance and efficiency
    // especially for large n.
    res.reserve(n);
    
    // Random number generator and distribution
    random_device rd;  // Seed
    mt19937 gen(rd()); // Mersenne Twister engine
    // mt19937 gen(42); // Replaces random_device with fixed seed
    
    normal_distribution <> generator{0, 1.0}; // mean 0 and std 1

    for (int i = 0; i < n; ++i) {
        res.push_back(generator(gen));
    }

    return res;
}

void test_randn() {
    
    vector<double> nums1 = randn(10000) ;
    
    // test mean
    ASSERT_APPROX_EQUAL( mean_function_v2(nums1), 0.0, 1e-1) ;
    
    // test std
    ASSERT_APPROX_EQUAL( standardDeviation(nums1), 1.0, 1e-1) ;
    
    // test of the size
    ASSERT(nums1.size() == 10000);
    
    // test variability
    vector<double> nums2 = randn(100);
    vector<double> nums3 = randn(100);
    bool are_different = false;
    for (int i = 0; i < 100; ++i) {
        if (nums2[i] != nums3[i]) {
            are_different = true;
            break;
        }
    }
    ASSERT(are_different); // Almost surely true
    
}

// 7.7.7

vector<double> rand_box_muller_algo(const int n = 1){
    
    vector<double> res;
    res.reserve(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < n; i += 1) {
        
        // first generate the two uniformly distributed random variable u1 and u2
        double u1 = dist(gen);
        double u2 = dist(gen);

        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * PI * u2);
//        double z1 = sqrt(-2.0 * log(u2)) * sin(2.0 * PI * u2);
        
        res.push_back(z0);
        
//        if (i + 1 < n) res.push_back(z1); // Only push second if within range
    }

    return res;
}

void test_rand_box_muller_all(int n = 100000) {
    cout << "Running unified test for rand_box_muller_algo with n = " << n << "...\n";

    vector<double> samples = rand_box_muller_algo(n);

    // 1. Functional checks
    // check size and if real number
    assert(samples.size() == n);
    for (double z : samples) {
        assert(isfinite(z));
    }

    // 2. Statistical test (mean ≈ 0, variance ≈ 1)
    ASSERT_APPROX_EQUAL( mean_function_v2(samples), 0.0, 1e-1) ;
    ASSERT_APPROX_EQUAL( standardDeviation(samples), 1.0, 1e-1) ;

    // 3. Histogram (simple ASCII)
    // will comment the visual test for now
//    const int bins = 20;
//    const double min_val = -4.0, max_val = 4.0;
//    vector<int> hist(bins, 0);
//
//    for (double x : samples) {
//        if (x < min_val || x >= max_val) continue;
//        int index = int((x - min_val) / (max_val - min_val) * bins);
//        hist[index]++;
//    }
//
//    cout << "\nASCII Histogram (range -4 to 4):\n";
//    for (double i = 0; i < bins; ++i) {
//        double bin_start = min_val + i * (max_val - min_val) / bins;
//        cout << "[" << (bin_start < 0 ? "" : " ") << bin_start << "] ";
//        cout << string(hist[i] / 200, '*') << '\n';
//    }

}

void testChap7_solutions(){
    
    TEST(testSolveQuadratic) ;
    TEST(testSolveQuadratic_vector) ;
    TEST(testMean) ;
    TEST(testMean_v2) ;
    TEST(testStandardDeviation) ;
    TEST(test_min_max) ;
    TEST(test_make_vector) ;
    TEST(test_randomuniform) ;
    TEST(test_randomuniform_v2) ;
    TEST(test_randn ) ;
    TEST(test_rand_box_muller_all) ;
    

}



