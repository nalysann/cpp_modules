#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main() {
    Bureaucrat swole("Swole", Bureaucrat::MAX_GRADE);

    std::cout << swole << std::endl;

    Intern noname;

    Form* ppf = noname.makeForm("presidential pardon", "Peppa");
    Form* rrf = noname.makeForm("robotomy request", "Bender");
    Form* scf = noname.makeForm("shrubbery creation", "Pentagon");

    swole.signForm(*ppf);
    swole.signForm(*rrf);
    swole.signForm(*scf);

    swole.executeForm(*ppf);
    swole.executeForm(*rrf);
    swole.executeForm(*scf);

    Form* bad_form = noname.makeForm("total extermination", "Humanity");

    if (bad_form) {
        std::cout << "You suck at programming..." << std::endl;
    }

    delete ppf;
    delete rrf;
    delete scf;
}
