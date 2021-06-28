#include <iostream>
#include "Bureaucrat.hpp"

/*check_ignore*/

int main(void)
{
    Bureaucrat buro1("Bob", 2);
    Bureaucrat buro2("Jhon", 149);

    std::cout << "Initial bureaucrats:" << std::endl;
    std::cout << buro1 << std::endl;
    std::cout << buro2 << std::endl;

    try
    {
        buro1.increment();
        buro1.increment();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        buro2.decrement();
        buro2.decrement();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat buro3("Error", -23);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}