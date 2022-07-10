#include "kernel.h"
#include <math.h>
#include "utils.h"

using namespace std;

//Rbf::Rbf(alglib::real_1d_array &x, double alfa, double beta){
//	this->x = x;
//	this->alfa = alfa;
//	this->beta = beta;
//	
//
//}


void Rbf::kernel(alglib::real_2d_array &K){
	double *xptr = x[0];
	for (int i=0; i<K.rows(); i++)
	{
	    for (int j=0; j<K.rows(); j++)
	    {

             double dis = dis_square( xptr + i*x.cols(), xptr + j*x.cols(), x.cols());

		if (i == j){
			K(i, j) = exp(alfa) * exp(-exp(beta) * dis ) + .0001;
		}
		else
		{
			K(i, j) = exp(alfa) * exp(-exp(beta) * dis );
		}

	    }
	}
}


void Rbf:: grads(alglib::real_2d_array &Gm1, alglib::real_2d_array &Gm2) {
	double *xptr = x[0];
	for (int i=0; i<x.rows(); i++)
	{
	    for (int j=0; j<x.rows(); j++)
	    {
	        double dis = dis_square( xptr + i*x.cols(), xptr + j*x.cols(), x.cols());

		Gm1(i, j) = exp(alfa) * exp(-exp(beta) * dis );
	        Gm2(i, j) = -exp(alfa) * exp(beta) *  dis * exp(-exp(beta) * dis );
	    }
	}
}


