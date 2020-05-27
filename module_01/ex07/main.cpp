#include <iostream>
#include <fstream>
#include "Replace.hpp"

int main(int argc, char *argv[])
{
    if (argc == 4)
			Replace::ft_replace(argv[1], argv[2], argv[3]);
    else
        std::cout << "Wrong number of arguments" << std::endl;
    return (0);
}