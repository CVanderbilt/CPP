#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Form;

#include "Bureaucrat.hpp"

class Form
{
    private:
        Form();
        bool a_status;
        const int a_sign_grade;
        const int a_exec_grade;
        const std::string a_name;
        std::string a_target;
    public:
        Form(std::string, int, int);
        Form(const Form& f);
        virtual ~Form(void);

        Form& operator=(const Form&);

        class UnsignedFormException: public std::exception {
		    virtual const char* what() const throw();
	    };

        void beSigned(const Bureaucrat&);
        void check(const Bureaucrat&) const;
        virtual void execute(Bureaucrat const&) const = 0;

        std::string getTarget(void) const;
        std::string getName(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        bool getStatus(void) const;

        void setTarget(const std::string&);

};

std::ostream&   operator<<(std::ostream& os, const Form& obj);


#endif