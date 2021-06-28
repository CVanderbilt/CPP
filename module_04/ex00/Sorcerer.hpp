#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
    private:
        Sorcerer(void);							//default constructor
        std::string name;
        std::string title;
    public:
        Sorcerer(std::string name, std::string title);
        Sorcerer(const Sorcerer&);				//copy constructor
        ~Sorcerer(void);						//destructor

        Sorcerer& operator=(const Sorcerer&);	//= operator

        void polymorph(Victim const &) const;

        //get & set
        std::string getName(void) const;
        std::string getTitle(void) const;
};

std::ostream& operator<<(std::ostream& os, const Sorcerer& s);

#endif