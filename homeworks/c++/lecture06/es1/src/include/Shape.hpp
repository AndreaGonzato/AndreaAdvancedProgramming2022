#pragma once

class Shape
{
private:
public:
    Shape();
    virtual ~Shape();

    virtual double calc_perimeter(){return -1;};
    virtual void print_vertices(){};
};

Shape::Shape(/* args */)
{
}

Shape::~Shape()
{
}
