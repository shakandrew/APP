cmake_minimum_required(VERSION 3.9)
project(first)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Ofast -pthread")

add_executable(first main.cpp src/Matrix.cpp include/Matrix.h tests/test_basic_multiplication.cpp tests/test_basic_multiplication.hpp)
