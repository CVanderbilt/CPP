#include <iostream>
#include "Form.hpp"

Form::Form(std::string name, int sign_req, int exec_req):
    a_status(false), a_sign_grade(sign_req), a_exec_grade(exec_req), a_name(name){
    if (this->a_exec_grade < 1 || this->a_sign_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if (this->a_exec_grade > 150 || this->a_sign_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
}

Form::Form(void): a_sign_grade(1), a_exec_grade(1),
	a_name("unnamed"){}
Form::Form(const Form& f): a_sign_grade(f.getSignGrade()), a_exec_grade(f.getExecGrade()),
	a_name(f.getName()){*this = f;}
Form::~Form(void){}

Form& Form::operator=(const Form& f){
    this->a_status = f.getStatus();
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

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->a_sign_grade)
        throw (Bureaucrat::GradeTooLowException());
    this->a_status = true;
}

std::string Form::getName(void) const{return (this->a_name);}
int Form::getSignGrade(void) const{return (this->a_sign_grade);}
int Form::getExecGrade(void) const{return (this->a_exec_grade);}
bool Form::getStatus(void) const{return (this->a_status);}

