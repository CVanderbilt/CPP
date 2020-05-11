#ifndef PEON_HPP
# define PEON_HPP
# include "Victim.hpp"
# include <iostream>

class Peon: public Victim
{
    private:
        Peon(void);
    public:
        Peon(std::string);
        Peon(const Peon &);
        virtual ~Peon(void);

        Peon& operator=(const Peon&);
        
        void getPolymorphed(void) const;
};

#endif