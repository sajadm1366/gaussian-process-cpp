#include <iostream>
#include "utils.h"

// dot product of two vectors
double dot(const alglib::real_1d_array &x, const alglib::real_1d_array &y, int size){
    double val = 0;
    for (size_t i = 0; i < size; i++)
    {
        val += x[i] * y[i];
    }
    return val;
}


//  element wise of sum of two vectors
alglib::real_1d_array  sum(const alglib::real_1d_array &x, const alglib::real_1d_array &y, int size){
    alglib::real_1d_array z;
    z.setlength(size);
    
    for (size_t i = 0; i < size; i++)
    {
        z[i] = x[i] + y[i];
    }
    return z;
    
}


// trace of a matrix
double trace(alglib::real_2d_array &A)
{	
	double tr = 0;
	for (int i=0; i< A.rows(); i++){
          tr += A(i, i);
	}
	return tr;
}


// compute the distance between two vectors
double dis_square(double *a, double *b, int K)
{
	double sum_ = 0;
	for (int i=0; i<K; i++)
	{
		double ac = *(a + i);
		double bc = *(b + i);
		sum_ += pow(ac - bc, 2);
	}
	return sum_;
}
