cmake_minimum_required(VERSION 3.17)
project(cpp_module_03_ex04)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(test_super_trap
        ClapTrap.hpp
        FragTrap.hpp
        NinjaTrap.hpp
        ScavTrap.hpp
        SuperTrap.hpp
        ClapTrap.cpp
        FragTrap.cpp
        main.cpp
        NinjaTrap.cpp
        ScavTrap.cpp
        SuperTrap.cpp)
