cmake_minimum_required(VERSION 3.9)
project(first)

set(CMAKE_CXX_STANDARD 11)
add_definitions("-Ofast")

add_executable(first main.cpp src/Matrix.cpp include/Matrix.h tests/test_basic_multiplication.cpp tests/test_basic_multiplication.hpp)
