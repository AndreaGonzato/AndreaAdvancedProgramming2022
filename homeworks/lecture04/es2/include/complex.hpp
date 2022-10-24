#ifndef complex_h
#define complex_h

#include <iostream>
#include <typeinfo>

template <typename T>
class Complex{
    public:
        T real = 0;
        T imaginary = 0;

        Complex(){
            real = 0;
            imaginary = 0;
        };
        Complex(T r, T i){
            real = r;
            imaginary = i;
        };
        void print(){
            if constexpr(std::is_same_v<int,T>){
                std::cout<<"this complex number store real and imaginary as int"<<std::endl;
            }
            if constexpr(std::is_same_v<double,T>){
                std::cout<<"this complex number store real and imaginary as double"<<std::endl;
            }
            std::cout<<real << " i "<< imaginary << std::endl;
        };

        template <typename M>
        Complex operator+(const Complex<M>& b) {
            Complex result;
            result.real = real + b.real;
            result.imaginary = imaginary + b.imaginary;
            return result;
        }


        template <typename M>
        Complex operator*(const Complex<M>& b) {
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