cmake_minimum_required(VERSION 3.17)
project(cpp_module_01_ex06)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(violence
        HumanA.hpp
        HumanB.hpp
        Weapon.hpp
        HumanA.cpp
        HumanB.cpp
        main.cpp
        Weapon.cpp)
