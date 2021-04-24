#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    {
        Form f("A1", 25, 17);

        std::cout << "getName() test: " << f.getName() << std::endl;
        std::cout << "isSigned() test: " << f.isSigned() << std::endl;
        std::cout << "getSignGrade() test: " << f.getSignGrade() << std::endl;
        std::cout << "getExecuteGrade() test: " << f.getExecuteGrade() << std::endl;
    }

    {
        try {
            Form f("A1", Form::MAX_GRADE - 1, 42);
        } catch (std::exception&) {
            std::cout << "tried to create a form with the sign grade too high" << std::endl;
        }

        try {
            Form f("A1", Form::MIN_GRADE + 1, 42);
        } catch (std::exception&) {
            std::cout << "tried to create a form with the sign grade too low" << std::endl;
        }

        try {
            Form f("A1", 33, Form::MAX_GRADE - 1);
        } catch (std::exception&) {
            std::cout << "tried to create a form with the execute grade too high" << std::endl;
        }

        try {
            Form f("A1", 33, Form::MIN_GRADE + 1);
        } catch (std::exception&) {
            std::cout << "tried to create a form with the execute grade too low" << std::endl;
        }
    }

    {
        Bureaucrat b("John", Bureaucrat::MAX_GRADE);
        Form f("A1", 25, 17);
        Form g("A2", 10, 20);

        std::cout << "sign form via Form::beSigned" << std::endl;
        std::cout << f << std::endl;
        f.beSigned(b);
        std::cout << f << std::endl;

        std::cout << "sign form via Bureaucrat::signForm" << std::endl;
        std::cout << g << std::endl;
        b.signForm(g);
        std::cout << g << std::endl;

        std::cout << "try to sign the form that is already signed" << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }

    {
        Bureaucrat b("Bob", 25);
        Bureaucrat c("Chad", Bureaucrat::MAX_GRADE);
        Form f("A1", 11, 7);

        std::cout << f << std::endl << b << std::endl;
        b.signForm(f);
        std::cout << f << std::endl << c << std::endl;
        c.signForm(f);
        std::cout << f << std::endl;
    }
}
