#ifndef complex_h
#define complex_h

#include <iostream>
#include <typeinfo>


template <typename R, typename I>
class Complex{
    public:
        R real = 0;
        I imaginary = 0;

        Complex(){
            real = 0;
            imaginary = 0;
        };
        Complex(R r, I i){
            real = r;
            imaginary = i;
        };

        void printType(){
            if constexpr(std::is_same_v<int,R>){
                std::cout<<"this complex number store the real as an int"<<std::endl;
            }
            if constexpr(std::is_same_v<int, I>){
                std::cout<<"this complex number store the imaginary part as an int"<<std::endl;
            }
            if constexpr(std::is_same_v<double, R>){
                std::cout<<"this complex number store the real part as a double"<<std::endl;
            }
            if constexpr(std::is_same_v<double, I>){
                std::cout<<"this complex number store the imaginary part as a double"<<std::endl;
            }
        };

        void print(){
            printType();
            std::cout<<real << " i "<< imaginary << std::endl;
        };

        template <typename M, typename N>
        Complex operator+(const Complex<M, N>& b) {
            if constexpr(std::is_same_v<double, M>){
                std::cout<<"we are summing a real part that is double"<<std::endl;
            }
            if constexpr(std::is_same_v<double, N>){
                std::cout<<"we are summing a imaginary part that is double"<<std::endl;
            }
                        

            Complex result;
            result.real = real + b.real;
            result.imaginary = imaginary + b.imaginary;
            result.printType();
            return result;
        }


        template <typename M, typename N>
        Complex operator*(const Complex<M, N>& b) {
            Complex result;
            result.real = real * b.real - imaginary * b.imaginary;
            result.imaginary = real * b.imaginary + imaginary * b.real;
            result.printType();
            return result;
        }

        std::ostream& operator<<(std::ostream& os){
                os << real << " i" << imaginary << std::endl;
            return os;
        }


};

#endif