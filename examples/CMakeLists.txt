cmake_minimum_required (VERSION 3.16)
project(cxxlib_examples CXX)

add_executable(cxxlib_examples src/example_cpp.cpp)
target_link_libraries(cxxlib_examples PRIVATE cxxlib)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR})

if(WIN32)
    file(GLOB CXXLIB_EXAMPLES_EXE "${CMAKE_BINARY_DIR}/**/${PROJECT_NAME}.exe")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CXXLIB_EXAMPLES_EXE} "${CMAKE_BINARY_DIR}/bin/")
endif()