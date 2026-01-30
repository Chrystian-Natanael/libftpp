cmake_minimum_required(VERSION 3.6)
project(tests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../includes)
include_directories(googletest/include)

add_subdirectory(googletest)
enable_testing()

set(TESTS_FOLDER my_tests)
file(GLOB_RECURSE TESTS_FILES "${TESTS_FOLDER}/*.cpp")
message(STATUS "Tests files: ${TESTS_FILES}")


set(PROJECT_SRC_FOLDER "../src")
file(GLOB_RECURSE PROJECT_SRC_FILES "${PROJECT_SRC_FOLDER}/*.cpp")
list(FILTER PROJECT_SRC_FILES EXCLUDE REGEX ".*main.cpp$")

add_executable(run_tests ${TESTS_FILES} ${PROJECT_SRC_FILES})
target_link_libraries(run_tests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)
