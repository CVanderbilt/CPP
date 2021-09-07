#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

//Creators & Destructor
Intern::Intern(void){
    this->a_name_list[0] = "PresidentialPardonForm";
    this->a_name_list[1] = "ShrubberyCreationForm";
    this->a_name_list[2] = "RobotomyRequestForm";

    this->a_fcnPtr_list[0] = PresidentialPardonForm::clone;
    this->a_fcnPtr_list[1] = ShrubberyCreationForm::clone;
    this->a_fcnPtr_list[2] = RobotomyRequestForm::clone;
}
Intern::Intern(const Intern& i){*this = i;}
Intern::~Intern(void){}

//Operators
Intern& Intern::operator=(const Intern& i){
    (void)i;
    return (*this);
}

//Others
const char* Intern::UnrecognisedFormException::what(void) const throw()
{
    return ("Form name not recognised, remember using format NamedTypedForm or else this form doesnt exist");
}

Form* Intern::makeForm(const std::string& form, const std::string& target)
{
    for (int i = 0; i < 3; i++){
        if (form == this->a_name_list[i])
            return (this->a_fcnPtr_list[i](target));
    }

    throw (Intern::UnrecognisedFormException());
}