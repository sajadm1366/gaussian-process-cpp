#include "linalg.h"
#include "func.h"
#include <iostream>
#include <stdio.h>
#include "utils.h"
// #include "stdafx.h"



Func::Func(){
     // define function fixed parameters
      A = "[[1, 0], [0, 1]]";
      b = "[1, 1]";
      N = 2;
      c = 2;
}

double Func::eval(const alglib::real_1d_array &x){

    alglib::real_1d_array y = "[0, 0]";
    alglib::rmatrixgemv(N, N, 1, A, 0, 0, 0, x, 0, 0, y, 0); // y = A*x
   // printf("%s\n", y.tostring(2).c_str());

    double t = dot(x, y, N) + dot(x, b, N) + c;  // t = x.y + x'b + c , t= x'Ax + x'b + c

    return t;
}

alglib::real_1d_array Func::grad(const alglib::real_1d_array &x){

    alglib::real_1d_array y = "[0, 0]";
    alglib::rmatrixgemv(N, N, 1, A, 0, 0, 0, b, 0, 0, y, 0);
    return sum(y, b , N);
}

alglib::real_2d_array Func::Hess(const alglib::real_1d_array &x){

    return  A;
}
