#include <iostream>
#include "Array.hpp"

int main(void)
{
    Array<int> int_array;
    try
    {
        int_array[0] = 5;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Size was: " << int_array.size() << std::endl << std::endl;
    }

    Array<std::string> str_empty_array;
    Array<std::string> str_array(5);
    str_array[0] = "0_string";
    str_array[1] = "1_string";
    str_array[2] = "2_string";
    str_array[3] = "3_string";
    str_array[4] = "4_string";

    std::cout << "Size of empty: " << str_empty_array.size() << "\nSize of other: " << str_array.size() << std::endl;
    str_empty_array = str_array;
    std::cout << "Size of empty: " << str_empty_array.size() << "\nSize of other: " << str_array.size() << std::endl << std::endl;

    str_empty_array[2] = "MiddleOne";

    for (int i = 0; i < str_empty_array.size(); i++)
    {
        std::cout << str_empty_array[i] << std::endl;
        std::cout << str_array[i] << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Fin" << std::endl;
    return (0);
}