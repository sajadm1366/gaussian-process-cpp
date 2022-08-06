#include <iostream>
#include "utils.h"
#include <math.h>

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





double dis_abs(double *a, double *b, int K)
{
	double sum_ = 0;
	for (int i=0; i<K; i++)
	{
		double ac = *a + i;
		double bc = *b + i;
		sum_ += abs(ac - bc);
	}
	return sum_;
}

// get daignla elmenst of matrix

// compute log det of a matrix using LU decompistion
double  log_det(const alglib::real_2d_array &X)
{
	alglib::real_2d_array U(X);
	alglib::spdmatrixcholesky(U, U.rows(), true);
	//alglib::real_1d_array x = diag(U);
	double log_sum = 0;
	for (int i=0; i<X.rows(); i++)
	{
		log_sum += log (U(i, i));
	}
	return 2*log_sum;
}


double prod_quad(const alglib::real_2d_array &A, const alglib::real_1d_array &x)
{
	alglib::real_1d_array c;
	c.setlength(x.length());
	rmatrixgemv(x.length(), x.length(), 1, A, 0, 0, 0, x, 0, 0, c, 0);
	return dot(x, c, x.length());
}


///////////////////////////////////////////////////////////
// reshape a vector to  matrix
void reshape(alglib::real_1d_array &x, alglib::real_2d_array &X, int K)
{
	int L = x.length();
	int M = L / K;
	X.setlength(M, K);
	for (int i=0; i<M; i++)
	{
		for (int j=0; j<K; j++)
		{
			X(i, j) = x[ i * K + j];
		}
	}

}
