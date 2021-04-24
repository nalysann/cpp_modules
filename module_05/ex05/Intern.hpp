#ifndef INTERN_HPP
#define INTERN_HPP

#include <stdexcept>
#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
  public:
    class FormNotFoundException : std::exception {};

    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();

    Form* makeForm(const std::string& name, const std::string& target) const;

  private:
    typedef Form* (Intern::*_makeConcreteForm)(const std::string&) const;

    static const size_t NUM_FORMS = 4;

    Form* _makeMutantPigTerminationForm(const std::string& target) const;
    Form* _makePresidentialPardonForm(const std::string& target) const;
    Form* _makeRobotomyRequestForm(const std::string& target) const;
    Form* _makeShrubberyCreationForm(const std::string& target) const;
};

#endif
