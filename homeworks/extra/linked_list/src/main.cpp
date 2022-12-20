#include <iostream>

#include "List.hpp"
#include "Node.hpp"

int main()
{

	List<int> l1 = List<int>();

	try
	{
		l1.loadFromFile("myList.txt");
		List<int> l2 = l1;
		l2.replaceIElement(1, 55);
		l1.print();
		l2.print();
	}
	catch (const Exception e)
	{
		std::cerr << "EXCEPTION: " <<e.message << '\n';
		l1.~List();
	}

	return 0;
}
