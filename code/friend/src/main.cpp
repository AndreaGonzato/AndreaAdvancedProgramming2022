#include <iostream>
#include "MyClass.hpp"

int main()
{
	MyClass m1 = MyClass(5);
	MyClass m2 = MyClass(5);
	auto m3 = sum(m1, m2);
	m3.print();
	std::cout << "Hello world!" << std::endl;
	return 0;
}
