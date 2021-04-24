#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
  public:
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();

    Form* makeForm(const std::string& name, const std::string& target) const;

  private:
    typedef Form* (Intern::*_makeConcreteForm)(const std::string&) const;

    static const size_t NUM_FORMS = 3;

    Form* _makePresidentialPardonForm(const std::string& target) const;
    Form* _makeRobotomyRequestForm(const std::string& target) const;
    Form* _makeShrubberyCreationForm(const std::string& target) const;
};

#endif
