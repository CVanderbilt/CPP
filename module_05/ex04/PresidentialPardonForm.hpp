#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
    private:
        PresidentialPardonForm (void);
    public:
        PresidentialPardonForm (const std::string&);
        PresidentialPardonForm (const PresidentialPardonForm &);
        virtual ~PresidentialPardonForm (void);

        PresidentialPardonForm & operator=(const PresidentialPardonForm &);

        void execute(const Bureaucrat&) const;
        static Form* clone(const std::string&);
};

std::ostream&   operator<<(std::ostream& os, const PresidentialPardonForm& obj);

#endif