#include <iostream>
#include "Data.hpp"

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << "test " << i << ": " << '\n';
		void *raw = serialize();
		Data *dt = deserialize(raw);
        (void)dt;

		std::cout << "\tstr1: " << dt->s1 << '\n';
		std::cout << "\tn:    " << dt->n << '\n';
		std::cout << "\tstr2: " << dt->s2 << std::endl;

		delete static_cast<char*>(raw);
		delete dt;
	}

	return (0);
}