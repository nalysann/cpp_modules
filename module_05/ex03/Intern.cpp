#include <iostream>
#include <string>

#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) {
    return *this;
}

Intern::~Intern() {}

Form* Intern::makeForm(const std::string& name, const std::string& target) const {
    static const std::string form_names[] = {
            "presidential pardon",
            "robotomy request",
            "shrubbery creation",
    };

    static const Intern::_makeConcreteForm form_makers[] = {
            &Intern::_makePresidentialPardonForm,
            &Intern::_makeRobotomyRequestForm,
            &Intern::_makeShrubberyCreationForm,
    };

    for (size_t i = 0; i < NUM_FORMS; ++i) {
        if (name == form_names[i]) {
            Form* new_form = (this->*form_makers[i])(target);
            std::cout << "Intern creates " << new_form->getName() << std::endl;
            return new_form;
        }
    }

    std::cout << "Intern can't create \"" << name << "\" form" << std::endl;

    return NULL;
}

Form* Intern::_makePresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

Form* Intern::_makeRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

Form* Intern::_makeShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}
