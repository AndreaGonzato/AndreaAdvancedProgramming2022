#include <vector>
#include <iostream>
#include <fstream>

template <typename T>
class Matrix{

    private:
        std::vector<T> elements;
        int N;

    public:

        Matrix(){};

        void read_from_file(std::string filename){
            std::ifstream inputfile(filename);
            if(inputfile){
                inputfile >> N;

                std::cout << "N: " << N << std::endl;

                elements.reserve(N*N);
                
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
            result.elements.reserve(N*N);

            for (int row_a = 0; row_a < N; row_a++){
                for (int col_b = 0; col_b < N; col_b++){
                    double val = 0;
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