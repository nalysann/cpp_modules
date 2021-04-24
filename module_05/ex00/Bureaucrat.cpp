#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
        : _name(name) {
    if (grade < MAX_GRADE) {
        throw GradeTooHighException();
    } else if (grade > MIN_GRADE) {
        throw GradeTooLowException();
    }

    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
        : _name(other._name) {
    if (other._grade < MAX_GRADE) {
        throw GradeTooHighException();
    } else if (other._grade > MIN_GRADE) {
        throw GradeTooLowException();
    }

    _grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (other._grade < MAX_GRADE) {
        throw GradeTooHighException();
    } else if (other._grade > MIN_GRADE) {
        throw GradeTooLowException();
    }

    _grade = other._grade;

    return *this;
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
    return os << bureaucrat.getName() << ", bureaucrat grade "
              << bureaucrat.getGrade() << std::endl;
}
