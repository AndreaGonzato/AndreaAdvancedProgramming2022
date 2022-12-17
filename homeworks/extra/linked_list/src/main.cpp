#include <iostream>

#include "List.hpp"
#include "Node.hpp"

int main()
{

	List<int> l1 = List(5);
	l1.push(8);
	l1.push(33);
	l1.push(45);
	l1.print();
	l1.remove();
	l1.remove();
	l1.remove();
	//l1.remove();
	
	l1.print();

	return 0;
}
