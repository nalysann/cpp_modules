cmake_minimum_required(VERSION 3.17)
project(cpp_module_04_ex01)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(test_fallout
        AlienAtomizer.hpp
        AWeapon.hpp
        Character.hpp
        Deathclaw.hpp
        Enemy.hpp
        PlasmaRifle.hpp
        PowerFist.hpp
        RadScorpion.hpp
        SuperMutant.hpp
        AlienAtomizer.cpp
        AWeapon.cpp
        Character.cpp
        Deathclaw.cpp
        Enemy.cpp
        main.cpp
        PlasmaRifle.cpp
        PowerFist.cpp
        RadScorpion.cpp
        SuperMutant.cpp)
