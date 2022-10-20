#include <iostream>
#include <cmath>

#include "include/CCoeffs.hpp"
#include "include/CComplex.hpp"



class CQuadratic_Equation{
    public:
        CCoeffs coefficients = CCoeffs;


    void solve(){
        double delta = coefficients.b*coefficients.b - 4 * coefficients.a * coefficients.c;

        if (delta > 0){
            double x1 = (-coefficients.b + sqrt(delta) )/(2*coefficients.a);
            double x2 = (-coefficients.b - sqrt(delta) )/(2*coefficients.a);

            std::cout<<"x1:"<< x1 <<std::endl;
            std::cout<<"x2:"<< x2 <<std::endl;
        }else{

            CComplex x1 = CComplex();
            CComplex x2;

            x1.real = (-coefficients.b)/(2*coefficients.a);
            x1.imaginary = (sqrt(delta*-1) )/(2*coefficients.a);

            x2.real = (-coefficients.b)/(2*coefficients.a);
            x2.imaginary = (-sqrt(delta*-1) )/(2*coefficients.a);

            if (x1.imaginary >= 0){
                std::cout<<"x1: "<< x1.real << " i " <<x1.imaginary <<std::endl;
            }else{
                std::cout<<"x1: "<< x1.real << " -i " << x1.imaginary*-1 <<std::endl;
            }


            if (x2.imaginary >= 0){
                std::cout<<"x2: "<< x2.real << " i " <<x2.imaginary <<std::endl;
            }else{
                std::cout<<"x2: "<< x2.real << " -i " << x2.imaginary*-1 <<std::endl;
            }
            
        }
    }


};
