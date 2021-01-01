cmake_minimum_required(VERSION 3.1)
project(color)

enable_testing()
find_package(GTest REQUIRED)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(
    unit_test
    ${CMAKE_CURRENT_LIST_DIR}/test/convert_to_hsl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/test/convert_to_hsv.cpp
    ${CMAKE_CURRENT_LIST_DIR}/test/convert_to_rgb.cpp
    ${CMAKE_CURRENT_LIST_DIR}/test/hsl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/test/hsv.cpp
    ${CMAKE_CURRENT_LIST_DIR}/test/rgb.cpp)
target_include_directories(
    unit_test PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include/
    ${GTEST_INCLUDE_DIRS})
target_link_libraries(
    unit_test
    ${GTEST_BOTH_LIBRARIES})
