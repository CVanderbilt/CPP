#include <iostream>
#include "Templates.hpp"
#include "iter.hpp"

void ft_foo(std::string& s)
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
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		std::cout << iarr[i];
	std::cout << std::endl;
	::iter (iarr, 3, &ft_fooi);
	for (int i = 0; i < 5; i++)
		std::cout << iarr[i];
	std::cout << std::endl;

	::iter (arr, -7, &ft_foo);

	std::cout << "Prueba template" << std::endl;
	::iter (arr, 3, template_print<std::string>);
    
	return (0);
}