cmake_minimum_required(VERSION 3.10)
project(task1)
add_subdirectory(./tests)

set(CMAKE_CXX_STANDARD 14)
add_library(TritSet__lib trit.cpp)
add_executable(task1 main.cpp)
target_link_libraries(task1 TritSet__lib)