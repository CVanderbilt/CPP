#include <iostream>
#include <fstream>  
#include "RobotomyRequestForm.hpp"

//Creators & destructor
RobotomyRequestForm ::RobotomyRequestForm (const std::string& target):
    Form("RobotomyRequestForm ", 72, 45){this->setTarget(target);}
RobotomyRequestForm ::RobotomyRequestForm (const RobotomyRequestForm & s):
    Form("RobotomyRequestForm ", 72, 45){
        *this = s;
}
RobotomyRequestForm ::~RobotomyRequestForm (void){}

//Operators
RobotomyRequestForm & RobotomyRequestForm ::operator=(const RobotomyRequestForm & s){
    this->setTarget(s.getTarget());
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const RobotomyRequestForm& obj){
    if (obj.getStatus())
        os << "Signed form ";
    else
        os << "Unsigned form ";
    os << obj.getName() << "; lvl required: to sign " << obj.getSignGrade() << "; to execute " << obj.getExecGrade();
    os << "; target: " << obj.getTarget();
    return (os);
}

//Other
void RobotomyRequestForm ::execute(const Bureaucrat& executor) const
{
    try 
    {
        this->check(executor);
    }
    catch (const std::exception& e)
    {
        throw;
    }

    const int randomBit = rand() & 1;
    if (randomBit)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->getTarget() << " couldnt be robotomized this time" << std::endl;
}

Form* RobotomyRequestForm::clone(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}