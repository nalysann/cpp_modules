cmake_minimum_required(VERSION 3.17)
project(cpp_module_05_ex05)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(test_central_bureaucracy
        Bureaucrat.hpp
        CentralBureaucracy.hpp
        Form.hpp
        Intern.hpp
        OfficeBlock.hpp
        MutantPigTerminationForm.hpp
        PresidentialPardonForm.hpp
        RobotomyRequestForm.hpp
        ShrubberyCreationForm.hpp
        Bureaucrat.cpp
        CentralBureaucracy.cpp
        Form.cpp
        Intern.cpp
        main.cpp
        MutantPigTerminationForm.cpp
        OfficeBlock.cpp
        PresidentialPardonForm.cpp
        RobotomyRequestForm.cpp
        ShrubberyCreationForm.cpp)
