cmake_minimum_required(VERSION 3.17)
project(cpp_module_02_ex03)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(eval_expr
        eval_expr.hpp
        Fixed.hpp
        eval_expr.cpp
        Fixed.cpp)
