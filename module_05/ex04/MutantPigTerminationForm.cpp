#include <iostream>
#include <string>

#include "Form.hpp"
#include "MutantPigTerminationForm.hpp"

MutantPigTerminationForm::MutantPigTerminationForm(const std::string& target)
        : Form("Mutant Pig Termination Form",
               130,
               50,
               target) {}

MutantPigTerminationForm::MutantPigTerminationForm(const MutantPigTerminationForm& other)
        : Form(other.getName(),
               other.getSignGrade(),
               other.getExecuteGrade(),
               other.getTarget()) {}

MutantPigTerminationForm::~MutantPigTerminationForm() {}

void MutantPigTerminationForm::_action() const {
    std::cout << "That'll do, " << getTarget() << ". That'll do..." << std::endl;
}
