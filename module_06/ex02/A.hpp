#ifndef A_HPP
# define A_HPP
# include "Base.hpp"

class A: public Base
{
	private:
		A(const A&);
    public:
        A(void);
		~A(void);
		A& operator=(const A&);
};


#endif
