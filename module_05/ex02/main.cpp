#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"

int main(void)
{
    srand(time(NULL));

    RobotomyRequestForm r_form("Mike");
    ShrubberyCreationForm s_form("test");
    PresidentialPardonForm p_form("Some random guy");

    Bureaucrat bob("Bob", 1);
    Bureaucrat john("John", 150);

    std::cout << "Form list:" << std::endl;
    std::cout << r_form << std::endl << s_form << std::endl << p_form << std::endl;
    std::cout << "Bureaucrats:" << std::endl << bob << std::endl << john << std::endl;

    std::cout << std::endl << std::endl;

    john.signForm(r_form);
    bob.signForm(r_form);
    john.executeForm(r_form);
    bob.executeForm(r_form);
    bob.executeForm(r_form);
    bob.executeForm(r_form);
    bob.executeForm(r_form);
    bob.executeForm(r_form);

    std::cout << std::endl << std::endl;

    john.signForm(s_form);
    bob.executeForm(s_form);
    bob.signForm(s_form);
    bob.executeForm(s_form);

    std::cout << std::endl << std::endl;

    john.signForm(p_form);
    bob.signForm(p_form);
    john.executeForm(p_form);
    bob.executeForm(p_form);    

    std::cout << "Fin" << std::endl;
    
    return (0);
}