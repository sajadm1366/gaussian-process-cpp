#include "GP_Model.h"
#include "math.h"
#include "utils.h"
#include <random>
#include <string>
#include <fstream>


using namespace alglib;
using namespace std;


template Model<Rbf>::Model(int , Rbf &);
template Model<Exp>::Model(int , Exp &);
template <typename T>
Model<T>::Model(int N, T &kernel){	
   	this->N = N;
	this->kernel = kernel;
}

// generate data
template real_1d_array Model<Rbf>::gen_data(const real_2d_array &);
template real_1d_array Model<Exp>::gen_data(const real_2d_array &);
template <typename T>
real_1d_array Model<T>::gen_data(const real_2d_array &x)
{
	// compute covaraince matrix
	kernel.x = x;
	real_2d_array K;
	K.setlength(N, N);
	kernel.cov(K);
	
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


////////////////////////////////////////////////////////////////////::
// fit model
template void  Model<Rbf>::fit(const real_2d_array &, const real_1d_array &);
template void  Model<Exp>::fit(const real_2d_array &, const real_1d_array &);
template <typename T>
void Model<T>::fit(const real_2d_array &x, const  real_1d_array &y){

	// compute covaraince matrix
	real_2d_array K;
	K.setlength(N, N);
	kernel.x = x;
	kernel.alfa = 0;
	kernel.beta = 0;
	kernel.sigma = 0;
	kernel.cov(K); //  cov matrix
	real_2d_array inv_K(K);
	ae_int_t info;
        matinvreport rep;
        rmatrixinverse(inv_K, info, rep);


	// preallocate grad
	real_1d_array grad("[0, 0, 0]");

	double l, norm_grad;
	double learning_rate = .0001;
	for (int i=0; i<5000; i++)
	{
		l = loglikelihood(y, K, inv_K);
		// get grads
		grad_loglikelihood(y, K, inv_K, grad);

		// update parameters
		kernel.alfa +=   learning_rate*grad[0];
		kernel.beta +=   learning_rate*grad[1];
		kernel.sigma +=  learning_rate*grad[2];

		// update kernel and its inverse
		kernel.cov(K);
		inv_K = K;
		rmatrixinverse(inv_K, info, rep);
		
		norm_grad = pow(grad[0], 2) + pow(grad[1], 2) + pow(grad[2], 2);

		if (norm_grad < .01) {
			break;
		}
		
		std::cout << "iter:" << i <<  " ,loglike:"<< l << std::endl;
	
	}


}


template <typename T>
double Model<T>::loglikelihood(const real_1d_array &y,const real_2d_array &K,const real_2d_array &inv_K)
 {
	real_1d_array c;
	c.setlength(N);
	rmatrixgemv(N, N, 1, inv_K, 0, 0, 0, y, 0,0, c, 0);
	double term1 = -.5 * dot(y, c, N);
	double term2 = -.5 * log_det(K);
 
	return term1 + term2 - N/2 * log(6.5);
}

/////////////////////////////////////////////////////////////////////
// compute grads
template <typename T>
void Model<T>::grad_loglikelihood(const real_1d_array &y, real_2d_array &K, real_2d_array &inv_K, real_1d_array &grad)
{
	//printf("test0\n");
	real_1d_array alfa;
	alfa.setlength(N);
	rmatrixgemv(N, N, 1, inv_K, 0, 0, 0, y, 0,0, alfa, 0);
	real_2d_array Gm1, Gm2, Gm3;
	Gm1.setlength(N, N);
	Gm2.setlength(N, N);
	Gm3.setlength(N , N);
	kernel.grads(Gm1, Gm2, Gm3);

	real_2d_array Alfa(inv_K);
	rmatrixger(N, N, Alfa, 0, 0, -1, alfa, 0, alfa, 0);
	
	real_2d_array C;
	C.setlength(N, N);
	rmatrixgemm(N, N, N, 1, Alfa, 0, 0, 0, Gm1, 0, 0, 0, 0, C, 0, 0);
        double grad1 = -.5*trace(C);

	rmatrixgemm(N, N, N, 1, Alfa, 0, 0, 0, Gm2, 0, 0, 0, 0, C, 0, 0);
	double grad2 = -.5*trace(C);

	rmatrixgemm(N, N, N, 1, Alfa, 0, 0, 0, Gm3, 0, 0, 0, 0, C, 0, 0);
	double grad3 = -.5*trace(C);

	grad[0] = grad1;
	grad[1] = grad2;
	grad[2] = grad3;

}




template Rbf  Model<Rbf>::getKernel();
template Exp  Model<Exp>::getKernel();
template<typename T>
T Model<T>::getKernel()
{
	return kernel;
}


///////////////////////////////////////////////////////////////////////:
// prediction 

template void  Model<Rbf>::predict(real_2d_array &x_new, real_1d_array &y_new, const real_2d_array &x, const real_1d_array &y);
template void  Model<Exp>::predict(real_2d_array &x_new, real_1d_array &y_new,  const real_2d_array &x, const real_1d_array &y);
template <typename T>
void Model<T>::predict(real_2d_array &x_new, real_1d_array &y_new, const real_2d_array &x, const real_1d_array &y)
{

	int M = x_new.cols();
	ifstream ifs;
	string line;
	ifs.open("out-train.txt");
	getline(ifs, line);
	getline(ifs, line);
	int pos0 = line.find("\t");
	int pos1 = line.size();
	kernel.alfa = stod(line.substr(pos0, pos1));
	getline(ifs, line);
	pos0 = line.find("\t");
	pos1 = line.size();
	kernel.beta = stod(line.substr(pos0, pos1));

	getline(ifs, line);
	pos0 = line.find("\t");
	pos1 = line.size();
	kernel.sigma = stod(line.substr(pos0, pos1));

	ifs.close();
	


	real_2d_array K;
	K.setlength(N, N);
	kernel.x = x;
	kernel.cov(K); //  cov matrix
	
	real_2d_array Kc;
	Kc.setlength(M + 1, N);
	kernel.cross_cov(x_new, Kc);

	// compute inverse of covarince matrix
	real_2d_array inv_K(K);
	ae_int_t info;
        matinvreport rep;
        rmatrixinverse(inv_K, info, rep);

	real_1d_array alfa;
	alfa.setlength(N);
	
	rmatrixgemv(N, N, 1, inv_K, 0, 0, 0, y, 0,0, alfa, 0);
	
	rmatrixgemv(M, N, 1, Kc, 0, 0, 0, alfa, 0,0, y_new, 0);

}

