#include <gtest/gtest.h>
#include <cxxlib/cxxlib.hpp>

namespace cxx::tests
{

TEST(test, get_string)
{ 
    cxx::lib cxxlib;
    ASSERT_EQ(cxxlib.get_string(), "this is cxx lib!");
}

TEST(test, get_double)
{ 
    cxx::lib cxxlib;
    ASSERT_EQ(cxxlib.get_double(), 1.2345);
}

TEST(test, get_value_valid_json_valid_key)
{ 
    cxx::lib cxxlib;
    auto data = R"({ "a":"1", "b":"2", "c":"3" })";
    ASSERT_EQ(cxxlib.get_value(data, "b"), "\"2\"");
}

TEST(test, get_value_valid_json_invalid_key)
{ 
    cxx::lib cxxlib;
    auto data = R"({ "a":"1", "b":"2", "c":"3" })";
    ASSERT_EQ(cxxlib.get_value(data, "d"), "null");
}

TEST(test, get_value_invalid_json)
{ 
    cxx::lib cxxlib;
    auto data = R"(this is not a valid json)";
    ASSERT_EQ(cxxlib.get_value(data, "key"), "");
}

}