#include <iostream>
#include <cstdlib>
#include <cstring>

// we want to create a program tha can accept and process the following input:
// ./code -n1 1 -n2 2 -n3 3
int main(int argc, char* argv[]){

    int n1 = 0, n2 = 0, n3 = 0;

	for (int i = 1; i < argc; i++){

		if (std::strcmp(argv[i], "-n1") == 0) {
			// The next argument should be the value of n1
			n1 = std::atoi(argv[i + 1]);
		}

		if (std::strcmp(argv[i], "-n2") == 0) {
			// The next argument should be the value of n2
			n2 = std::atoi(argv[i + 1]);
		}

		if (std::strcmp(argv[i], "-n3") == 0) {
			// The next argument should be the value of n3
			n3 = std::atoi(argv[i + 1]);
		}

	}


	std::cout << n1 << std::endl << n2 << std::endl << n3 <<std::endl;

	return 0;
}