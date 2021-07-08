#include <pybind11/pybind11.h>
#include <cxxlib/cxxlib.hpp>

namespace bindings
{

namespace py = pybind11;

PYBIND11_MODULE(cxxlib_python, m) {
    m.doc() = "module docs";
    m.attr("__version__") = "0.1.2";

    py::class_<cxx::lib>(m, "create")
    .def(py::init<>())
    .def("get_string", &cxx::lib::get_string)
    .def("get_double", &cxx::lib::get_double);
}

}