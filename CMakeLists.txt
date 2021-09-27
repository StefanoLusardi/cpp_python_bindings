cmake_minimum_required (VERSION 3.17)

project(cxxlib_project
    LANGUAGES CXX 
    VERSION 1.0.0
)

message("System Info: " ${CMAKE_SYSTEM} ${CMAKE_SYSTEM_PROCESSOR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

option(CXXLIB_TESTS "Build cxxlib tests" OFF)
option(CXXLIB_EXAMPLES "Build cxxlib examples" ON)
option(CXXLIB_BINDINGS_PYTHON "Build cxxlib Python bindings" ON)

add_subdirectory(cxxlib)

if(${CXXLIB_TESTS})
    enable_testing()
    add_subdirectory(tests)
endif()

if(${CXXLIB_EXAMPLES})
    add_subdirectory(examples)
endif()

if(${CXXLIB_BINDINGS_PYTHON})
    add_subdirectory(bindings/python)
endif()
