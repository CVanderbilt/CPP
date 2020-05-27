#include "Replace.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>

std::string Replace::get_file_contents(const std::string filename)
{
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (!in.is_open() || !in.good())
        throw (std::strerror(errno));
        //std::cout << "replace: " << filename << ": " << std::strerror(errno) << std::endl;
    
    std::ostringstream contents;
    contents << in.rdbuf();
    in.close();
    return (contents.str());
}

void Replace::ft_replace
    (std::string filename, std::string to_find, std::string replacement)
{
    size_t i, len, last;
    std::string str;
    if (to_find.empty() || replacement.empty() || filename.empty())
        std::cerr << "ft_replace error: empty strings" << std::endl;
    else
        try{
            std::ofstream myFile(filename + ".replace", std::ios::trunc);
            str = get_file_contents(filename);
            len = to_find.length();
            last = 0;
            i = str.find(to_find);
            while (i != std::string::npos)
            {
                myFile << str.substr(last, i - last) << replacement;
                last = i + len;
                i = str.find(to_find, last);
            }
            myFile << str.substr(last, i);
            myFile.close();
        }
        catch (...){
            std::cerr << "ft_replace error: file handling" << std::endl;
        }
}