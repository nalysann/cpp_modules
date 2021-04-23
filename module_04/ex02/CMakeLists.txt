cmake_minimum_required(VERSION 3.17)
project(cpp_module_04_ex02)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(test_warhammer
        AssaultTerminator.hpp
        ISpaceMarine.hpp
        ISquad.hpp
        Squad.hpp
        TacticalMarine.hpp
        AssaultTerminator.cpp
        main.cpp
        Squad.cpp
        TacticalMarine.cpp)
