cmake_minimum_required(VERSION 3.1)
project(color)

enable_testing()
find_package(GTest REQUIRED)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)

add_executable(
    unit_test
    test/hsl.cpp
    test/hsv.cpp
    test/rgb.cpp)
target_include_directories(
    unit_test PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include/
    ${GTEST_INCLUDE_DIRS})
target_link_libraries(
    unit_test
    ${GTEST_BOTH_LIBRARIES})
