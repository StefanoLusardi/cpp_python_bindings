project(cxxlib
    LANGUAGES CXX 
    VERSION 1.0.0
)

set(CXXLIB_SOURCES 
    src/cxxlib.cpp)

set(CXXLIB_HEADERS 
    include/cxxlib/api.hpp
    include/cxxlib/cxxlib.hpp)

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
    REQUIRES nlohmann_json/3.10.2
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

find_package(nlohmann_json REQUIRED QUIET)

add_library(${PROJECT_NAME} SHARED ${CXXLIB_SOURCES} ${CXXLIB_HEADERS})
target_compile_definitions(${PROJECT_NAME} PRIVATE CXXLIB_API)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${cxxlib_VERSION} SOVERSION ${cxxlib_VERSION_MAJOR})
