#ifndef GPMODEL_H
#define GPMODLE_H

#include "kernel.h"


class GP_model {
private:
	int  N;
	Rbf rbf;
public:
	GP_model(double a, Rbf &rbf);
	void fit(const alglib::real_2d_array &x, const alglib::real_1d_array &y);
	alglib::real_1d_array gen_data(const alglib::real_2d_array &x);
	void predict();
	double loglikelihood(const alglib::real_1d_array &y, alglib::real_2d_array &K, alglib::real_2d_array &inv_K);
	void grad_loglikelihood(const alglib::real_1d_array &y, alglib::real_2d_array &K, alglib::real_2d_array &inv_K, alglib::real_1d_array &grad);


};


#endif
