#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    return os << "Bureaucrat " << bureaucrat.getName() << " (grade " << bureaucrat.getGrade() << ")";
}
