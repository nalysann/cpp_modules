#include <cctype>
#include <iostream>
#include <sstream>

#include "Fixed.hpp"
#include "eval_expr.hpp"

std::string expr;
size_t pos = 0;
const char EOT = '\0';

void skip_spaces() {
    while (isspace(expr[pos])) {
        ++pos;
    }
}

void terminate(const std::string& message) {
    std::cerr << "eval_expr: " << message << std::endl;
    exit(1);
}

Fixed eval_parentheses() {
    ++pos;
    skip_spaces();
    Fixed res = eval();
    if (expr[pos] != ')') {
        terminate("Missing ')'");
    }
    ++pos;
    skip_spaces();
    return res;
}

Fixed eval_number() {
    size_t beg = pos;
    while (expr[pos] == '+' || expr[pos] == '-') {
        ++pos;
    }
    if (!(isdigit(expr[pos]) || expr[pos] == '.')) {
        terminate("Invalid number");
    }

    pos = expr.find_first_not_of("0123456789.", pos);
    std::istringstream iss(expr.substr(beg, pos - beg));
    skip_spaces();
    if (iss.str().find('.') != std::string::npos) {
        float f;
        iss >> f;
        if (!iss) {
            terminate("Invalid float number");
        }
        return Fixed(f);
    } else {
        int i;
        iss >> i;
        if (!iss) {
            terminate("Invalid integer number");
        }
        return Fixed(i);
    }
}

Fixed eval_one() {
    if (expr[pos] == '(') {
        return eval_parentheses();
    } else {
        return eval_number();
    }
}

Fixed eval_term() {
    Fixed res = eval_one();

    while (expr[pos] == '*' || expr[pos] == '/') {
        char op = expr[pos];
        ++pos;
        skip_spaces();
        Fixed rhs = eval_one();
        if (op == '*') {
            res *= rhs;
        } else {
            res /= rhs;
        }
    }

    return res;
}

Fixed eval() {
    Fixed res = eval_term();

    while (expr[pos] == '+' || expr[pos] == '-') {
        char op = expr[pos];
        ++pos;
        skip_spaces();
        Fixed rhs = eval_term();
        if (op == '+') {
            res += rhs;
        } else {
            res -= rhs;
        }
    }

    if (!(expr[pos] == ')' || expr[pos] == EOT)) {
        terminate("Invalid expression");
    }

    return res;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./eval_expr expression" << std::endl
                  << "    - expression - mathematical expression to evaluate" << std::endl
                  << "Supported operations: +, -, *, /" << std::endl;
        return 1;
    }

    expr = argv[1];
    expr.push_back(EOT);

    skip_spaces();
    if (expr[pos] == EOT) {
        terminate("Empty expression");
    }

    std::cout << eval() << std::endl;
}
