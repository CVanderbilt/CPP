#include "Fixed.hpp"
#include <iostream>
#include <sstream>

#define ISOPSIGN(c) (c == '+' || c == '-' || c == '*' || c == '/')

Fixed   ft_error()
{
    std::cout << "Wrong format" << std::endl;
    return (0);
}

Fixed   ft_atoi_fixed(std::string::const_iterator &it, const std::string::const_iterator &end)
{

    std::stringstream ss;
    float f;

    std::string tmp(it, end);
    ss << tmp;
    ss >> f;

    Fixed ret(f);

    while (std::isdigit(*it))
        it++;
    if (*it != '.')
        return (ret);
    it++;
    while (std::isdigit(*it))
        it++;
    return (ret);
}

Fixed   ft_operate(Fixed fx1, Fixed fx2, char const op)
{
    Fixed ret;

    switch (op)
    {
        case '+':
            ret = (fx1 + fx2);
            break ;
        case '-':
            ret = (fx1 - fx2);
            break ;
        case '*':
            ret = (fx1 * fx2);
            break ;
        case '/':
            ret = (fx1 / fx2);
            break ;
         default:
            ret = ft_error();
    }
    return (ret);
}

Fixed    ft_eval_expr_rec(std::string::const_iterator &it, std::string &s)
{
    Fixed aux1, aux2, aux3;
    char op;

    op = '+';
    std::string::const_iterator it_end = s.cend();
    if (*it == '(')
        it++;
    while (it != it_end)
    {
        if (*it == '('){
            aux1 = ft_operate(aux1, ft_eval_expr_rec(it, s), op);
            op = '*';
        }
        else if (std::isdigit(*it)){
            aux1 = ft_operate(aux1, ft_atoi_fixed(it, s.cend()), op);
            op = '*';
        }
        else if (ISOPSIGN(*it)){
            op = *it;
            it++;
        }
        else if (*it == ')'){
            it++;
            return (aux1);
        }
        else
            it++;
	}
    std::cout << "syntax error: " << aux1 << std::endl;
    return (aux1);
}