project (cxxlib_tests
    LANGUAGES CXX 
    VERSION 1.0.0
)

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
    REQUIRES gtest/1.11.0
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

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/tests)
find_package(GTest COMPONENTS gtest REQUIRED QUIET)

set(CXXLIB_TESTS_SOURCES 
    src/main.cpp
    src/cxxlib_tests.cpp
)

add_executable(${PROJECT_NAME} ${CXXLIB_TESTS_SOURCES})

target_link_libraries(${PROJECT_NAME} 
	PRIVATE cxxlib
	PRIVATE GTest::gtest
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
