#ifndef MUTANT_PIG_TERMINATION_FORM_HPP
#define MUTANT_PIG_TERMINATION_FORM_HPP

#include <string>

#include "Form.hpp"

class MutantPigTerminationForm : public Form {
  public:
    MutantPigTerminationForm();
    explicit MutantPigTerminationForm(const std::string& target);
    MutantPigTerminationForm(const MutantPigTerminationForm& other);
    MutantPigTerminationForm& operator=(const MutantPigTerminationForm& other);
    ~MutantPigTerminationForm();

  protected:
    void _action() const;
};

#endif
