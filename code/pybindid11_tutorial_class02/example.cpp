#include <pybind11/pybind11.h>
#include <iostream>

namespace py = pybind11;

class Coordinate{
    public:
        int x;
        int y;

        Coordinate(const int x1, const int y1){
            x = x1;
            y = y1;
        }

        int getX(){
            return x;
        }

        int getY(){
            return y;
        }
};


class Matrix {
    public: 
        Coordinate val;

        Matrix(const Coordinate v) : val(v){}

        Coordinate getVal(){
            return val;
        }

        void setVal(Coordinate v){
            val = v;
        }

        void doubleVal(){
            val.x = val.x * 2;
            val.y = val.y * 2;
        }
        

};


PYBIND11_MODULE(example, m) {
    py::class_<Coordinate>(m, "Coordinate")
        .def(py::init<const int, const int>())
        .def("getX", &Coordinate::getX)
        .def("getY", &Coordinate::getY);

    py::class_<Matrix>(m, "Matrix")
        .def(py::init<const Coordinate>())
        .def("doubleVal", &Matrix::doubleVal)
        .def("getVal", &Matrix::getVal)
        .def("setVal", &Matrix::setVal);
}