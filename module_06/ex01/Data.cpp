#include <iostream>
#include "Data.hpp"
#include <unistd.h>

/*check_ignore*/

std::string alfa_num_str = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int alfa_num_size = alfa_num_str.size();

Data* deserialize(uintptr_t raw)
{
    Data* data = new Data;
    char* chrraw = reinterpret_cast<char*>(raw);

    data->s1 = "";
    data->s2 = "";

    for (int i = 0; i < 8; i++)
    {
        data->s1.push_back(chrraw[i]);
        data->s2.push_back(chrraw[19 - i]);
    }
    data->n = *(reinterpret_cast<int*>(chrraw + 8));

    return (data);
}

uintptr_t serialize(void)
{
    char* arr = new char[20];
	std::string s1;
	std::string s2;
	int n;

	n = static_cast<int>(rand());
    int *int_ptr = reinterpret_cast<int*>(arr + 8);
    *int_ptr = n;
    for (int i = 0; i < 7; i++)
    {
		char c;
		
		c = alfa_num_str[rand() % alfa_num_size];
        arr[i] = c;
		s1 += c;
		c = alfa_num_str[rand() % alfa_num_size];
        arr[18 - i] = c;
		s2 += c;
    }

    arr[7] = 0;
    arr[19] = 0;

	std::cout << "Serialized:" << std::endl;
	std::cout << "str1: " << s1 << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "str2: " << s2 << std::endl;
	
    return (reinterpret_cast<uintptr_t>(arr));
}
