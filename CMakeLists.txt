cmake_minimum_required(VERSION 3.24)
project(TestTask)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(
        TapeTest
        TapeTest.cc
)
target_link_libraries(
        TapeTest
        gtest_main
)
include(GoogleTest)
gtest_discover_tests(TapeTest)
add_executable(TestTask main.cpp Tape.h Tape.cpp Client.h Client.cpp MergeSorter.h MergeSorter.cpp)
