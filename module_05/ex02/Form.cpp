#include <iostream>
#include "Form.hpp"

//Creators & destructos
Form::Form(std::string name, int sign_req, int exec_req):
    a_name(name), a_sign_grade(sign_req), a_exec_grade(exec_req), a_status(false){
    if (this->a_exec_grade < 1 || this->a_sign_grade < 1){
		this->a_sign_grade = 150;
        throw (Bureaucrat::GradeTooHighException());
	}
    if (this->a_exec_grade > 150 || this->a_sign_grade > 150){
		this->a_sign_grade = 150;
        throw (Bureaucrat::GradeTooLowException());
	}
}

Form::Form(void){}
Form::Form(const Form& f){*this = f;}
Form::~Form(void){}

//Operators
Form& Form::operator=(const Form& f){
    this->a_name = f.getName();
    this->a_status = f.getStatus();
    this->a_exec_grade = f.getExecGrade();
    this->a_sign_grade = f.getSignGrade();
    return (*this);
}
std::ostream&   operator<<(std::ostream& os, const Form& obj){
    if (obj.getStatus())
        os << "Signed form ";
    else
        os << "Unsigned form ";
    os << obj.getName() << "; lvl required: to sign " << obj.getSignGrade() << "; to execute " << obj.getExecGrade();
    return (os);
}

//Other

const char* Form::UnsignedFormException::what(void) const throw()
{
    return ("Unsigned form");
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->a_sign_grade)
        throw (Bureaucrat::GradeTooLowException());
    this->a_status = true;
}

void Form::check(const Bureaucrat& b) const
{
    if (this->a_exec_grade < b.getGrade())
        throw (Bureaucrat::GradeTooLowException());
    if (!this->a_status)
        throw (Form::UnsignedFormException());
}

//get & set
std::string Form::getTarget(void) const{return (this->a_target);}
std::string Form::getName(void) const{return (this->a_name);}
int Form::getSignGrade(void) const{return (this->a_sign_grade);}
int Form::getExecGrade(void) const{return (this->a_exec_grade);}
bool Form::getStatus(void) const{return (this->a_status);}

void Form::setTarget(const std::string& target){this->a_target = target;}

