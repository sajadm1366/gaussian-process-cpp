#ifndef FUNC_H
#define FUNC_H

#include "linalg.h"
#include <iostream>

class Func
{

private:
     alglib::real_2d_array A;
     alglib::real_1d_array b;
     double c;
     int N;

public:
     Func();
     double eval(const alglib::real_1d_array &x);
     alglib::real_1d_array grad(const alglib::real_1d_array &x);
     alglib::real_2d_array Hess(const alglib::real_1d_array &x);

};

#endif
