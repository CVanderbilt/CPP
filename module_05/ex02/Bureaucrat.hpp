#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat;

# include "Form.hpp"

class Bureaucrat
{
    private:
        Bureaucrat(void);
        const std::string a_name;
        int a_grade;
    public:
        Bureaucrat(const std::string, int);
        Bureaucrat(const Bureaucrat&);
        virtual ~Bureaucrat(void);

        Bureaucrat& operator=(const Bureaucrat&);

        class GradeTooHighException: public std::exception {
		    virtual const char* what() const throw();
	    };
	    class GradeTooLowException: public std::exception {
		    virtual const char* what() const throw();
	    };

        void increment(void);
        void decrement(void);
        void signForm(Form&);
        void executeForm(Form const & form);

        int getGrade(void) const;
        std::string getName(void) const;
};

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& obj);

#endif