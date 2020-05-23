#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP
# include <iostream>

# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "OfficeBlock.hpp"

class CentralBureaucracy
{
    private:
        OfficeBlock a_blocks_list[20];
        Intern a_interns_list[20];
        std::string a_burolist[4];
        std::string *a_queue;
        int a_queue_size;
        CentralBureaucracy(const CentralBureaucracy&);
        CentralBureaucracy& operator=(const CentralBureaucracy&);
    public:
        CentralBureaucracy(void);
        ~CentralBureaucracy(void);

        void feed(Bureaucrat &);
        void queueUp(const std::string&);
        void doBureaucracy(void);

        int getQueuesize(void) const;
        std::string* getQueue(void) const;
};

#endif