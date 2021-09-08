#ifndef B_HPP
# define B_HPP
# include "Base.hpp"

class B: public Base
{
	private:
		B(const B&);
    public:
        B(void);
		~B(void);
		B& operator=(const B&);
};


#endif