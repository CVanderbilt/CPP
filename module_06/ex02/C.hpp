#ifndef C_HPP
# define C_HPP
# include "Base.hpp"

class C: public Base
{
	private:
		C(const C&);
    public:
        C(void);
		~C(void);
		C& operator=(const C&);
};


#endif