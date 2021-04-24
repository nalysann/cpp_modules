#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <stdexcept>
#include <string>

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
  public:
    class ShrubberyCreationException : public std::exception {};

    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

  protected:
    void _action() const;

  private:
    static const std::string _ascii_tree;

    const std::string _filename;
};

#endif
