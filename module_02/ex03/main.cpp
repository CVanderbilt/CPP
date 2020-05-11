#include <iostream>
#include "Fixed.hpp"

Fixed    ft_eval_expr_rec(std::string::const_iterator &it, std::string &s);

int main(int argc, char *argv[])
{
    std::string s;
    std::string s2 = ")";
    std::string s3 = "(";
    std::string::const_iterator it;
    Fixed result;

    if (argc == 2){
        s = s3 + argv[1] + s2;
        it = s.cbegin();
        result = ft_eval_expr_rec(it, s);
        std::cout << "result: " << result << std::endl;
    }
    return (0);
}