#include <iostream>

template <class T1, class T2>
T1 sum(const T1& par1, const T2& par2){
	return par1 + par2;
};

template <class T, class... Ts>
T sum(const T& arg, const Ts&... args){
	return arg + sum(args...);
};

int main()
{
	
	std::cout<< sum(1, 1, 4, 5.5) << std::endl;

	return 0;
}
