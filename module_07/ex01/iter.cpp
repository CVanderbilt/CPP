#include <iostream>

template<typename T>
void iter(T *arr, int size, void (*foo)(const T&)){
    for (int i = 0; i < size; i++)
        foo(arr[i]);
}

void ft_foo(const std::string& s)
{
    std::cout << s << std::endl;
}

int main(void)
{
    std::string arr[5] = {
        "str1",
        "str2",
        "str3",
        "str4",
        "str5"
    };

    ::iter (arr, 5, &ft_foo);

    return (0);
}