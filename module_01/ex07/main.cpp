#include <iostream>
#include <fstream>
#include "Replace.hpp"

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        try{
			Replace::ft_replace(argv[1], argv[2], argv[3]);
        }
		catch(char const *e){
			std::cerr << "ft_replace: error: " << e << std::endl;
        }
    }
    else
        std::cout << "Wrong number of arguments" << std::endl;
    return (0);
}