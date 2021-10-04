#include <pybind11/pybind11.h>
#include <cxxlib/cxxlib.hpp>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace bindings
{

namespace py = pybind11;

PYBIND11_MODULE(cxxlib_python, m) {
    m.doc() = "module docs";

    py::class_<cxx::lib>(m, "create")
    .def(py::init<>())
    .def("get_string", &cxx::lib::get_string)
    .def("get_double", &cxx::lib::get_double)
    .def("get_value" , &cxx::lib::get_value, "Get the value corresponding to the given key of the input json", py::arg("json_str"), py::arg("json_key"))
    ;

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY((VERSION_INFO));
#else
    m.attr("__version__") = "dev";
#endif
}

}