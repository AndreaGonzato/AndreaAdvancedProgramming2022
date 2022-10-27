#include <iostream>
#include "Matrix.hpp"

int main()
{
	Matrix<double> A,B;
	A.read_from_file("A.txt");
	B.read_from_file("B.txt");


	auto C=A*B;
	C.print_to_file("C.txt");
	return 0;
}
