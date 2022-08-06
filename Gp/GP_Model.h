#ifndef GPMODEL_H
#define GPMODLE_H

#include "kernel.h"
#include <string>

template <typename T>
class Model {
private:
	int  N;
	T  kernel;

public:
	Model(int N, T &kernel);

	void fit(const alglib::real_2d_array &x, const alglib::real_1d_array &y);

	alglib::real_1d_array gen_data(const alglib::real_2d_array &x);

	void predict(alglib::real_2d_array &xnew, alglib::real_1d_array &y_new, const alglib::real_2d_array &x, const alglib::real_1d_array &y);

	double loglikelihood(const alglib::real_1d_array &y,const alglib::real_2d_array &K,const alglib::real_2d_array &inv_K);

	void grad_loglikelihood(const alglib::real_1d_array &y, alglib::real_2d_array &K, alglib::real_2d_array &inv_K, alglib::real_1d_array &grad);

	T getKernel();
};


#endif

