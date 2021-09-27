#include <cxxlib/cxxlib.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    cxx::lib cxxlib;
    std::cout << cxxlib.get_string() << std::endl << std::endl;
    std::cout << cxxlib.get_double() << std::endl << std::endl;
    
    auto a = cxxlib.get_value(R"({ "a":"1", "b":"2", "c":"3" })", "b");
    std::cout << "Value: " << a << std::endl << std::endl;

    auto b = cxxlib.get_value(R"({ })", "the_key");
    std::cout << "Value: " << b << std::endl << std::endl;

    auto c = cxxlib.get_value(R"(this is not a valid json)", "the_key");
    std::cout << "Value: " << c << std::endl << std::endl;

    return 0;
}
