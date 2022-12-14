#include <iostream>
#include "complex.hpp"

int main(){
    Complex<int, int> c1 = Complex(2, 1);
    Complex<double, double> c2 = Complex(6.9, 8.9);

    c1.print();

    std::cout<<"the sum result is:"<<std::endl;
    Complex c3 = c1+c2;
    c3<<std::cout;


    std::cout<<"the multiplication result is:"<<std::endl;
    Complex c4 = c1*c2;
    c4<<std::cout;
    
    return 0;
}