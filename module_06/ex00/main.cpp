#include <iostream>
#include "ExpresionConverter.hpp"

/*check_ignore*/

int main(int argc, char* argv[])
{
    double num;
	int flag;

    try
    {
        if (argc == 2)
        {
            num = ExpresionConverter::convert(argv[1], &flag);
            
            //std::cout << std::endl;
			if (!flag)
			{
            	if ((int)num <= 126 && (int)num >= 32)
            	    std::cout << "Char: " << static_cast<char>(num) << std::endl;
            	else
            	    std::cout << "Char: Non displayable" << std::endl;
				std::cout << "Int: " << static_cast<int>(num) << std::endl;
			}
			else
			{
				std::cout << "Char: impossible" << std::endl;
				std::cout << "Int: impossible" << std::endl;
			}
            std::cout << "Float: " << static_cast<float>(num) << 'f' << std::endl;
            std::cout << "Double: " << num << std::endl; 
            
        }
    }
    catch (...)
    {
    }

    return(0);
}
