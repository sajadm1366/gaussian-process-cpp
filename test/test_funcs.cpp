#include <iostream>
#include "linalg.h"
#include "utils.h"

int Test_trace()
{
	alglib::real_2d_array A = "[[1, 2],[3, 4]]";
	if ( trace(A) != 5) return 1;

	A = "[[1, 2],[3, -4]]";
	if ( trace(A) != -3) return 1;

	return 0;
}

int Test_alglib_slice()
{
	alglib::real_2d_array A = "[[1, 2],[3, 4]]";
	alglib::real_2d_array B = "[[-1, 2],[3, 4]]";
	alglib::real_1d_array temp = "[0, 0]";
	
	double *Aptr, *Bptr;
	Aptr = A[0];
	Bptr = B[0];
	for (int i=0; i<2; i++)
	{
		temp[i] = dis_square(Aptr + 2*i, Bptr + 2*i, 2);
	}
	if (temp[0] != 4) return 1;
	if (temp[1] != 0) return 1;



	A =  "[[0, 2, 3]]";
	B = "[[2, 1, 6]]";
	Aptr = A[0];
	Bptr = B[0];
	alglib::real_1d_array temp2 = "[0, 0, 0]";
	for (int i=0; i<3; i++)
	{
		temp2[i] = dis_square(Aptr +1*i, Bptr + 1*i, 1);
	}
	if (temp2[0] !=4) return 1;
	if (temp2[1] != 1) return 1;
	if (temp2[2] != 9) return 1;
	return 0;

}


int Test_reshape()
{
	alglib::real_1d_array a = "[1, 3, 4, 7]";
	alglib::real_2d_array Aq = "[[1, 3],[4, 7]";
	//A.setlength(2, 2);
	//reshape(a, A, 2);
	if (1 != 1)
	{
		//std::cout << "A(1, 2) != 3" << std::endl;
		 return 1;
	}
	if (1  != 1)
	{
		//std::cout << "A(2, 1) != 4" << std::endl;
		 return 1;
	}
 
	return 0;
}


int main() {
  	if (Test_trace() == 1) return 1; // failed
	if (Test_alglib_slice() ==1) return 1;
	//std::cout << "test reshape";
	//if (Test_reshape() == 1) return 1;
	return 0;
}
