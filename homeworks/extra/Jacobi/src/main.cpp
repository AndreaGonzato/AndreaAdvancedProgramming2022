#include <iostream>
#include "Matrix.hpp"
#include <string>


template <typename T>
void init(Matrix<T> matrix){
	// TODO move Matrix.init here
}

int main()
{
	Matrix<double> matrix = Matrix<double>(11);
	matrix.init();
	matrix.print_to_file("first");
	
	for (int i = 0; i < 1000; i++)
	{
		matrix = matrix.calculateJacobiStep();
	}

	matrix.print_to_file("result");


	return 0;
}
