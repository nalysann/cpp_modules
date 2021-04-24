cmake_minimum_required(VERSION 3.17)
project(cpp_module_05_ex02)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(test_forms
        Bureaucrat.hpp
        Form.hpp
        PresidentialPardonForm.hpp
        RobotomyRequestForm.hpp
        ShrubberyCreationForm.hpp
        Bureaucrat.cpp
        Form.cpp
        main.cpp
        PresidentialPardonForm.cpp
        RobotomyRequestForm.cpp
        ShrubberyCreationForm.cpp)
