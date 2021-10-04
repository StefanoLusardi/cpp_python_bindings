cmake_minimum_required (VERSION 3.16)
project (cxxlib_tests LANGUAGES CXX)

conan_cmake_autodetect(conan_settings)
conan_cmake_configure(REQUIRES gtest/1.11.0 GENERATORS cmake_find_package OUTPUT_QUIET)
conan_cmake_install(PATH_OR_REFERENCE . BUILD missing SETTINGS ${conan_settings} OUTPUT_QUIET)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/tests)
find_package(GTest COMPONENTS gtest REQUIRED QUIET)

set(CXXLIB_TESTS_SOURCES 
    src/main.cpp
    src/cxxlib_tests.cpp
)

add_executable(${PROJECT_NAME} ${CXXLIB_TESTS_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE cxxlib PRIVATE GTest::gtest)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME} DISCOVERY_MODE PRE_TEST)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR})

if(WIN32)
    file(GLOB CXXLIB_TESTS_EXE "${CMAKE_BINARY_DIR}/**/${PROJECT_NAME}.exe")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CXXLIB_TESTS_EXE} "${CMAKE_BINARY_DIR}/bin/")
endif()