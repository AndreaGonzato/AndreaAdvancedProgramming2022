#include <iostream>
#include "Shape.hpp"
#include "Vertex.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"

int main()
{
	Vertex v1 = Vertex(0, 0);
	Vertex v2 = Vertex(0, 2);
	Vertex v3 = Vertex(2, 0);
	Triangle t1 = Triangle(v1, v2, v3);

	//t1.print_vertices();

	Vertex* vertices = new Vertex[3];
	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;

	Polygon p1(vertices, 3);
	p1.print_vertices();


	std::cout << t1.calc_perimeter() << std::endl;
	std::cout << p1.calc_perimeter() << std::endl;



	return 0;
}
