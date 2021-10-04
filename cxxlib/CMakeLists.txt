cmake_minimum_required (VERSION 3.16)
project(cxxlib
    LANGUAGES CXX 
    VERSION 1.0.0
)

conan_cmake_autodetect(conan_settings)
conan_cmake_configure(REQUIRES nlohmann_json/3.10.2 GENERATORS cmake_find_package OUTPUT_QUIET)
conan_cmake_install(PATH_OR_REFERENCE . BUILD missing SETTINGS ${conan_settings} OUTPUT_QUIET)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/cxxlib)
find_package(nlohmann_json REQUIRED QUIET)

set(CXXLIB_SOURCES 
    src/cxxlib.cpp)

set(CXXLIB_HEADERS 
    include/cxxlib/api.hpp
    include/cxxlib/cxxlib.hpp)

add_library(${PROJECT_NAME} SHARED ${CXXLIB_SOURCES} ${CXXLIB_HEADERS})
target_compile_definitions(${PROJECT_NAME} PRIVATE CXXLIB_API)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${cxxlib_VERSION} SOVERSION ${cxxlib_VERSION_MAJOR})

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${CXXLIB_HEADERS} DESTINATION include/${PROJECT_NAME})

if(WIN32)
    file(GLOB CXXLIB_DLL "${CMAKE_BINARY_DIR}/**/${PROJECT_NAME}.dll")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CXXLIB_DLL} "${CMAKE_BINARY_DIR}/bin/")
endif()