#ifndef UTILS_H
#define UTILS_H


#include <iostream>
#include "linalg.h"

double dot(const alglib::real_1d_array &x, const alglib::real_1d_array &y, int size);
alglib::real_1d_array sum(const alglib::real_1d_array &x, const alglib::real_1d_array &y, int size);


double trace(alglib::real_2d_array &A);

double dis_square(double *a, double *b, int K);
#endif
