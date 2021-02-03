#include <cctype>
#include <iostream>
#include <sstream>

#include "Fixed.hpp"
#include "utils.hpp"

//bool			isFloat(std::string s)
//{
//    int		i = 0;
//
//    while (std::isdigit(s[i]))
//        i++;
//    return (s[i] == '.');
//}
//
//bool			checkFrontOperator(std::string &expr, int &index)
//{
//    if (!index)
//        return (false);
//
//    int		i = index - 1;
//
//    while (i && std::isspace(expr[i]))
//        i--;
//    if (std::isdigit(expr[i]))
//        while (((i - 1) >= 0) && (std::isdigit(expr[i - 1]) || (expr[i - 1] == '.')))
//            i--;
//    else if (expr[i] == ')')
//    {
//        for (int parenthesisCount = 1; parenthesisCount;)
//        {
//            if (--i < 0)
//                return (false);
//            else if (expr[i] == ')')
//                parenthesisCount++;
//            else if (expr[i] == '(')
//                parenthesisCount--;
//        }
//    }
//    else
//        return (false);
//    if (expr[index] == '*' || expr[index] == '/')
//    {
//        expr.insert(expr.begin() + i, '(');
//        index++;
//    }
//    return (true);
//}
//
//bool			checkBackOperator(std::string &expr, int &index)
//{
//    int		i = index + 1;
//
//    while (std::isspace(expr[i]))
//        i++;
//    if (std::isdigit(expr[i]))
//        while (expr[i] && (std::isdigit(expr[i]) || expr[i] == '.'))
//            i++;
//    else if (expr[i] == '(')
//    {
//        for (int parenthesisCount = 1; parenthesisCount;)
//        {
//            if (!expr[++i])
//                return (false);
//            if (expr[i] == '(')
//                parenthesisCount++;
//            else if (expr[i] == ')')
//                parenthesisCount--;
//        }
//    }
//    else
//        return (false);
//    if (expr[index] == '*' || expr[index] == '/')
//        expr.insert(expr.begin() + i, ')');
//    return (true);
//}
//
//inline bool		checkOperator(std::string &expr, int &i)
//{
//    return (checkFrontOperator(expr, i) && checkBackOperator(expr, i));
//}
//
//bool			checkExpr(std::string &expr, int i = 0, bool checkParenthesis = false)
//{
//    int		parenthesisCount = 1;
//    int		createdParenthesis = 0;
//
//    if (expr.find_first_not_of(" \t\n\v\f\r()+-*/.0123456789") != std::string::npos)
//        return (false);
//    while (expr[i])
//    {
//        while (std::isspace(expr[i]))
//            i++;
//        if (std::isdigit(expr[i]))
//        {
//            while (std::isdigit(expr[i]))
//                i++;
//            if (expr[i] == '.')
//            {
//                do
//                    i++;
//                while (std::isdigit(expr[i]));
//                if (expr[i] == '.')
//                    return (false);
//            }
//            while (expr[i] && (std::string("+-*/").find_first_of(expr[i]) == std::string::npos))
//            {
//                if (std::isdigit(expr[i]) || (expr[i] == '('))
//                    return (false);
//                i++;
//            }
//            continue ;
//        }
//        else if (expr[i] == '(')
//        {
//            if (!checkExpr(expr, i + 1, true))
//                return (false);
//            while (parenthesisCount)
//            {
//                if (!expr[++i])
//                    return (false);
//                else if (expr[i] == '(')
//                    parenthesisCount++;
//                else if (expr[i] == ')')
//                    parenthesisCount--;
//            }
//        }
//        else if (std::string("+-*/").find_first_of(expr[i]) != std::string::npos)
//        {
//            if ((expr[i] == '*') || (expr[i] == '/'))
//                createdParenthesis++;
//            if (!checkOperator(expr, i))
//                return (false);
//        }
//        else if (expr[i] == '.')
//            return (false);
//        else if (expr[i] == ')')
//        {
//            if (createdParenthesis)
//            {
//                createdParenthesis--;
//                i++;
//                continue ;
//            }
//            if (checkParenthesis)
//                return (true);
//            return (false);
//        }
//        i++;
//    }
//    return (true);
//}
//
//Fixed			atofixed(std::string s)
//{
//    Fixed	nb;
//
//    if (isFloat(s))
//        nb = Fixed((float)std::atof(s.c_str()));
//    else
//        nb = Fixed(std::atoi(s.c_str()));
//    return (nb);
//}

