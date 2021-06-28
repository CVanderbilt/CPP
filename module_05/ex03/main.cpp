#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

/*check_ignore*/

int main(void)
{
    srand(time(NULL));

    Form *r_form;
    Form *s_form;
    Form *p_form;

    Bureaucrat bob("Bob", 1);
    Bureaucrat john("John", 150);

    Intern someIntern;

    try
    {
        someIntern.makeForm("kk", "will fail");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        r_form = someIntern.makeForm("RobotomyRequestForm", "mike");
        s_form = someIntern.makeForm("ShrubberyCreationForm", "test");
        p_form = someIntern.makeForm("PresidentialPardonForm", "some random guy");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "Form list:" << std::endl;
    std::cout << *r_form << std::endl << *s_form << std::endl << *p_form << std::endl;
    std::cout << "Bureaucrats:" << std::endl << bob << std::endl << john << std::endl;

    std::cout << std::endl << std::endl;

    john.signForm(*r_form);
    bob.signForm(*r_form);
    john.executeForm(*r_form);
    bob.executeForm(*r_form);
    bob.executeForm(*r_form);
    bob.executeForm(*r_form);
    bob.executeForm(*r_form);
    bob.executeForm(*r_form);

    std::cout << std::endl << std::endl;

    john.signForm(*s_form);
    bob.executeForm(*s_form);
    bob.signForm(*s_form);
    bob.executeForm(*s_form);

    std::cout << std::endl << std::endl;

    john.signForm(*p_form);
    bob.signForm(*p_form);
    john.executeForm(*p_form);
    bob.executeForm(*p_form);    

    std::cout << "Fin" << std::endl;
    
    delete (r_form);
    delete (s_form);
    delete (p_form);

    return (0);
}