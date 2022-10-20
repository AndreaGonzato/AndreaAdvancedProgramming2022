#include <iostream>
#include <cmath>


class CComplex{
    public:
        double real;
        double imaginary;
};

class CCoeffs{
public:    
    double a;
    double b;
    double c;

    void ask_for_input(){
        std::cout<<"enter the coefficients"<<std::endl;
        std::cin>>a;
        std::cin>>b;
        std::cin>>c;
        std::cout<<"you entered the following coefficients a: "<< a << " b: "<<  b << " c: "<< c <<std::endl;
    }

};

class CQuadratic_Equation{
    public:
        CCoeffs coefficients;


    void solve(){
        double delta = coefficients.b*coefficients.b - 4 * coefficients.a * coefficients.c;

        if (delta > 0){
            double x1 = (-coefficients.b + sqrt(delta) )/(2*coefficients.a);
            double x2 = (-coefficients.b - sqrt(delta) )/(2*coefficients.a);

            std::cout<<"x1:"<< x1 <<std::endl;
            std::cout<<"x2:"<< x2 <<std::endl;
        }else{

            CComplex x1;
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


int main(){
    CQuadratic_Equation eq;
    eq.coefficients.ask_for_input();
    eq.solve();

    return 0;  
}