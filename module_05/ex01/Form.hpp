#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
  public:
    class GradeTooHighException : public std::exception {};
    class GradeTooLowException : public std::exception {};
    class AlreadySignedException : public std::exception {};

    Form();
    Form(const std::string& name, int sign_grade, int execute_grade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);

    static const int MAX_GRADE = 1;
    static const int MIN_GRADE = 150;

  private:
    const std::string _name;
    bool _is_signed;
    const int _sign_grade;
    const int _execute_grade;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
