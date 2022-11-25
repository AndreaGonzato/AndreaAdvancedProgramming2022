#pragma once

#include <iostream>
#include "Shape.hpp"
#include "Vertex.hpp"


class Triangle : public Shape
{
private:
    Vertex v1, v2, v3;
public:
    Triangle(Vertex& _v1, Vertex& _v2, Vertex& _v3);
    ~Triangle();

    double calc_perimeter() override;
    void print_vertices() override;

    friend std::ostream& operator<<(std::ostream&, const Triangle&);
};

Triangle::Triangle(Vertex& _v1, Vertex& _v2, Vertex& _v3)
{
    v1 = _v1;
    v2 = _v2;
    v3 = _v3;
}

Triangle::~Triangle()
{
}

double Triangle::calc_perimeter() {
    return v1.distance(v2) + v2.distance(v3) + v3.distance(v1);
}

void Triangle::print_vertices(){
    std::cout<< "v1: " << v1 << std::endl << "v2: " << v2 << std::endl << "v3: " << v3 << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Triangle& t){
    return stream << "triangle{ v1: " << t.v1 << std::endl << " v2: " << t.v2 << std::endl << " v3: " << t.v3 << "}";
}
