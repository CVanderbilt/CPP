#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

/*check_ignore*/

int main(void)
{

    Intern i;

    Bureaucrat b1("bob", 1);
    Bureaucrat b2("john", 1);
    Bureaucrat b3("Mike", 140);

    OfficeBlock block0;
    OfficeBlock block1;
    OfficeBlock block2(b3, b1, i);
    OfficeBlock block3(&b1, &b1, &i);

    block1.setIntern(i);
    block1.setSigner(b1);
    block1.setExecutor(&b3);

    try
    {
        std::cout << std::endl;
        std::cout << std::endl << "Block0:" << std::endl;
        block0.doBureaucracy("RobotomyRequestForm", "some guy");
        std::cout << std::endl;
        block0.doBureaucracy("ShrubberyCreationForm", "block0");
        std::cout << std::endl;
        block0.doBureaucracy("PresidentialPardonForm", "Blope");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Block0 throws exception:" << std::endl;
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << std::endl;
        std::cout << std::endl << "Block1:" << std::endl;
        block1.doBureaucracy("RobotomyRequestForm", "some guy");
        std::cout << std::endl;
        block1.doBureaucracy("ShrubberyCreationForm", "block1");
        std::cout << std::endl;
        block1.doBureaucracy("PresidentialPardonForm", "Blope");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Block1 throws exception:" << std::endl;
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << std::endl;
        std::cout << std::endl << "Block2:" << std::endl;
        block2.doBureaucracy("RobotomyRequestForm", "some guy");
        std::cout << std::endl;
        block2.doBureaucracy("ShrubberyCreationForm", "block2");
        std::cout << std::endl;
        block2.doBureaucracy("PresidentialPardonForm", "Blope");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Block2 throws exception:" << std::endl;
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << std::endl;
        std::cout << std::endl << "Block3:" << std::endl;
        block3.doBureaucracy("RobotomyRequestForm", "some guy");
        std::cout << std::endl;
        block3.doBureaucracy("ShrubberyCreationForm", "block3");
        std::cout << std::endl;
        block3.doBureaucracy("PresidentialPardonForm", "Blope");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Block3 throws exception:" << std::endl;
        std::cerr << e.what() << '\n';
    }

    return (0);
}