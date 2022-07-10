
#include <iostream>
#include "linalg.h"
#include <string>
#include "func.h"
#include "grad_decent.h"
#include "kernel.h"
#include "GP_Model.h"

int main(){
	//alglib::real_1d_array x = "[2, 1]";
	//Func square_func;

	//double y = square_func.eval(x);
	//std::cout <<"the value of function: " <<  y << std::endl;

	//std::cout << "suceeful run" << std::endl;


	//alglib::real_1d_array grad;
	//grad = square_func.grad(x);
	//printf("%s\n", grad.tostring(4).c_str());
	//alglib::real_2d_array H = square_func.Hess(x);
	//printf("%s\n", H.tostring(2).c_str());


	//Grad_decent opt(.001, 1000);
	//for (int i=0; i<1000; i++){
	//grad = square_func.grad(x);
	//opt.step(x, grad);
	//std::cout << square_func.eval(x) << std::endl;
	//	}
	//alglib::real_1d_array x = "[1 , 2, 3, 4, 5]";
	//alglib::real_1d_array y = "[1 , 2, 1, 1, 0]";
	//Rbf rbf(xx, 1, 1);
	//alglib::real_2d_array K;
	//K.setlength(xx.length(), xx.length());
	//rbf.kernel(K);
	//printf("%s\n", K.tostring(2).c_str());


	//alglib::real_2d_array Gm1;
	//Gm1.setlength(xx.length(), xx.length());
	//alglib::real_2d_array Gm2;
	//Gm2.setlength(xx.length(), xx.length());
	//rbf.grads(Gm1, Gm2);
	//printf("%s\n", Gm1.tostring(2).c_str());
//	printf("%s\n", Gm2.tostring(2).c_str());


	std::cout << "this is gp model" << std::endl;
	int N = 500;
	Rbf rbf;
	GP_model gp_model(N, rbf);
	//gp_model.fit(x, y);
	alglib::real_2d_array x;
	x.setlength(N, 1);
	for (int i=0; i<N; i++) x(i, 0) = i;

	alglib::real_1d_array y = gp_model.gen_data(x);
	printf("%s\n", y.tostring(2).c_str());

	printf("+++++++++++++++++++\n");
	gp_model.fit(x, y);
   	 return 0;
}
