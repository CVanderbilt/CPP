#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade){
        if (grade < 1)
            throw (Bureaucrat::GradeTooHighException());
        if (grade > 150)
            throw (Bureaucrat::GradeTooLowException());
}
Bureaucrat::Bureaucrat(const Bureaucrat& b){*this = b;}
Bureaucrat::~Bureaucrat(void){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b){
    this->a_name = b.getName();
    this->a_grade = b.getGrade();
    if (this->a_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if (this->a_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& obj){
    os << obj.getName() <<  ", bureaucrat grade " << obj.getGrade() << ".";
    return (os);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade to high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade to low");
}

void Bureaucrat::increment(void)
{
    this->a_grade--;
    if (this->a_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if (this->a_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
}

void Bureaucrat::decrement(void)
{
    this->a_grade++;
    if (this->a_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if (this->a_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
}

int Bureaucrat::getGrade(void) const{return (this->a_grade);}
std::string Bureaucrat::getName(void) const{return (this->a_name);}
