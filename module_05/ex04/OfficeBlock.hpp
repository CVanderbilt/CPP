#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"

class OfficeBlock
{
    private:
        Intern *a_intern;
        Bureaucrat *a_signer;
        Bureaucrat *a_executor;
        OfficeBlock(const OfficeBlock&);
        OfficeBlock& operator=(const OfficeBlock&);
    public:
        OfficeBlock(void);
        OfficeBlock(Bureaucrat* s, Bureaucrat* e, Intern* i);
        OfficeBlock(Bureaucrat& s, Bureaucrat& e, Intern& i);
        virtual ~OfficeBlock(void);

        class IncompleteOfficeException: public std::exception {
		    virtual const char* what() const throw();
	    };

        void doBureaucracy(const std::string& form_name, const std::string& target);

        Intern* getIntern(void) const;
        Bureaucrat* getSigner(void) const;
        Bureaucrat* getExecutor(void) const;

        void setIntern(Intern*);
        void setIntern(Intern&);
        void setSigner(Bureaucrat*);
        void setSigner(Bureaucrat&);
        void setExecutor(Bureaucrat*);
        void setExecutor(Bureaucrat&);
};

#endif