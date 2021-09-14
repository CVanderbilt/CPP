#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int b = rand() % 3;
	switch (b)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

void identify(Base* p)
{

    if (dynamic_cast<A*>(p))
        std::cout << 'A' << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << 'B' << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << 'C' << std::endl;
    else
        std::cout << "not a recognized type" << std::endl;
}
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(...){}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(...){}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(...){}

	std::cout << "not a recognized type" << std::endl;
}

int main(void)
{
    srand(time(NULL));
    Base* arr[10];

	std::string s;
    for (int i = 0; i < 10; i++)
    {
		arr[i] = generate();
    }

    for (int i = 0; i < 10; i++){
		std::cout << "   ";
        identify(arr[i]);
		std::cout << "   ";
        identify(*arr[i]);
        std::cout << "-------" << std::endl;
    }

	std::cout << s << std::endl;
    
    return (0);
}