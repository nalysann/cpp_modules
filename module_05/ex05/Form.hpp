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
    class SignedException : public std::exception {};
    class UnsignedException : public std::exception {};

    Form();
    Form(const std::string& name, int sign_grade, int execute_grade, const std::string& target);
    Form(const Form& other);
    Form& operator=(const Form& other);
    virtual ~Form();

    const std::string& getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    const std::string& getTarget() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const;

    static const int MAX_GRADE = 1;
    static const int MIN_GRADE = 150;
    static const size_t NUM_FORMS = 4;
    static const std::string FORM_NAMES[];

  protected:
    virtual void _action() const = 0;

  private:
    const std::string _name;
    bool _is_signed;
    const int _sign_grade;
    const int _execute_grade;
    const std::string _target;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
