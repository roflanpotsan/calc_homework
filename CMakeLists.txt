cmake_minimum_required(VERSION 3.20)
project(calc_homework)

set(CMAKE_CXX_STANDARD 14)

add_executable(calc_homework main.cpp split_expression.cpp header.h extra_functions.cpp get_rpn.cpp calculate.cpp)
