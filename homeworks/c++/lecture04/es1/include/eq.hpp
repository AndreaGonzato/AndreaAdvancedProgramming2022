#pragma once
#include "coeffs.hpp"
#include "eq.hpp"
#include <cmath>
#include <iostream>


struct myComplex{
    double r;
    double im;
};

template <typename T>
class CQuadratic_Equation{
public:
   CCoeffs<T> coeffs;    
   myComplex sol1;
   myComplex sol2;
   CQuadratic_Equation(){
     sol1.r=0;sol2.r=0;sol1.im=0;sol2.im=0;    
   };
   void solve(){
    double discr = coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c;
    if (discr >= 0){
          //for performance (which doesn't matter now, but can in general)
          //we calculate the complicated math only once
          double inv2a=1/(2*coeffs.a);
          double root_of_discr = std::sqrt(discr);
          sol1.r = (-coeffs.b + root_of_discr)*inv2a;
          sol2.r = (-coeffs.b - root_of_discr)*inv2a;
          
    } else {
          double inv2a=1/(2*coeffs.a);
          double root_of_discr = std::sqrt(-discr);
          sol1.r=-coeffs.b*inv2a; sol1.im=root_of_discr*inv2a;
          sol2.r=-coeffs.b*inv2a; sol2.im=-root_of_discr*inv2a;
      }
   };
   void print_solution(){
      //not the best printing format
      std::cout<<"solutions are: "<<sol1.r << " + i*" <<sol1.im<<std::endl;
      std::cout<<sol2.r << " + i*" <<sol2.im<<std::endl;
   };
};

