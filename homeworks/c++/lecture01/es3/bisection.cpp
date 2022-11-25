#include <iostream>
#include <cmath>

class CCoeffs{
public:    
    double a;
    double b;
    double c;
    double d;
};


int main(){
    CCoeffs coefficients;
    coefficients.a = 1;
    coefficients.b = -6;
    coefficients.c = 11;
    coefficients.d = -6;

    int a{-10};
    int b{10};    
    
    double x = a;
    double evaluatea = coefficients.a * pow(x, 3) + coefficients.b * pow(x, 2) + coefficients.c * pow(x, 1) + coefficients.d;
    x = b;
    double evaluateb = coefficients.a * pow(x, 3) + coefficients.b * pow(x, 2) + coefficients.c * pow(x, 1) + coefficients.d;

    if(evaluatea*evaluateb > 0){
        std::cout<<"error there are no guarantee that there is a zero in this interval";
        return -1;
    }

    double evaluatem;
    double m ;
    do{
        m = (a + b)/ 2;
        x = m;
        evaluatem = coefficients.a * pow(x, 3) + coefficients.b * pow(x, 2) + coefficients.c * pow(x, 1) + coefficients.d;

        if(evaluatem * evaluateb < 0){
            a = m;
        }else{
            b = m;
        }
        
    }while (evaluatem > pow(10, -9) || evaluatem < -1* pow(10, -9));
  
    
    std::cout<<"solution: x= "<<m<<std::endl;
    std::cout<<"evaluate f(x)= "<<evaluatem<<std::endl;

    return 0;
}