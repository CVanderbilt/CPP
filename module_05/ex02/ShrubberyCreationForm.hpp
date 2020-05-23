#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public Form
{
    private:
        ShrubberyCreationForm(void);
    public:
        ShrubberyCreationForm(const std::string&);
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        virtual ~ShrubberyCreationForm(void);

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

        void execute(const Bureaucrat&) const;
};

std::ostream&   operator<<(std::ostream& os, const ShrubberyCreationForm& obj);

#endif