cmake_minimum_required (VERSION 3.16)
project(cxxlib_examples CXX)

add_executable(cxxlib_examples src/example_cpp.cpp)
target_link_libraries(cxxlib_examples PRIVATE cxxlib)