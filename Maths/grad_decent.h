#ifndef GRAD_H
#define GRAD_H

#include "linalg.h"

class Grad_decent
{
private:
   float  lr; // learning rate
   int iterations; // number of iterations

public:
   Grad_decent(float lr, int iterations);
   void   step(alglib::real_1d_array &x, const alglib::real_1d_array &grad);

};



#endif
