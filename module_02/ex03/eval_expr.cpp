#include "Fixed.hpp"
#include <iostream>
#include <sstream>

#define ISOPSIGN(c) (c == '+' || c == '-' || c == '*' || c == '/')

int ft_skip_p(std::string& str, int i, bool direction)
{
    int d = direction ? 1 : -1;
    int n = d;
    i += d;
    while (n)
    {
        if (str[i] == ')')
            n --;
        if (str[i] == '(')
            n ++;
        i += d;
        if (i < 0){
            std::cout << "1" << std::endl;
            throw std::exception();
        }
    }
    return (i);
}

int ft_check_wrap(std::string& str, int i)
{
    std::string left = "(";
    std::string right = ")";
    bool r = false;
    bool l = false;
    int ri;
    int li;
    int aux = i;
    //std::cout << std::endl;
    //std::cout << str << std::endl; 
    while (--i >= 0 && str[i] && !l)
    {
        //std::cout << "      hacia izq: " << i << std::endl;
        if (str[i] == '(')
            l = true;
        else if (str[i] == ')')
            i = ft_skip_p(str, i, false);
        else if (str[i] == '+' || str[i] == '-')
            break ;
    }
    li = l ? i : i + 1;
    i = aux;
    while (str[++i] && !r)
    {
        //std::cout << "      hacia der: " << i << std::endl;
        if (str[i] == ')')
            r = true;
        else if (str[i] == '(')
            i = ft_skip_p(str, i, true);
        else if (str[i] == '+' || str[i] == '-')
            break ;
    }
    ri = r ? i + 1 : i;
    if (!r || !l)
    {
        //std::cout << "---" << std::endl;
        str.insert(li, left);
        //std::cout << "---"  << ri << std::endl; 
        str.insert(ri, right);
        //std::cout << "---" << std::endl;
        return (aux + 1);
    }
    return (aux);
}

std::string ft_wrap_muldiv(char *str)
{
    std::string ret = "";

    for (int i = 0; str[i]; i++)
        if (ISOPSIGN(str[i]) || str[i] == '(' || str[i] == ')' || isdigit(str[i]))
            ret.push_back(str[i]);
    ret = "(0+" + ret + ")";
    for (int i = 0; i < static_cast<int>(ret.length()); i++)
        if (ret[i] == '*' || ret[i] == '/')
            i = ft_check_wrap(ret, i);
    return (ret);
}

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
    bool op_used = false;

    //std::cout << "kk" << std::endl;
    op = '+';
    std::string::const_iterator it_end = s.cend();
    if (*it == '(')
        it++;
    while (it != it_end)
    {
        if (*it == '('){
            if (op_used){
                std::cout << "2" << std::endl;
                throw std::exception();
            }
            aux1 = ft_operate(aux1, ft_eval_expr_rec(it, s), op);
            op = '*';
            op_used = true;
        }
        else if (std::isdigit(*it)){
            if (op_used){
                std::cout << "3" << std::endl;
                throw std::exception();
            }
            aux1 = ft_operate(aux1, ft_atoi_fixed(it, s.cend()), op);
            op = '*';
            op_used = true;
        }
        else if (ISOPSIGN(*it)){
            if (op_used)
                op = *it;
            else
            {
                if (*it == '-')
                    op = op == '-' ? '+' : '-';
                else if (*it != '+'){
                    std::cout << "4" << std::endl;
                    throw std::exception();
                }
            }
            op_used = false; 
            it++;
        }
        else if (*it == ')'){
            if (!op_used){
                std::cout << "5" << std::endl;
                throw std::exception();
            }
            //std::cout << "Encuentra parentesis" << std::endl;
            it++;
            return (aux1);
        }
        else
            it++;
	}
    std::cout << "10" << std::endl;
    throw std::exception();
    return (0);
}