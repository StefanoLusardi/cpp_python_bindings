#pragma once
#include "api.hpp"
#include <string>

namespace cxx
{
struct API lib
{
public:
    explicit lib();
    std::string get_string();
    double get_double();
    std::string get_value(const std::string& json_str, const std::string& json_key);
};

}