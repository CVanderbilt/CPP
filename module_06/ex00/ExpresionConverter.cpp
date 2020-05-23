#include <iostream>
#include "ExpresionConverter.hpp"

const std::string ExpresionConverter::a_list[8] = {
    "-inf",
    "+inf",
    "inf",
    "nan",
    "-inff",
    "+inff",
    "inff",
    "nanf"
};

int ExpresionConverter::checkType(std::string& s)
{
    int type_id; //0 -> char, 1 -> int, 2 -> foat 3 -> double
    int double_float = *(s.end() - 1) == 'f' ? 1 : 2;

    /*for (int i = 0; i < 8; i++)
        if (s == ExpresionConverter::a_list[i])
            return (i / 4 == 0 ? 2 : 1);*/
    //std::cout << "No es ninguna de las expresiones" << std::endl;
    //if (s[0] != '-' || s[0] != '+' || !isdigit(s[0]))
    //    return (0);
    
    int digit_pos = s[0] != '-' && s[0] != '+' ? 1 : 0;

    type_id = 0;
    for (std::string::iterator it = s.begin() + digit_pos; it != s.end(); it++)
        if (*it == '.')
        {
            if (type_id != double_float)
                type_id = double_float;
            else
                throw (std::exception());
        }
    if (type_id == 0)
        return (type_id);
    
    return (double_float);

        
}

double ExpresionConverter::numConversion(const std::string& consts)
{
    //std::cout << "EXPRESION CONVERTER" << std::endl;
    double n;
    int type_id;

    std::string s = const_cast<char*>(consts.c_str());

    type_id = ExpresionConverter::checkType(s);

    //std::cout << "--------" << std::endl;
    if (isalpha(*(s.end() - 1)))
    {
        //std::cout << "          End in alfa: " << *(s.end() - 1) << std::endl;
        if (*(s.cend() - 1) == 'f')
            type_id = 1;
        else
            throw (std::exception());
    }
    else
        for (std::string::iterator it = s.begin(); it != s.end(); it++)
            if (*it == '.')
            {
                type_id = 2;
                break ;
            }

    n = atof (s.c_str());
    switch (type_id)
	{
	case 0:
        std::cout << "Int" << std::endl;
		return (static_cast<int>(n));
	case 1:
        std::cout << "Float" << std::endl;
		return (static_cast<float>(n));
	}
    std::cout << "Double" << std::endl;
    return (n);
}

double ExpresionConverter::asciiConversion(const std::string& s)
{
    if (s.length() != 1 )
        throw (std::exception());
    return (static_cast<double>(s[0]));
}

double ExpresionConverter::convert(const std::string& s)
{
    double num;
    //std::cout << "      Evaluating  " << s << " firstchar: " << s[0] << std::endl;

    for (int i = 0; i < 8; i++)
        if (s == ExpresionConverter::a_list[i]){
            std::cout << "Expresion" << std::endl;
            return (i / 4 == 0 ? atof (s.c_str()) : static_cast<float>(atof (s.c_str())));
        }

    if (!isdigit(s[0]) && s[0] != '-' && s[0] != '+')
            num = ExpresionConverter::asciiConversion(s);
    else
            num = ExpresionConverter::numConversion(s);
    return num;
}