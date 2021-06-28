#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>

class Victim
{
    private:
        Victim();							//default constructor
    protected:
        std::string name;
    public:
        Victim(std::string name);
        Victim(const Victim &v);			//copy constructor
        virtual ~Victim(void);						//destructor

        Victim& operator=(const Victim &);	//= operator

        virtual void getPolymorphed(void) const;

        //get & set
        std::string getName(void) const;
};

std::ostream& operator<<(std::ostream& os, const Victim &v);

#endif