#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cato9tails.hpp"

void Cato9Tails::cat(const std::string& filename)
{
    std::ostringstream contents;
    std::ifstream in(filename, std::ios::in | std::ios::binary);

    if (!in.is_open() || !in.good())
    std::cout << "cato9tails: " << filename << ": " << std::strerror(errno) << std::endl;
    else
    {
        contents << in.rdbuf();
        in.close();
        std::cout << contents.str();
        return ;
    }
}

void Cato9Tails::cat(void)
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << line << std::endl;
    }
}