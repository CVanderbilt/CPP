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
        int a_sign_grade;
        int a_exec_grade;
        std::string a_name;
    public:
        Form(std::string, int sign_req, int exec_req);
        Form(const Form& f);
        virtual ~Form(void);

        Form& operator=(const Form&);

        void beSigned(const Bureaucrat&);

        std::string getName(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        bool getStatus(void) const;
};

std::ostream&   operator<<(std::ostream& os, const Form& obj);


#endif