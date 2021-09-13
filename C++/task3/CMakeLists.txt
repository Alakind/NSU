cmake_minimum_required(VERSION 3.5)
project(task3_battleship)

#
# library with common functions for tests and exe
#

add_library(battleship_game
        src/main.cpp
        src/battleship.cpp
        src/battleship.h
	src/optionparser.h)

set_target_properties(battleship_game PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

#
# project itself
#

add_executable(battleship
        src/main.cpp)

add_dependencies(battleship battleship_game)

set_target_properties(battleship PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

target_link_libraries(battleship battleship_game)

#
# unit tests
#
add_executable(battleship_unittests
        tests/main.cpp tests/battleship_unittest.cpp)

set_target_properties(battleship_unittests PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

target_include_directories(battleship_unittests PRIVATE
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_SOURCE_DIR}/src"
        "${PROJECT_SOURCE_DIR}/tests/googletest"
        "${PROJECT_SOURCE_DIR}/tests/googletest/include")

add_dependencies(battleship battleship_game)


target_link_libraries(battleship_unittests battleship_game)

find_package(Threads REQUIRED)
target_link_libraries(battleship_unittests ${CMAKE_THREAD_LIBS_INIT})