#ifndef HUMAN_HPP
# define HUMAN_HPP
# include <iostream>
# include "Brain.hpp"

class Human
{
    private:
        std::string name;
        std::string lastname;
        const Brain brain;
    public:
        Human(void);
        Human(std::string name);
        Human(std::string name, std::string lastname);
        ~Human(void);

        std::string identify() const;
        void        setName(std::string name);
        void        setLastName(std::string lastname);
        const Brain &getBrain(void);
};
#endif