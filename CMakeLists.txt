cmake_minimum_required(VERSION 3.20)
project(dynamic_prog)

set(CMAKE_CXX_STANDARD 20)

add_executable(dynamic_prog main.cpp src/triangle.cpp src/triangle.h)
