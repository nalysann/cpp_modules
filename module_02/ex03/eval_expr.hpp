#ifndef EVAL_EXPR_HPP
#define EVAL_EXPR_HPP

#include <string>

#include "Fixed.hpp"

void skip_spaces();
void terminate(const std::string& message);

Fixed eval();
Fixed eval_term();
Fixed eval_one();
Fixed eval_number();
Fixed eval_parentheses();

#endif
