#include <iostream>
#include <cxxlib/cxxlib.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

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

std::string lib::get_value(const std::string& json_str, const std::string& json_key)
{
    try
    {
        auto j = json::parse(json_str);
        std::cout << "Input json: " << j.dump(2) << std::endl;
        
        auto json_value = j[json_key];
        std::cout << "Input key : " << json_key << std::endl;

        return json_value.dump();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return "";
    }
    
}

}