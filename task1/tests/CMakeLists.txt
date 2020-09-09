project(tests)

add_subdirectory(./googletest-master)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run test_task1.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)