#ifndef COMPLEX_H
#define COMPLEX_H

void hello();

class Complex{
    public:
        int real, imaginary;
        Complex(int r, int i);
        void print();
};

#endif