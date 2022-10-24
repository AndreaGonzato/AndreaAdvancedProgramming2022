#ifndef complex_h
#define complex_h

#include <iostream>

class Complex{
    public:
        int real = 0;
        int imaginary = 0;

        Complex(){
            real = 0;
            imaginary = 0;
        };
        Complex(int r, int i);
        void print();

        Complex operator+(const Complex& b) {
            Complex result;
            result.real = real + b.real;
            result.imaginary = imaginary + b.imaginary;
            return result;
        }

        Complex operator*(const Complex& b) {
            Complex result;
            result.real = real * b.real - imaginary * b.imaginary;
            result.imaginary = real * b.imaginary + imaginary * b.real;
            return result;
        }

        std::ostream& operator<<(std::ostream& os){
                os << real << " i" << imaginary << std::endl;
            return os;
        }


};

#endif