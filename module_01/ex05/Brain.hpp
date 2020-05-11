#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    private:
        std::string name;
    public:
        Brain(void);
        Brain(std::string name);
        ~Brain(void);

        void setName(std::string);
        std::string identify(void) const; 
};

#endif