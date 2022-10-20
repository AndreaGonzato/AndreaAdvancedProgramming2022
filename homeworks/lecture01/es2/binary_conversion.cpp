#include <iostream>
#include <cmath>



int main(){
    int number;
    std::cout<<"Enter a number to convert in to binary base" <<std::endl;
    std::cin>>number;

    int bits = (int) log2(number)+1;
    short int conversion[bits];

    int current = number;
    for(int i=0 ; i<bits ; i++){
        conversion[i] = current % 2;
        current = current / 2;
    }

    // print the number in binary
    for(int i=bits-1 ; i>=0 ; i--){
        std::cout<<conversion[i];
    }
    std::cout<<std::endl;


    return 0;
}