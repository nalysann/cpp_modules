#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat cheems("Cheems", Bureaucrat::MIN_GRADE);
    Bureaucrat swole("Swole", Bureaucrat::MAX_GRADE);

    std::cout << cheems << std::endl;
    std::cout << swole << std::endl;

    Form* ppf = new PresidentialPardonForm("Peppa");
    Form* rrf = new RobotomyRequestForm("Chad");
    Form* scf = new ShrubberyCreationForm("Pentagon");
    Form* not_signed = new RobotomyRequestForm("Jim");
    Form* denied = new ShrubberyCreationForm("USA");

    std::cout << *ppf << std::endl;
    std::cout << *rrf << std::endl;
    std::cout << *scf << std::endl;

    cheems.signForm(*ppf);
    cheems.signForm(*rrf);
    cheems.signForm(*scf);
    swole.signForm(*ppf);
    swole.signForm(*rrf);
    swole.signForm(*scf);

    std::cout << *not_signed << std::endl;

    cheems.executeForm(*not_signed);
    swole.executeForm(*not_signed);

    cheems.executeForm(*ppf);
    cheems.executeForm(*rrf);
    cheems.executeForm(*scf);
    swole.executeForm(*ppf);
    swole.executeForm(*rrf);
    swole.executeForm(*rrf);
    swole.executeForm(*rrf);
    swole.executeForm(*rrf);
    swole.executeForm(*scf);

    try {
        swole.signForm(*denied);
        swole.executeForm(*denied);
    } catch (ShrubberyCreationForm::ShrubberyCreationException&) {
        std::cout << "Unexpected shrubbery creation failure" << std::endl;
    }

    delete ppf;
    delete rrf;
    delete scf;
    delete not_signed;
    delete denied;
}
