#include <iostream>
#include "Data.hpp"

std::string alfa_num_str = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int alfa_num_size = alfa_num_str.size();

Data* deserialize(void* raw)
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

void* serialize(void)
{
    char* arr = new char[20];
    
    int *int_ptr = reinterpret_cast<int*>(arr + 8);
    *int_ptr = static_cast<int>(rand());

    for (int i = 0; i < 7; i++)
    {
        arr[i] = alfa_num_str[rand() % alfa_num_size];
        arr[18 - i] = alfa_num_str[rand() % alfa_num_size];
    }

    arr[7] = 0;
    arr[19] = 0;

    return (reinterpret_cast<void*>(arr));
}
