#include <iostream>
#include "iter.hpp"

void ft_foo(const std::string& s)
{
    std::cout << s << std::endl;
}

void ft_fooi(int &n)
{
	n += 3;
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

	int	iarr[5]  ={1, 2, 30, 4, 5};

    ::iter (arr, 5, &ft_foo);
	//::iter (iarr, 5, &ft_fooi);
	for (int i = 0; i < 5; i++)
		std::cout << iarr[i];
	std::cout << std::endl;
    return (0);
}