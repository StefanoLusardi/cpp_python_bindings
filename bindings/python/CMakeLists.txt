cmake_minimum_required (VERSION 3.17)

project (cxxlib_python_bindings CXX)

set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

include(FetchContent)

FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG        v2.7.1)

FetchContent_GetProperties(pybind11)
if(NOT pybind11_POPULATED)
    FetchContent_Populate(pybind11)
    add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
endif()


pybind11_add_module(cxxlib_python src/cxxlib_python.cpp)
target_link_libraries(cxxlib_python PRIVATE cxxlib)
target_compile_definitions(cxxlib_python PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
