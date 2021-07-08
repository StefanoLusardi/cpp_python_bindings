project (cxxlib_examples
    LANGUAGES CXX 
    VERSION 1.0.0
)

add_executable(example_cpp src/example_cpp.cpp)
target_link_libraries(example_cpp PRIVATE cxxlib)