#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void): a_signer(0), a_executor(0), a_intern(0){}
OfficeBlock::OfficeBlock(Bureaucrat* s, Bureaucrat* e, Intern* i):
    a_signer(s), a_executor(e), a_intern(i){}
OfficeBlock::OfficeBlock(Bureaucrat& s, Bureaucrat& e, Intern& i):
    a_signer(&s), a_executor(&e), a_intern(&i){}
OfficeBlock::OfficeBlock(const OfficeBlock& o){(void)o;}
OfficeBlock::~OfficeBlock(void){}

OfficeBlock& OfficeBlock::operator=(const OfficeBlock& f){(void)f; return (*this);}

const char* OfficeBlock::IncompleteOfficeException::what(void) const throw()
{
    return ("Nobody worked on this office for a long time");
}

void OfficeBlock::doBureaucracy(const std::string& form_name, const std::string& target)
{
    Form *form;

    if (!this->a_signer || !this->a_executor || !this->a_intern)
        throw(OfficeBlock::IncompleteOfficeException());

    try
    {
        form = this->a_intern->makeForm(form_name, target);
    }
    catch(const std::exception& e)
    {
        throw ;
    }

    this->a_signer->signForm(*form);
    this->a_executor->executeForm(*form);
    delete (form);
}

Intern* OfficeBlock::getIntern(void) const{return (this->a_intern);}
Bureaucrat* OfficeBlock::getSigner(void) const{return (this->a_signer);}
Bureaucrat* OfficeBlock::getExecutor(void) const{return (this->a_executor);}

void OfficeBlock::setIntern(Intern* i){this->a_intern = i;}
void OfficeBlock::setIntern(Intern& i){this->a_intern = &i;}
void OfficeBlock::setSigner(Bureaucrat* b){this->a_signer = b;}
void OfficeBlock::setSigner(Bureaucrat& b){this->a_signer = &b;}
void OfficeBlock::setExecutor(Bureaucrat* b){this->a_executor = b;}
void OfficeBlock::setExecutor(Bureaucrat& b){this->a_executor = &b;}