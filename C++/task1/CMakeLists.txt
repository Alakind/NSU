cmake_minimum_required(VERSION 3.5)
project(task1_trit)

#
# library with common functions for tests and exe
#

add_library(tritlib
        src/main.cpp
        src/trit.cpp
        src/trit.h)

set_target_properties(tritlib PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

#
# project itself
#

add_executable(trit
        src/main.cpp)

add_dependencies(trit tritlib)

set_target_properties(trit PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

target_link_libraries(trit tritlib)

#
# unit tests
#
add_executable(trit_unittests
        tests/main.cpp tests/trit_unittest.cpp)

set_target_properties(trit_unittests PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

target_include_directories(trit_unittests PRIVATE
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_SOURCE_DIR}/src"
        "${PROJECT_SOURCE_DIR}/tests/googletest"
        "${PROJECT_SOURCE_DIR}/tests/googletest/include")

add_dependencies(trit tritlib)


target_link_libraries(trit_unittests tritlib)

find_package(Threads REQUIRED)
target_link_libraries(trit_unittests ${CMAKE_THREAD_LIBS_INIT})