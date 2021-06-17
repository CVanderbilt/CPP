#include <iostream>
#include "ExpresionConverter.hpp"

int main(int argc, char* argv[])
{
    double num;
    try
    {
        if (argc == 2)
        {
            num = ExpresionConverter::convert(argv[1]);
            
            std::cout << std::endl;
            if ((int)num <= 127 && (int)num >= 0)
                std::cout << "  Char: " << static_cast<char>(num) << std::endl;
            else
                std::cout << "  Char: Not possible" << std::endl;

            std::cout << "  Int: " << static_cast<int>(num) << std::endl;
            std::cout << "  Float: " << static_cast<float>(num) << 'f' << std::endl;
            std::cout << "  Double: " << num << std::endl << std::endl; 
            
        }
    }
    catch (...)
    {
    }

    return(0);
}
