#include <iostream>
#include "complex.hpp"






template <typename T>
void print(const T& x){
    //all we need is the operator << be defined for the type T
    std::cout<<x<<std::endl;
}

int main(){



    print(2);
    print("dsf");
    print(9.99);
    print('f');
    
    
    return 0;
}

