#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
    private:
        int m_size;
        T *m_arr;
    public:
        Array(void);
        Array(unsigned int);
        Array(const Array&);
        virtual ~Array(void);

        Array& operator=(const Array&);
        T& operator[](int) const;

        class IndexOutOfBoundsException: public std::exception {
		    virtual const char* what() const throw();
	    };

        int size(void) const;
};

#include "Array.cpp"

#endif