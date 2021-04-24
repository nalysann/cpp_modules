#include <iostream>

#include "Bureaucrat.hpp"

int	main() {
    {
        Bureaucrat b("John", 42);

        std::cout << "getName() test: " << b.getName() << std::endl;
        std::cout << "getGrade() test: " << b.getGrade() << std::endl;

        std::cout << "before incrementGrade(): " << b.getGrade() << std::endl;
        b.incrementGrade();
        std::cout << "after incrementGrade(): " << b.getGrade() << std::endl;

        std::cout << "before decrementGrade(): " << b.getGrade() << std::endl;
        b.decrementGrade();
        std::cout << "after decrementGrade(): " << b.getGrade() << std::endl;

        std::cout << b << std::endl;
    }

    {
        try {
            Bureaucrat b("John", Bureaucrat::MAX_GRADE - 1);
        } catch (Bureaucrat::GradeTooHighException&) {
            std::cout << "tried to create a bureaucrat with the grade too high" << std::endl;
        }

        try {
            Bureaucrat b("John", Bureaucrat::MIN_GRADE + 1);
        } catch (Bureaucrat::GradeTooLowException&) {
            std::cout << "tried to create a bureaucrat with the grade too low" << std::endl;
        }
    }

    {
        try {
            Bureaucrat b("John", Bureaucrat::MAX_GRADE);
            b.incrementGrade();
        } catch (Bureaucrat::GradeTooHighException&) {
            std::cout << "tried to increment the grade over the max grade" << std::endl;
        }

        try {
            Bureaucrat b("John", Bureaucrat::MIN_GRADE);
            b.decrementGrade();
        } catch (Bureaucrat::GradeTooLowException&) {
            std::cout << "tried to decrement the grade over the min grade" << std::endl;
        }
    }
}
