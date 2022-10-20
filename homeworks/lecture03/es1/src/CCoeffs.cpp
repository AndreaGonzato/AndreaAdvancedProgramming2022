#include <iostream>

class CCoeffs{
public:    
    double a;
    double b;
    double c;

    CCoeffs(){
        
    }

    void ask_for_input(){
        std::cout<<"enter the coefficients a b and c"<<std::endl;
        std::cin>>a;
        std::cin>>b;
        std::cin>>c;
        std::cout<<"you entered the following coefficients a: "<< a << " b: "<<  b << " c: "<< c <<std::endl;
    }

};