project(cxxlib
    LANGUAGES CXX 
    VERSION 1.0.0
)

set(CXXLIB_SOURCES 
    src/cxxlib.cpp)

set(CXXLIB_HEADERS 
    include/cxxlib/api.hpp
    include/cxxlib/cxxlib.hpp)

add_library(${PROJECT_NAME} SHARED ${CXXLIB_SOURCES} ${CXXLIB_HEADERS})
target_compile_definitions(${PROJECT_NAME} PRIVATE CXXLIB_API)
target_include_directories(${PROJECT_NAME} PUBLIC include)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${cxxlib_VERSION} SOVERSION ${cxxlib_VERSION_MAJOR})
