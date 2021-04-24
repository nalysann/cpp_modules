#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Form.hpp"

class Bureaucrat {
  public:
    class GradeTooHighException : public std::exception {};
    class GradeTooLowException : public std::exception {};

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form& form) const;
    void executeForm(const Form& form) const;

    static const int MAX_GRADE = 1;
    static const int MIN_GRADE = 150;

  private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
