#include <iostream>
#include "Matrix.hpp"


template <typename T>
void init(Matrix<T> matrix){
	// TODO move Matrix.init here
}

int main()
{
	Matrix<double> firstMatrix = Matrix<double>(11);
	firstMatrix.init();
	
	Matrix<double> matrix = firstMatrix.calculateJacobiStep();
	for (int i = 0; i < 999; i++)
	{
		matrix = matrix.calculateJacobiStep();
	}
	
	matrix.print_to_file("result.txt");


	return 0;
}
