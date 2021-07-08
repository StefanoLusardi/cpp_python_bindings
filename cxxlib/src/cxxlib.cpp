#include <cxxlib/cxxlib.hpp>

namespace cxx
{
    
lib::lib()
{}

std::string lib::get_string()
{
    return "this is cxx lib!";
}

double lib::get_double()
{
    return 1.2345;
}

}