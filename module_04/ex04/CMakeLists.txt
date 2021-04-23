cmake_minimum_required(VERSION 3.17)
project(cpp_module_04_ex04)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(test_mining
        Asteroid.hpp
        Comet.hpp
        DeepCoreMiner.hpp
        IAsteroid.hpp
        IMiningLaser.hpp
        MiningBarge.hpp
        StripMiner.hpp
        Asteroid.cpp
        Comet.cpp
        DeepCoreMiner.cpp
        main.cpp
        MiningBarge.cpp
        StripMiner.cpp)
