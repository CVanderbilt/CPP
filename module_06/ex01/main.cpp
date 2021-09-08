#include <iostream>
#include "Data.hpp"

/*ignore_check*/

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << "test " << i << ": " << '\n';
		uintptr_t raw = serialize();
		Data *dt = deserialize(raw);
        (void)dt;
		std::cout << std::endl;
		std::cout << "\tstr1: " << dt->s1 << '\n';
		std::cout << "\tn:    " << dt->n << '\n';
		std::cout << "\tstr2: " << dt->s2 << std::endl;
		std::cout << std::endl;
		delete (char*)(raw);
		delete dt;
	}

	return (0);
}