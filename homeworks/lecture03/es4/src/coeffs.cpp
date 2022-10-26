#include "coeffs.hpp"
#include <iostream>
#include <fstream>

void CCoeffs::ask_for_input() {
    std::cout<<"I'm gonna read fro the file coeff.txt"<<std::endl;
    std::ifstream filevar("coeff.txt");
    if(filevar){
        filevar >> a >>b >>c;
    }  

    //std::cin >> a >> b >> c;
    
    if(a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
}

void CCoeffs::print() {
    std::cout<<"The equation has the following coefficients:"<<std::endl;
    std::cout<< a << " " << b<<" "<<c<<std::endl;
}


