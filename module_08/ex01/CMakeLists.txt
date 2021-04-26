cmake_minimum_required(VERSION 3.17)
project(cpp_module_08_ex01)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(test_span
        span.hpp
        main.cpp
        span.cpp)
