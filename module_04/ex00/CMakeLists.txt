cmake_minimum_required(VERSION 3.17)
project(cpp_module_04_ex00)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(test_poly
        Peon.hpp
        Sorcerer.hpp
        Victim.hpp
        Warrior.hpp
        main.cpp
        Peon.cpp
        Sorcerer.cpp
        Victim.cpp
        Warrior.cpp)
