#ifndef PEON_HPP
# define PEON_HPP
# include "Victim.hpp"
# include <iostream>

class Peon: public Victim
{
    private:
        Peon(void);						//default constructor
    public:
        Peon(std::string);
        Peon(const Peon &);				//copy constructor
        virtual ~Peon(void);			//destructor

        Peon& operator=(const Peon&);	//=operator
        
        void getPolymorphed(void) const;
};

#endif