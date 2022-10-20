#include <iostream>
#include <cmath>


int main(){
    CQuadratic_Equation eq;
    eq.coefficients.ask_for_input();
    eq.solve();

    return 0;  
}