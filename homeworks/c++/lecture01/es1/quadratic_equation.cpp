#include <iostream>
#include <cmath>


//by default all variables are private
class CCoeffs{
public:    
    double a;
    double b;
    double c;
};

int main(){
    CCoeffs coefficients;

    std::cout<<"enter the coefficients"<<std::endl;
    std::cin>>coefficients.a;
    std::cin>>coefficients.b;
    std::cin>>coefficients.c;
    std::cout<<"you entered the following coefficients a: "<< coefficients.a << " b: "<<  coefficients.b << " c: "<< coefficients.c <<std::endl;

    double delta = coefficients.b*coefficients.b - 4 * coefficients.a * coefficients.c;

    if (delta > 0){
        double x1 = (-coefficients.b + sqrt(delta) )/(2*coefficients.a);
        double x2 = (-coefficients.b - sqrt(delta) )/(2*coefficients.a);

        std::cout<<"x1:"<< x1 <<std::endl;
        std::cout<<"x2:"<< x2 <<std::endl;
    }else{

        double rx1 = (-coefficients.b)/(2*coefficients.a);
        double ix1 = (sqrt(delta*-1) )/(2*coefficients.a);

        double rx2 = (-coefficients.b)/(2*coefficients.a);
        double ix2 = (-sqrt(delta*-1) )/(2*coefficients.a);

        if (ix1 >= 0){
            std::cout<<"x1: "<< rx1 << " i " <<ix1 <<std::endl;
        }else{
            std::cout<<"x1: "<< rx1 << " -i " << ix1*-1 <<std::endl;
        }


        if (ix2 >= 0){
            std::cout<<"x2: "<< rx2 << " i " <<ix2 <<std::endl;
        }else{
            std::cout<<"x2: "<< rx2 << " -i " << ix2*-1 <<std::endl;
        }
        
        

    }
    




    return 0;  
}