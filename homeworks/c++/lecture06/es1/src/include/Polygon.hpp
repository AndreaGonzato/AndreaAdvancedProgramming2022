#pragma once

#include "Shape.hpp"
#include "Vertex.hpp"

class Polygon : public Shape
{
private:
    Vertex* vertices;
    int size;
public:
    Polygon(Vertex* _vertices, int _size);
    ~Polygon();

    double calc_perimeter() override;
    void print_vertices() override;


};

Polygon::Polygon(Vertex* _vertices, int _size)
{   
    vertices = _vertices;
    size = _size;
}

Polygon::~Polygon()
{
    delete[] vertices;
}


void Polygon::print_vertices(){
    
    for (int i = 0; i < size; i++)
    {
        std::cout <<   "v" + std::to_string(i) + ": " << vertices[i] << std::endl;
    }

    
}

double Polygon::calc_perimeter(){
    double perimeter = vertices[size-1].distance(vertices[0]);

    for (int i = 0; i < size-1; i++)
    {
        perimeter += vertices[i].distance(vertices[i+1]);
    }

    
    return perimeter;
}
