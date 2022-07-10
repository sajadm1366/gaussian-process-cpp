#include "GP_Model.h"
#include "math.h"
#include "utils.h"
#include <random>


using namespace alglib;

GP_model::GP_model(double N, Rbf &rbf){	
   	this->N = N;
	this->rbf = rbf;
}

real_1d_array GP_model::gen_data(const real_2d_array &x)
{
	// compute covaraince matrix
	rbf.x = x;

	real_2d_array K;
	K.setlength(N, N);
	rbf.kernel(K);
	
	real_2d_array U(K);
	spdmatrixcholesky(U, N, true);
	

	std::default_random_engine generator;
	std::normal_distribution<double> distribution(0.0, 1.0);
	double z_[N];
	for (int i=0; i<N; i++)
	{
		z_[i] = distribution(generator);
	}

	real_1d_array z;
	z.setcontent(N,z_);
	
	real_1d_array y;
	y.setlength(N);
	rmatrixgemv(N, N, 1, U, 0, 0, 0, z, 0,0, y, 0);
	return y;
}


void GP_model::fit(const real_2d_array &x, const  real_1d_array &y){

	// compute covaraince matrix
	real_2d_array K;
	K.setlength(N, N);
	//Rbf rbf(x, 1, 1); // init Rbf kernel
	rbf.x = x;
	rbf.alfa = 1;
	rbf.beta = 1;
	rbf.kernel(K); //  cov matrix
	printf("%s\n", K.tostring(2).c_str());

	// compute inverse of covarince matrix
	real_2d_array inv_K(K);
   	//printf("%s\n", inv_K.tostring(2).c_str());
	ae_int_t info;
        matinvreport rep;
        rmatrixinverse(inv_K, info, rep);

	double l = loglikelihood(y, K, inv_K);

        std::cout << l <<std::endl;

	// preallocate grad
	real_1d_array grad("[0, 0]");
	//grad.setlength(2);
	//printf("%s\n", grad.tostring(2).c_str());
	grad_loglikelihood(y, K, inv_K, grad);
	std::cout << "grad"<< std::endl;
	//printf("%s\n", grad.tostring(2).c_str());


	for (int i=0; i<100000; i++)
	{
		// get grads
		grad_loglikelihood(y, K, inv_K, grad);

		// update parameters
		rbf.alfa +=   .0001*grad[0];
		rbf.beta += .0001*grad[1];

		// update kernel and its inverse
		rbf.kernel(K);
		inv_K = K;
		rmatrixinverse(inv_K, info, rep);
		
		double sum_grad = grad[0] + grad[1];
		//printf("%s\n", grad.tostring(2).c_str());
		//std::cout << rbf.alfa << std::endl;	
		double l = loglikelihood(y, K, inv_K);
		std::cout << "loglike:"<< l <<" ,sum_grad:"<< sum_grad<< std::endl;
	
	}


}

double GP_model::loglikelihood(const real_1d_array &y, real_2d_array &K, real_2d_array &inv_K) {


	real_1d_array c;
	c.setlength(N);
	rmatrixgemv(N, N, 1, inv_K, 0, 0, 0, y, 0,0, c, 0);
	double term1 = -.5 * dot(y, c, N);
	double term2 = -.5 * std::log(rmatrixdet(K));
 
	return term1 + term2;

}


void GP_model::grad_loglikelihood(const real_1d_array &y, real_2d_array &K, real_2d_array &inv_K, real_1d_array &grad)
{
	//printf("test0\n");
	real_1d_array alfa;
	alfa.setlength(N);
	rmatrixgemv(N, N, 1, inv_K, 0, 0, 0, y, 0,0, alfa, 0);
	//printf("%s\n", inv_K.tostring(2).c_str());
	real_2d_array Gm1, Gm2;
	Gm1.setlength(N, N);
	Gm2.setlength(N, N);
	rbf.grads(Gm1, Gm2);

	real_2d_array Alfa(inv_K);
	rmatrixger(N, N, Alfa, 0, 0, -1, alfa, 0, alfa, 0);
	
	real_2d_array C;
	C.setlength(N, N);
	rmatrixgemm(N, N, N, 1, Alfa, 0, 0, 0, Gm1, 0, 0, 0, 0, C, 0, 0);
        double grad1 = -.5*trace(C);

	rmatrixgemm(N, N, N, 1, Alfa, 0, 0, 0, Gm2, 0, 0, 0, 0, C, 0, 0);
	double grad2 = -.5*trace(C);


	grad[0] = grad1;
	grad[1] = grad2;

}






