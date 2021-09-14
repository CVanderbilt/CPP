#include <iostream>
#include "Data.hpp"

/*ignore_check*/

void ft_test(Data *ptr)
{
	static int n = -1;

	n++;
	std::cout << "test " << n << ": " << '\n';
	uintptr_t raw = serialize(ptr);
	Data *dt = deserialize(raw);
    (void)dt;
	std::cout << std::endl;
	std::cout << "\tstr1: " << dt->s1 << std::endl;
	std::cout << "\tstr2: " << dt->s2 << std::endl;
	std::cout << "\tn:    " << dt->n << std::endl << std::endl;
	delete (char*)(raw);
	delete dt;
}

int main(void)
{
	srand(time(NULL));
	Data init;

	init.n = 42424200;
	init.s1 = "hola";
	init.s2 = "mundo";
	ft_test(&init);

	init.n = 0;
	init.s1 = "mundo";
	init.s2 = "hola";
	ft_test(&init);

	init.n = 1234567;
	init.s1 = "_";
	init.s2 = "fsdkljklfjsañlkjfklñdsjlkfjdsalkjfklasjaaaaaaa";
	ft_test(&init);

	init.n = 2147483647;
	init.s1 = "";
	init.s2 = "max_  int :)";
	ft_test(&init);
	
	return (0);
}