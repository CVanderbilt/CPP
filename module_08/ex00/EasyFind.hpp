#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>

template<typename T>
int& easyfind(T& container, int n){
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        if (*it == n)
            return (*it);
    throw (std::exception()); 
}

#endif