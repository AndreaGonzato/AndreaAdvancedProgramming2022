#include <iostream>

int main()
{	
	int N{5};
	int* p =new int[N];
	for(int i=0;i<N;i++){
		p[i]=i;
	}

	std::cout<<p[3]<<std::endl;

	std::cout << "Hello world!" << std::endl;
	return 0;
}
