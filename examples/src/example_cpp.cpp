#include <cxxlib/cxxlib.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    cxx::lib cxxlib;
    std::cout << cxxlib.get_string() << std::endl;
    std::cout << cxxlib.get_double() << std::endl;

    return 0;
}