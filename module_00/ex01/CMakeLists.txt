cmake_minimum_required(VERSION 3.17)
project(cpp_module_00_ex01)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(phonebook
        AddressBook.hpp
        Contact.hpp
        utils.hpp
        AddressBook.cpp
        Contact.cpp
        phonebook.cpp
        utils.cpp)
