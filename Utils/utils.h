#ifndef UTILS_H
#define UTILS_H


#include <iostream>
#include "linalg.h"

double dot(const alglib::real_1d_array &x, const alglib::real_1d_array &y, int size);
alglib::real_1d_array sum(const alglib::real_1d_array &x, const alglib::real_1d_array &y, int size);


double trace(alglib::real_2d_array &A);

double dis_square(double *a, double *b, int K);

double dis_abs(double *a, double *b, int K);

double log_det(const alglib::real_2d_array &x);

double prod_quad(const alglib::real_2d_array &A, alglib::real_1d_array &x);

void reshape(alglib::real_1d_array &x, alglib::real_2d_array &X, int K);
#endif
