#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        std::string a_name_list[3];
        Form *((*a_fcnPtr_list[3])(const std::string&));

    public:
        Intern(void);
        Intern(const Intern&);
        virtual ~Intern(void);

        Intern& operator=(const Intern&);

        class UnrecognisedFormException: public std::exception {
		    virtual const char* what() const throw();
	    };

        Form* makeForm(const std::string& form_name, const std::string& target);
};

#endif