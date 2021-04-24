#include <iostream>
#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
        : _name(name)
        , _grade(grade) {
    if (_grade < MAX_GRADE) {
        throw GradeTooHighException();
    } else if (_grade > MIN_GRADE) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
        : _name(other._name)
        , _grade(other._grade) {
    if (_grade < MAX_GRADE) {
        throw GradeTooHighException();
    } else if (_grade > MIN_GRADE) {
        throw GradeTooLowException();
    }
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade == MAX_GRADE) {
        throw GradeTooHighException();
    }

    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade == MIN_GRADE) {
        throw GradeTooLowException();
    }

    ++_grade;
}

void Bureaucrat::signForm(Form& form) const {
    if (form.isSigned()) {
        std::cout << _name << " cannot sign " << form.getName()
                  << " because it's already signed" << std::endl;
        return;
    }

    try {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    } catch (std::exception&) {
        std::cout << _name << " cannot sign " << form.getName() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
