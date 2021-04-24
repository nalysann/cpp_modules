#include <iostream>
#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
        : Form("PresidentialPardonForm",
               25,
               5,
               target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
        : Form(other.getName(),
               other.getSignGrade(),
               other.getExecuteGrade(),
               other.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::_action() const {
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
