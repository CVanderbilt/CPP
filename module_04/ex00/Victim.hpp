#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>

class Victim
{
    private:
        Victim();
    protected:
        std::string name;
    public:
        Victim(std::string name);
        Victim(const Victim &v);
        ~Victim(void);

        Victim& operator=(const Victim &);

        virtual void getPolymorphed(void) const;

        //get & set
        std::string getName(void) const;
};

std::ostream& operator<<(std::ostream& os, const Victim &v);

#endif