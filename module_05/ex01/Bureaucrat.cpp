#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): a_name(name), a_grade(grade){
        if (grade < 1){
			this->a_grade = 150;
            throw (Bureaucrat::GradeTooHighException());
		}
		if (grade > 150){
			this->a_grade = 150;
		    throw (Bureaucrat::GradeTooLowException());
		}
}

Bureaucrat::Bureaucrat(void){}
Bureaucrat::Bureaucrat(const Bureaucrat& b){*this = b;}
Bureaucrat::~Bureaucrat(void){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b){
    this->a_name = b.getName();
    this->a_grade = b.getGrade();
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
    if (this->a_grade == 1)
        throw (Bureaucrat::GradeTooHighException());
	else
		this->a_grade--;
}

void Bureaucrat::decrement(void)
{
    if (this->a_grade == 150)
        throw (Bureaucrat::GradeTooLowException());
	else
		this->a_grade++;
}

void Bureaucrat::signForm(Form& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << *this << " Signs " << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << *this << " Cannot sign " << f << " because " << e.what() << std::endl;
    }
}

int Bureaucrat::getGrade(void) const{return (this->a_grade);}
std::string Bureaucrat::getName(void) const{return (this->a_name);}
