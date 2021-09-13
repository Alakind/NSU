cmake_minimum_required(VERSION 3.5)
project(task2_executor)

#
# library with common functions for tests and exe
#

add_library(executorlib
        src/main.cpp
        src/executor.cpp
        src/executor.h)

set_target_properties(executorlib PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

#
# project itself
#

add_executable(executor
        src/main.cpp)

add_dependencies(executor executorlib)

set_target_properties(executor PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

target_link_libraries(executor executorlib)

#
# unit tests
#
add_executable(executor_unittests
        tests/main.cpp tests/executor_unittest.cpp)

set_target_properties(executor_unittests PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

target_include_directories(executor_unittests PRIVATE
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_SOURCE_DIR}/src"
        "${PROJECT_SOURCE_DIR}/tests/googletest"
        "${PROJECT_SOURCE_DIR}/tests/googletest/include")

add_dependencies(executor executorlib)


target_link_libraries(executor_unittests executorlib)

find_package(Threads REQUIRED)
target_link_libraries(executor_unittests ${CMAKE_THREAD_LIBS_INIT})