#include <vector>
#include <iostream>
#include <fstream>
#include <memory>

#define INIT_COEFF 0.5

template <typename T>
class Matrix
{

private:
    int N = 0;
    std::unique_ptr<T[]> elements;

    int static const STEP = 10;

public:
    Matrix(){};
    Matrix(int n);
    Matrix(Matrix<T> &&p);
    void operator=(const Matrix<T> & m);

    void init();
    void setBorders();


    Matrix<T> calculateJacobiStep();

    T getElement(int i, int j) const;
    void setElement(int i, int j, T newValue);

    void print_to_file(std::string filename);
};

template <typename T>
Matrix<T>::Matrix(int n)
{
    N = n;

    elements = std::make_unique<T[]>(N * N);
}

template <typename T>
void Matrix<T>::init(){
   	 // fill all the matrix with the INIT_COEFF
    for (int i = N; i < N * N; i++)
    {
		elements[i] = INIT_COEFF;
    }

    setBorders();
}

template <typename T>
Matrix<T>::Matrix(Matrix<T> &&p)
{
    // move constructor
    if (this != &p)
    {
        // copy non-dynamic variables
        N = p.N;
        p.N = 0;
        // create and copy dynamic variables
        elements = std::move(p.elements);
        p.elements.reset();
    }
}

template <typename T>
void Matrix<T>::operator=(const Matrix<T> & m){

    // copy all the elements
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            this->setElement(i, j, m.getElement(i, j));
        }
        
    }


}

template <typename T>
void Matrix<T>::setBorders(){
    // fill first row
    for (int i = 0; i < N; i++)
    {
        elements[i] = 0;
    }

    // fill the last row
    int counter = Matrix::STEP * (N - 1);
    for (int i = N * N - N; i < N * N; i++)
    {
        elements[i] = counter;
        counter -= Matrix::STEP;
    }

    // fill the last column
    for (int i = N - 1; i < N * N; i += N)
    {
        elements[i] = 0;
    }

    // fill the first column
    counter = 0;
    for (int i = 0; i < N * N; i += N)
    {
        elements[i] = counter;
        counter += Matrix::STEP;
    }
}

template <typename T>
Matrix<T> Matrix<T>::calculateJacobiStep(){
    Matrix<T> newMatrix = Matrix(N);

    newMatrix.setBorders();

    for (int i = 1; i < N-1; i++)
    {
        for (int j = 1; j < N-1; j++)
        {
            T newValue = 0.25 *(getElement(i-1, j) + getElement(i+1, j) + getElement(i, j-1) + getElement(i, j+1));
            newMatrix.setElement(i, j, newValue);
        }
        
    }
    
    return newMatrix;
}

template <typename T>
T Matrix<T>::getElement(int i, int j) const
{
    return elements[i * N + j];
}

template <typename T>
void Matrix<T>::setElement(int i, int j, T newValue){
    elements[i * N + j] = newValue;
}



template <typename T>
void Matrix<T>::print_to_file(std::string filename)
{
    std::ofstream file(filename);

    file << N << std::endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            file << elements[i * N + j] << " ";
        }
        file << std::endl;
    }

    file.close();
};
