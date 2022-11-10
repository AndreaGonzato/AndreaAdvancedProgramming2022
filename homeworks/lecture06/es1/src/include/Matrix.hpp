#include <vector>
#include <iostream>
#include <fstream>
#include <memory>

template <typename T>
class Matrix{

    private:
        int N;
        std::unique_ptr<T[]> elements;



    public:

        Matrix(){
        };

        Matrix (Matrix<T> && p ) {
            if (this != &p) {
                //copy non-dynamic variables
                N = p.N;
                p.N = 0;
                //create and copy dynamic variables
                elements = std::move(p.elements);
                p.elements.reset();
            }
                
        }

        void read_from_file(std::string filename){
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
    
        };

        T getElement(int i, int j) const {
            return elements[i*N+j];
        }


        Matrix operator*(const Matrix& b) {
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
            
        };

        void print_to_file(std::string filename){
            std::ofstream outputfile(filename);
            
            outputfile << N << std::endl;
            for(int i = 0 ; i < N ; i++){
                for (int j = 0; j < N; j++){
                    outputfile << elements[i*N + j] << " ";
                }
                outputfile << std::endl;
                
            }

        };

};