bool isoperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Fixed eval(const std::string& expr, size_t pos = 0) {
    Fixed result;
    Operator op = NOP;

    while (pos != expr.size()) {
        while (pos != expr.size() && isspace(expr[pos])) {  // skip whitespace
            ++pos;
        }

        if (isdigit(expr[pos])) {  // parse number
            if (op == ADD) {
                result += Fixed(expr, pos);
            } else if (op == SUB) {
                result -= Fixed(expr, pos);
            } else if (op == MUL) {
                result *= Fixed(expr, pos);
            } else if (op == DIV) {
                result /= Fixed(expr, pos);
            } else {
                result = Fixed(expr, pos);
            }

            // skip parsed number
            if (pos != expr.size() && (expr[pos] == '+' || expr[pos] == '-')) {
                ++pos;
            }

            if (pos != expr.size() && !(isdigit(expr[pos]) || expr[pos] == '.')) {
                std::cout << "eval_expr: Invalid expression" << std::endl;
                exit(EXIT_FAILURE);
            }

            while (pos != expr.size() && isdigit(expr[pos])) {
                ++pos;
            }

            if (pos != expr.size() && expr[pos] == '.') {
                ++pos;
            }

            while (pos != expr.size() && isdigit(expr[pos])) {
                ++pos;
            }

            // reset operator
            op = NOP;
        } else if (expr[pos] == '(') {  // parse parenthesis
            if (op == ADD) {
                result += eval(expr, pos + 1);
            } else if (op == SUB) {
                result -= eval(expr, pos + 1);
            } else if (op == MUL) {
                result *= eval(expr, pos + 1);
            } else if (op == DIV) {
                result /= eval(expr, pos + 1);
            } else {
                result = eval(expr, pos + 1);
            }

            // skip parsed expression in parenthesis
            ++pos;
            for (int par_count = 1; par_count > 0; ++pos) {
                if (pos == expr.size()) {
                    std::cout << "eval_expr: Invalid expression" << std::endl;
                    exit(EXIT_FAILURE);
                } else if (expr[pos] == '(') {
                    ++par_count;
                } else if (expr[pos] == ')') {
                    --par_count;
                }
            }
        } else if (expr[pos] == ')') {  // parse parenthesis
            return result;
        } else if (isoperator(expr[pos])) {  // parse operator
            if (op != NOP) {
                std::cout << "eval_expr: Invalid expression" << std::endl;
                exit(EXIT_FAILURE);
            }

            op = static_cast<Operator>(std::string("+-*/").find(expr[pos]) + 1);
        } else {  // invalid character
            std::cout << "eval_expr: Invalid expression" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    // hanging operator
    if (op != NOP) {
        std::cout << "eval_expr: Invalid expression" << std::endl;
        exit(EXIT_FAILURE);
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "usage: ./eval_expr expression" << std::endl
                  << "    - expression - mathematical expression to evaluate" << std::endl
                  << "Supported operations: +, -, *, /." << std::endl;
        return 1;
    }

    const std::string expr(argv[1]);

    if (expr.empty()) {
        std::cout << "eval_expr: Empty expression" << std::endl;
    }

    std::cout << eval(argv[1]) << std::endl;
}

//$> clang++ -Wall -Wextra -Werror -o eval_expr Fixed.class.cpp {your files}
//$> ./eval_expr "( 18.18 + 3.03 ) * 2"
//42.4219 $>
