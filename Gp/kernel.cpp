#include "kernel.h"
#include <math.h>
#include "utils.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// RBF kernel

// RBF cov matrix
void Rbf::cov(alglib::real_2d_array &K){
	double *xptr = x[0];
	for (int i=0; i<K.rows(); i++)
	{
	    for (int j=0; j<K.rows(); j++)
	    {

            double dis = dis_square( xptr + i*x.cols() * 8, xptr + j*x.cols() * 8, x.cols());
	     //double dis = pow( x(i, 0)- x(j, 0), 2);
	   

		if (i == j){
			K(i, j) = exp(alfa) * exp(-exp(beta) * dis ) + exp(sigma);
			//K(i, j) = dis;
		}
		else
		{
			K(i, j) = exp(alfa) * exp(-exp(beta) * dis );
			//K(i, j) = dis;
		}

	    }
	}
}

// compute the gradient matrix of RBF kernel
void Rbf::grads(alglib::real_2d_array &Gm1, alglib::real_2d_array &Gm2, alglib::real_2d_array &Gm3) {
	double *xptr = x[0];
	for (int i=0; i<x.rows(); i++)
	{
	    for (int j=0; j<x.rows(); j++)
	    {
	       double dis = dis_square( xptr + i*x.cols()*8, xptr + j*x.cols()*8, x.cols());
	       double dis_test = pow( x(i, 0)- x(j, 0), 2);
		if (dis != dis_test) {
			cout << "someyhing is wrong here";
		}
		Gm1(i, j) = exp(alfa) * exp(-exp(beta) * dis );

	        Gm2(i, j) = -exp(alfa) * exp(beta) *  dis * exp(-exp(beta) * dis );

		if (i ==j) Gm3(i, j) = exp(sigma);
		if (i != j) Gm3(i, j) = 0;

	    }
	}
}


// cross kernel
void Rbf::cross_cov(alglib::real_2d_array &xs, alglib::real_2d_array &Kc){
	double *xptr = x[0];
	double *xsptr = xs[0];

	//std::cout << Kc.rows() << Kc.cols() << std::endl;
	for (int i=0; i<xs.rows(); i++)
	{
	    for (int j=0; j<x.rows(); j++)
	    {


             double dis = dis_square( xsptr + i*x.cols()* 8, xptr + j*x.cols()* 8, x.cols());
	     //double dis = pow(x(i, 0) - xs(j, 0), 2);
	     Kc(i, j) = exp(alfa) * exp(-exp(beta) * dis );
		   // std::cout << i << std::endl;
	     //Kc(i, j) = 1;

	    }

//	std::cout << "here"<< std::endl;
//	printf("%s\n", xs.tostring(2).c_str());
//	std::cout << "here"<< std::endl;

	}

}


//////////////////////////////////////////////////////////////////////////////
// Exponetail kernel 

// Exponetail covariance matrix
void Exp::cov(alglib::real_2d_array &K){
	double *xptr = x[0];
	for (int i=0; i<K.rows(); i++)
	{
	    for (int j=0; j<K.rows(); j++)
	    {

             double dis = dis_abs( xptr + i*x.cols(), xptr + j*x.cols(), x.cols());

		if (i == j){
			K(i, j) = exp(alfa) * exp(-exp(beta) * dis ) + exp(sigma);
		}
		else
		{
			K(i, j) = exp(alfa) * exp(-exp(beta) * dis );
		}

	    }
	}
}


// gradient matrix of exponetail kernel
void Exp:: grads(alglib::real_2d_array &Gm1, alglib::real_2d_array &Gm2, alglib::real_2d_array &Gm3)
 {
	double *xptr = x[0];
	for (int i=0; i<x.rows(); i++)
	{
	    for (int j=0; j<x.rows(); j++)
	    {
	        double dis = dis_abs( xptr + i*x.cols(), xptr + j*x.cols(), x.cols());

		Gm1(i, j) = exp(alfa) * exp(-exp(beta) * dis );
	        Gm2(i, j) = -exp(alfa) * exp(beta) *  dis * exp(-exp(beta) * dis );
		if (i == j) Gm3(i, j) = exp(sigma);
		if (i != j) Gm3(i , j) = 0;
	    }
	}
}

// cross kernel
void Exp::cross_cov(alglib::real_2d_array &xs, alglib::real_2d_array &Kc)
{
	double *xptr = x[0];
	double *xsptr = xs[0];
	for (int i=0; i<xs.rows(); i++)
	{
	    for (int j=0; j<x.rows(); j++)
	    {

             double dis = dis_square( xsptr + i*x.cols(), xptr + j*x.cols(), x.cols());

		if (i == j){
			Kc(i, j) = exp(alfa) * exp(-exp(beta) * dis ) ;
		}
		else
		{
			Kc(i, j) = exp(alfa) * exp(-exp(beta) * dis );
		}

	    }
	}
}




