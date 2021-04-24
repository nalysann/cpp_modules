#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string& name, int sign_grade, int execute_grade, const std::string& target)
        : _name(name)
        , _is_signed(false)
        , _sign_grade(sign_grade)
        , _execute_grade(execute_grade)
        , _target(target) {
    if (_sign_grade < MAX_GRADE || _execute_grade < MAX_GRADE) {
        throw GradeTooHighException();
    } else if (_sign_grade > MIN_GRADE || _execute_grade > MIN_GRADE) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other)
        : _name(other._name)
        , _is_signed(other._is_signed)
        , _sign_grade(other._sign_grade)
        , _execute_grade(other._execute_grade)
        , _target(other._target) {
    if (_sign_grade < MAX_GRADE || _execute_grade < MAX_GRADE) {
        throw GradeTooHighException();
    } else if (_sign_grade > MIN_GRADE || _execute_grade > MIN_GRADE) {
        throw GradeTooLowException();
    }
}

Form::~Form() {}

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _is_signed;
}

int Form::getSignGrade() const {
    return _sign_grade;
}

int Form::getExecuteGrade() const {
    return _execute_grade;
}

const std::string& Form::getTarget() const {
    return _target;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (_is_signed) {
        throw AlreadySignedException();
    } else if (bureaucrat.getGrade() > _sign_grade) {
        throw GradeTooLowException();
    }

    _is_signed = true;
}

void Form::execute(const Bureaucrat& executor) const {
    if (!_is_signed) {
        throw NotSignedException();
    } else if (executor.getGrade() > _execute_grade) {
        throw GradeTooLowException();
    }

    _action();
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    return os << "Form " << form.getName()
              << ", sign grade " << form.getSignGrade()
              << ", execute grade " << form.getExecuteGrade()
              << ", is " << (form.isSigned() ? "signed" : "not signed");
}