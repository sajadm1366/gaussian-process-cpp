#include "grad_decent.h"


Grad_decent::Grad_decent(float lr, int iterations){
	this->lr = lr;
	this->iterations = iterations;
}

void Grad_decent::step(alglib::real_1d_array &x, const alglib::real_1d_array &grad){
	for (int i=0; i<x.length(); i++)
	{
	x[i] -= lr *  grad[i];
	}
}

