#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

/*check_ignore*/

int main(void)
{
    Bureaucrat buro("Bob", 15);
    Form f1("A21", 15, 10);
    Form f2("B21", 1, 10);

    buro.signForm(f1);
    buro.signForm(f2);

    try
    {
        Form error("Error", -23, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}