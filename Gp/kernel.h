#ifndef KERNELS_H
#define KERNELS_H

#include "linalg.h"

//typedef alglib::real_2d_array mat;
//typedef alglib::real_1d_array vec;

class Rbf {
public:
	alglib::real_2d_array x;
	double alfa =0;
	double beta = 0;
	//alglib::real_2d_array K;
	//alglib::real_2d_array grad_alfa;
	//alglib::real_2d_array grad_beta;
//	Rbf(alglib::real_1d_array &x, double alfa, double beta);
	void kernel(alglib::real_2d_array &K);
	
	void grads(alglib::real_2d_array &Gm1, alglib::real_2d_array &Gm2);
	//alglib::real_2d_array grad_beta();
	//mat grad();
};


#endif

