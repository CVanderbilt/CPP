#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>

class Pony
{
    private:
        int age;
        int weight;
        std::string name;
    public:
        Pony();
        ~Pony();
        
        int         getWeight(void);
        int         getAge(void);
        std::string getName(void);
        void        doThings(void);
};
#endif