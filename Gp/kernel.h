#ifndef KERNELS_H
#define KERNELS_H

#include "linalg.h"


class Rbf {
public:
	alglib::real_2d_array x;
	double alfa = 1;
	double beta = 1;
	double sigma = 0;
	void cov(alglib::real_2d_array &K);
	void cross_cov(alglib::real_2d_array &xs, alglib::real_2d_array &Kc);
	void grads(alglib::real_2d_array &Gm1, alglib::real_2d_array &Gm2, alglib::real_2d_array &Gm3);
};


class Exp {
public:
	alglib::real_2d_array x;
	double alfa =0;
	double beta = 0;
	double sigma = 0;
	void cov(alglib::real_2d_array &K);
	void cross_cov(alglib::real_2d_array &xs, alglib::real_2d_array &Kc);
	void grads(alglib::real_2d_array &Gm1, alglib::real_2d_array &Gm2, alglib::real_2d_array &Gm3);
};

#endif

