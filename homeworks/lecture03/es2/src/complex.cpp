#include <iostream>
#include "complex.hpp"

Complex::Complex(int r, int i){
    real = r;
    imaginary = i;
}

void Complex::print(){
    std::cout<<real << " i "<< imaginary << std::endl;
}

