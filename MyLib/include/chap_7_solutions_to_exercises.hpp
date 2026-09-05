//
//  chap_7_solutions_to_exercises.hpp
//  MyLib
//
//  Created by Martial Aguessi on 07/06/2025.
//

#ifndef chap_7_solutions_to_exercises_hpp
#define chap_7_solutions_to_exercises_hpp

#include "stdafx.h"

void testChap7_solutions() ;

// 7.7.1

int solveQuadratic_mag(double& a, double& b, double& c) ;

int solveQuadratic(double& x1, double& x2, double& unused) ; 

int solveQuadratic(double& a, double& b, double& c);

std::vector<double> solveQuadratic_vector(double a, double b, double c);

// 7.7.2

double mean_function(std::vector<double> nums) ;

double mean_function_v2(const std::vector<double>& nums) ;

// 7.7.3

double standardDeviation(const std::vector<double> nums, bool sample_std) ;

// 7.7.4

double min_max(const std::vector<double>& nums, bool is_min) ;

// helper function

std::vector<double> make_vector(std::initializer_list<double> values) ;

std::vector<std::string> make_vector(std::initializer_list<std::string> values) ;

// 7.7.5

std::vector<double> randuniformOld(const int n) ;

// 7.7.6

std::vector<double> randn(const int n) ;

// 7.7.7

std::vector<double> rand_box_muller_algo(const int n) ; 

#endif /* chap_7_solutions_to_exercises_hpp */
