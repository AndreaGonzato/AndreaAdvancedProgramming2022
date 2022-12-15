#include <pybind11/pybind11.h>

namespace py = pybind11;

long long int fact(long long int n) {
    if (n == 1){
        return 1;
    }
    return n * fact(n-1);
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("fact", &fact, "A function that calculate the factorian of a number", py::arg("n"));
}
