#include <iostream> 
#include "../include/complex.hpp"

void hello(){
     std::cout<<"Hello, this is a function"<<std::endl;
}


Complex::Complex(int r, int i){
     real = r;
     imaginary = i;
}

void Complex::print(){
     std::cout<< real << " +i "<< imaginary <<std::endl;
}
 

