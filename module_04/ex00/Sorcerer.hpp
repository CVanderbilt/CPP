#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
    private:
        Sorcerer(void);
        std::string name;
        std::string title;
    public:
        Sorcerer(std::string name, std::string title);
        Sorcerer(const Sorcerer&);
        ~Sorcerer(void);

        Sorcerer& operator=(const Sorcerer&);

        void polymorph(Victim const &) const;

        //get & set
        std::string getName(void) const;
        std::string getTitle(void) const;
};

std::ostream& operator<<(std::ostream& os, const Sorcerer& s);

#endif