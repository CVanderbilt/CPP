#ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
    private:
        RobotomyRequestForm (void);
    public:
        RobotomyRequestForm (const std::string&);
        RobotomyRequestForm (const RobotomyRequestForm &);
        virtual ~RobotomyRequestForm (void);

        RobotomyRequestForm & operator=(const RobotomyRequestForm &);

        void execute(const Bureaucrat&) const;
};

std::ostream&   operator<<(std::ostream& os, const RobotomyRequestForm& obj);

#endif