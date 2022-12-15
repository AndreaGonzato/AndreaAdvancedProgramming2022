#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>
#include <random>
#include <algorithm>

template <typename T>
class Matrix{

    private:
        int N;
        std::unique_ptr<T[]> elements;


    public:

        Matrix(){};

        Matrix (Matrix<T> && p );

        void read_from_file(std::string filename);

        void random_fill(int n);

        T getElement(int i, int j) const;


        Matrix operator*(const Matrix& b);

        void print_to_file(std::string filename);

};


template <typename T>
Matrix<T>::Matrix(Matrix<T> && p ) {
    if (this != &p) {
        //copy non-dynamic variables
        N = p.N;
        p.N = 0;
        //create and copy dynamic variables
        elements = std::move(p.elements);
        p.elements.reset();
    }
        
}

template <typename T>
void Matrix<T>::print_to_file(std::string filename){
    std::ofstream outputfile(filename);
    
    outputfile << N << std::endl;
    for(int i = 0 ; i < N ; i++){
        for (int j = 0; j < N; j++){
            outputfile << elements[i*N + j] << " ";
        }
        outputfile << std::endl;
        
    }

}

template <typename T>
void Matrix<T>::read_from_file(std::string filename){
    std::ifstream inputfile(filename);
    if(inputfile){
        inputfile >> N;

        std::cout << "N: " << N << std::endl;

        elements = std::make_unique<T[]>(N*N);
        
        // read all the elements
        for (int i = 0; i < N*N; i++){
            inputfile >> elements[i];
        }

    }else{
        std::cout<< "ERROR: can not read from file " << filename << std::endl;
    }           

}

template <typename T>
T Matrix<T>::getElement(int i, int j) const {
    return elements[i*N+j];
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& b) {
    Matrix result = Matrix();
    result.N = N;
    result.elements = std::make_unique<T[]>(N*N);

    for (int row_a = 0; row_a < N; row_a++){
        for (int col_b = 0; col_b < N; col_b++){
            T val = 0;
            for (int i = 0; i < N; i++){
                val += getElement(row_a, i) * b.getElement(i, col_b);
            }
            result.elements[row_a*N+col_b] = val;
            
        }
        
    }
    
    return result;
    
}

template <typename T>
void Matrix<T>::random_fill(int n){
    constexpr auto low_bound = 0;
    constexpr auto up_bound = 100;
    //take the current time as a random value for the seed
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine dre(seed);//engine
    std::uniform_int_distribution<int> di(low_bound, up_bound);//distribution

    // init N and elements
    N = n;
    elements = std::make_unique<T[]>(N*N);

    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            elements[i*N+j] = di(dre);
        }
    }
    
    // next line is how Irina did it instead of my double for loop
    //std::generate(elements.begin(), elements.end(), [&](){ return di(dre);});//fill
};