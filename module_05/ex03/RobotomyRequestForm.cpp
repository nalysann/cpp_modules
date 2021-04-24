#include <cstdlib>
#include <iostream>
#include <string>

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
        : Form("Robotomy Request Form",
               72,
               45,
               target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
        : Form(other.getName(),
               other.getSignGrade(),
               other.getExecuteGrade(),
               other.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::_action() const {
    std::cout << "* drrr ve ve ve ve ve drrr *" << std::endl;

    switch (rand() % 2) {
        case 0:
            std::cout << getTarget() << " has been robotomized successfully" << std::endl;
            break;
        case 1:
            std::cout << getTarget() << " robotomization failed" << std::endl;
            break;
        default:
            std::cout << "WTF am I doing here?" << std::endl;
            break;
    }
}
