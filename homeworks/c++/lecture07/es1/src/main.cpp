#include <iostream>
#include "Matrix.hpp"

int main()
{
	int N = 1000;
	Matrix<double> A,B;

	A.random_fill(N);
	B.random_fill(N);

	//A.print_to_file("A.txt");
	//B.print_to_file("B.txt");

	//A.read_from_file("A.txt");
	//B.read_from_file("B.txt");

	//A.random_fill();



	auto C = A*B;
	std::cout << "computed the multiplication" << std::endl;
	C.print_to_file("C.txt");

	std::cout << "printed on file matrix C" << std::endl;

	return 0;
}
