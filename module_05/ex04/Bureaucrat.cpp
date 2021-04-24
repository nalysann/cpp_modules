#include <iostream>
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
    try {
        form.beSigned(*this);
        std::cout << *this << " signed " << form << std::endl;
    } catch (Form::SignedException&) {
        std::cout << *this << " can't sign " << form
                  << " because it's already signed" << std::endl;
        throw SigningException();
    } catch (Form::GradeTooLowException&) {
        std::cout << *this << " can't sign " << form
                  << " because his grade is too low" << std::endl;
        throw SigningException();
    }
}

void Bureaucrat::executeForm(const Form& form) const {
    try {
        form.execute(*this);
        std::cout << *this << " executed " << form << std::endl;
    } catch (Form::UnsignedException&) {
        std::cout << *this << " can't execute " << form
                  << " because it's unsigned" << std::endl;
        throw ExecutionException();
    } catch (Form::GradeTooLowException&) {
        std::cout << *this << " can't execute " << form
                  << " because his grade is too low" << std::endl;
        throw ExecutionException();
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    return os << "Bureaucrat " << bureaucrat.getName() << " (grade " << bureaucrat.getGrade() << ")";
}
