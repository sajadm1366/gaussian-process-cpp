#include <iostream>
#include "linalg.h"
#include <string>
#include "grad_decent.h"
#include "kernel.h"
#include "GP_Model.h"
#include <fstream>
#include "utils.h"


using namespace alglib;
using namespace std;
///////////////////////////////////////////////:

int load_data(real_1d_array &x,  string path);
void train();
void predict();


// main function
int main(int argc, char** argv){
	
	string mode;
	mode = argv[1];	
	if (mode == "train") {		

		// trian the model using the data in folder data/train
		train();

	}
	else if(mode == "predict"){

		// predict using the data in folder data/test
		predict();

	}else {

		cout << "mode not defined" << endl ;

	}

	return 0;
}


////////////////////////////////////////////////
// train function
void train()
{
	cout << "++++++++++++++++++" << endl;
	cout << "load  train data" << endl;
	cout << "+++++++++++++++++++" << endl;

	// inputs (features)
	real_2d_array x;
	// outputs
	real_1d_array y; 

	string path = "./data/train/input.txt";
	real_1d_array x_tmp;
	int K_in = load_data(x_tmp, path);
	cout << "number of features: " << K_in << endl;

	// reshape the features
	reshape(x_tmp, x, K_in);

	cout << "number of data points: " << x.rows() << endl;
	path =  "./data/train/output.txt";
	int K_out = load_data(y, path);

	cout << "++++++++++++++++++" << endl;
	int N = y.length();
	
	
	// gp with RBF kernel
	Rbf rbf;
	Model<Rbf> model(N, rbf);

	printf("+++++++ fitting ++++++++++\n");
	model.fit(x, y);

	std::ofstream tmpfile;
	tmpfile.open ("out-train.txt");
	tmpfile << "RBF\n";
	tmpfile << "alfa\t" << model.getKernel().alfa <<  std::endl;
	tmpfile << "beta\t" << model.getKernel().beta <<  std::endl;
	tmpfile << "sigma\t" << model.getKernel().sigma <<  std::endl;
	tmpfile.close();


	
}

/////////////////////////////////////////////////////////////////
// predict
void predict()
{
cout << "++++++++++++++++++" << endl;
	cout << "load  train data" << endl;
	cout << "+++++++++++++++++++" << endl;
	real_2d_array x;
	real_1d_array y;

	string path = "./data/train/input.txt";
	real_1d_array x_tmp;
	int K = load_data(x_tmp, path);
	cout << "number of features: " << K << endl;
	// reshape the features
	reshape(x_tmp, x, K);
	cout << "number of data points: " << x.rows() << endl;
	path =  "./data/train/output.txt";
	int Kk = load_data(y, path);

	//printf("%s\n", x.tostring(2).c_str());
	cout << "++++++++++++++++++" << endl;
	int N = y.length();

	cout << "load  test data" << endl;
	cout << "+++++++++++++++++++" << endl;
	real_2d_array x_new;
	real_1d_array y_new;
	path = "./data/test/input.txt";
	real_1d_array x_tmp2;
	load_data(x_tmp2, path);
	reshape(x_tmp2, x_new, K);
	y_new.setlength(x_new.rows());
	Rbf rbf;
	Model<Rbf> model(N, rbf);

	cout << "input value: " << endl;
	printf("%s\n", x_new.tostring(2).c_str());

	model.predict(x_new, y_new, x, y);

	cout << "output value: " << endl;
	printf("%s\n", y_new.tostring(2).c_str());
}



//////////////////////////////////////////////////////////////:
// load data set
int  load_data(real_1d_array &x,  string path)
{
		
	vector<string> x_tmp;
	int  pos_end;
	double tmp_val;

	ifstream ifs;
	string line;
	int K = 0;
	ifs.open(path);
	while (getline(ifs, line, '\n'))
	{
		// read one line of x
		if(line.size()>1) x_tmp.push_back(line);
		if (K == 0) K = x_tmp.size();


	}// end whil
	ifs.close();
	//cout << x_tmp.size() << endl;

	x.setlength(x_tmp.size());
	double x_val;
	for (int i=0; i<x_tmp.size(); i++)
	{
		x_val = stod(x_tmp[i]);
		x[i] = x_val;
	}
	return K;
}

