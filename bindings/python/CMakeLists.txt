cmake_minimum_required (VERSION 3.17)

project (cxxlib_python_bindings CXX)

message("#########################")
message("CC: " $ENV{CC})
message("CXX: " $ENV{CXX})
message("CMAKE_C_COMPILER: " ${CMAKE_C_COMPILER})
message("CMAKE_CXX_COMPILER: " ${CMAKE_CXX_COMPILER})
message("#########################")

set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

#[[
set(CONAN_SYSTEM_INCLUDES ON)
set(CONAN_CMAKE_SILENT_OUTPUT ON)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake" TLS_VERIFY ON)
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(
    REQUIRES pybind11/2.7.1
    GENERATORS cmake_find_package
    OUTPUT_QUIET
)
conan_cmake_autodetect(conan_settings)
conan_cmake_install(
    PATH_OR_REFERENCE .
    BUILD missing
    SETTINGS ${conan_settings}
    OUTPUT_QUIET
)

]]

# list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/bindings/python)
# list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/bindings/python)

add_subdirectory(pybind11)
# find_package(pybind11 CONFIG REQUIRED QUIET)
pybind11_add_module(cxxlib_python src/cxxlib_python.cpp)
target_link_libraries(cxxlib_python PRIVATE cxxlib)
target_compile_definitions(cxxlib_python PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
