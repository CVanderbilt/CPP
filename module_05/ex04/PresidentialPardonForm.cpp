#include <iostream>
#include <iostream>
#include <fstream>  
#include "PresidentialPardonForm.hpp"

//Creators & destructor 
PresidentialPardonForm ::PresidentialPardonForm (const std::string& target):
    Form("PresidentialPardonForm ", 25, 5){this->setTarget(target);}
PresidentialPardonForm ::PresidentialPardonForm (const PresidentialPardonForm & s):
    Form("PresidentialPardonForm ", 25, 5){
        *this = s;
}
PresidentialPardonForm ::~PresidentialPardonForm (void){}

//Operators
PresidentialPardonForm & PresidentialPardonForm ::operator=(const PresidentialPardonForm & s){
    this->setTarget(s.getTarget());
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const PresidentialPardonForm& obj){
    if (obj.getStatus())
        os << "Signed form ";
    else
        os << "Unsigned form ";
    os << obj.getName() << "; lvl required: to sign " << obj.getSignGrade() << "; to execute " << obj.getExecGrade();
    os << "; target: " << obj.getTarget();
    return (os);
}

//Other
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    try 
    {
        this->check(executor);
    }
    catch (const std::exception& e)
    {
        throw;
    }

    std::cout << this->getTarget() << "has been pardoned by Zafod Beeblebrox." << std::endl;
}

Form* PresidentialPardonForm::clone(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}