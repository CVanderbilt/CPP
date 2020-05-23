#include <iostream>
#include <iostream>
#include <fstream>  
#include "ShrubberyCreationForm.hpp"

//Creators & destructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
    Form("ShrubberyCreationForm", 145, 137){this->setTarget(target);}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s):
    Form("ShrubberyCreationForm", 145, 137){*this = s;}
ShrubberyCreationForm::~ShrubberyCreationForm(void){}

//Operators
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s){
    this->setTarget(s.getTarget());
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const ShrubberyCreationForm& obj){
    if (obj.getStatus())
        os << "Signed form ";
    else
        os << "Unsigned form ";
    os << obj.getName() << "; lvl required: to sign " << obj.getSignGrade() << "; to execute " << obj.getExecGrade();
    os << "; target: " << obj.getTarget();
    return (os);
}

//Other
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    try 
    {
        this->check(executor);
    }
    catch (const std::exception& e)
    {
        throw;
    }

    std::ofstream outfile (this->getTarget() + "_shrubbery");

    outfile << "     /\\" << std::endl;
    outfile << "    /  \\" << std::endl;
    outfile << "   /    \\" << std::endl;
    outfile << "  /      \\" << std::endl;
    outfile << " ----------" << std::endl;
    outfile << "   /    \\" << std::endl;
    outfile << "  /      \\" << std::endl;
    outfile << " /        \\" << std::endl;
    outfile << " ----------" << std::endl;
    outfile << "  /      \\" << std::endl;
    outfile << " /        \\" << std::endl;
    outfile << "/          \\" << std::endl;
    outfile << "------------" << std::endl;
    outfile << "    ||||" << std::endl;
    outfile << "    ||||" << std::endl;

    outfile.close();
}

Form* ShrubberyCreationForm::clone(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}