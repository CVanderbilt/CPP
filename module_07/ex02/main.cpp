#include <iostream>
#include "Array.hpp"
#define MAX_VAL 750

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

	std::cout << "Default initialization" << std::endl;
	for (int i = 0; i < str_array.size(); i++)
		std::cout << "|" << str_array[i] << "|";
	std::cout << std::endl;

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

    Array<int> numbers(MAX_VAL);
	
	std::cout << "Default initialization" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "|" << numbers[i] << "|";
	std::cout << std::endl;

    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		std::cout << "COPY TEST:" << std::endl;
		tmp[2] = 123321;
		for (int i = 0; i < 5; i++)
		{
			std::cout << "(" << tmp[i] << ", " << test[i] << ")" << std::endl;
		}
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;//
    return 0;
}