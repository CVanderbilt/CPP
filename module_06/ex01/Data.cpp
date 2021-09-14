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

	data->n = *reinterpret_cast<int*>(raw);

	int i = 3;
	while (chrraw[++i])
		data->s1 += chrraw[i];
	while (chrraw[++i])
		data->s2 += chrraw[i];

    return (data);
}

uintptr_t serialize(Data *ptr)
{
	int l1 = ptr->s1.length();
	int l2 = ptr->s2.length();
    char* arr = new char[6 + l1 + l2];
	
	//int n;

	*reinterpret_cast<int*>(arr) = ptr->n;
	int i = -1;
	int j = -1;
	while (++i < l1)
		arr[4 + i] = ptr->s1.c_str()[i];
	arr[4 + i++] = 0;
	while (++j < l2)
		arr[4 + i + j] = ptr->s2.c_str()[j];
	arr[4 + i + j] = 0;

	std::cout << "Serialized:" << std::endl;
	std::cout << "int: " << ptr->n << std::endl;
	std::cout << "str1: " << ptr->s1 << std::endl;
	std::cout << "str2: " << ptr->s2 << std::endl;
	
    return (reinterpret_cast<uintptr_t>(arr));
}
