#pragma once

#include <iostream>
#include <math.h> 

class Vertex
{
private:
    double x, y;    
public:
    Vertex(){};
    Vertex(double a, double b);
    ~Vertex();

    double distance(Vertex& v2);

    friend std::ostream& operator<<(std::ostream&, const Vertex&);

};



Vertex::Vertex(double a, double b)
{
    x = a;
    y = b;
}

Vertex::~Vertex()
{
}

double Vertex::distance(Vertex& v2){
    return sqrt( pow(x-v2.x, 2) + pow(y-v2.y, 2));
}


std::ostream& operator<<(std::ostream &strm, const Vertex &a) {
    return strm << "vertex{ x: " << a.x << ", y: " << a.y << " }";
}

