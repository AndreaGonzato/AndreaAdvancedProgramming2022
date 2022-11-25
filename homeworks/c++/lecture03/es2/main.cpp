#include <iostream>
#include "complex.hpp"

int main(){
    Complex c1 = Complex(2, 1);
    Complex c2 = Complex(6, 8);

    std::cout<<"the sum result sum is:"<<std::endl;
    Complex c3 = c1+c2;
    c3<<std::cout;


    std::cout<<"the multiplication result is:"<<std::endl;
    Complex c4 = c1*c2;
    c4<<std::cout;
    
    return 0;
}