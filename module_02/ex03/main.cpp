#include <iostream>
#include "Fixed.hpp"

Fixed    ft_eval_expr_rec(std::string::const_iterator &it, std::string &s);
//std::string ft_check(char *str);
std::string ft_wrap_muldiv(char *str);
int ft_check_wrap(std::string& str, int i);

int main(int argc, char *argv[])
{
    std::string s;
    std::string::const_iterator it;
    Fixed result;

    if (argc == 2){
        try
        {
            
            s = ft_wrap_muldiv(argv[1]);
            //std::cout << argv[1] << std::endl;
            //std::cout << "Expresion reducida: >" << s << "<" << std::endl;
            it = s.cbegin();
            result = ft_eval_expr_rec(it, s);
            std::cout << "result: " << result << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}