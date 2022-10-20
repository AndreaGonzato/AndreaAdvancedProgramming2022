#include <iostream>

void add_two_ref(int & a){
    a=a+2;
}

int main(){
    int a = 4;
    add_two_ref(a);
    std::cout<<a<<std::endl;
    return 0;
}