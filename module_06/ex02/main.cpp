#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify_from_pointer(Base* p)
{

    if (dynamic_cast<A*>(p))
        std::cout << p << " is type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << p << " is type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << p << " is type C" << std::endl;
    else
        std::cout << p << " is not a recognized type" << std::endl;
}
void identify_from_reference(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "ref is type A" << std::endl;
        return ;
    }
    catch(...){}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "ref is type B" << std::endl;
        return ;
    }
    catch(...){}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "ref is type C" << std::endl;
        return ;
    }
    catch(...){}
}

int main(void)
{
    srand(time(NULL));
    Base* arr[10];

	std::string s;
    for (int i = 0; i < 10; i++)
    {
        int b = rand() % 3;
        switch (b)
        {
        case 0:
            arr[i] = new (A);
			s += "a, ";
            break ;
        case 1:
            arr[i] = new (B);
			s += "b, ";
            break ;
        default:
            arr[i] = new (C);
			s+= "c, ";
            break ;
        }
    }

    for (int i = 0; i < 10; i++){
        identify_from_pointer(arr[i]);
        identify_from_reference(*arr[i]);
        std::cout << std::endl;
    }

	std::cout << s << std::endl;
    
    return (0);
}