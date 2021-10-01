#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
/*
template<typename T>
int& easyfind(T& container, int n){
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        if (*it == n)
            return (*it);
    throw (std::exception());
}*/

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	return (std::find(container.begin(), container.end(), value));
}

template<typename key_type>
typename std::map<key_type, int>::iterator easyfind(std::map<key_type, int> &container, int value)
{
	typename std::map<key_type, int>::iterator it;
	for (it = container.begin();
		it != container.end();
		it++)
		if (it->second == value)
			return (it);
	return (container.end());
}

template<typename key_type>
typename std::multimap<key_type, int>::iterator easyfind(std::multimap<key_type, int> &container, int value)
{
	typename std::multimap<key_type, int>::iterator it;
	for (it = container.begin();
		it != container.end();
		it++)
		if (it->second == value)
			return (it);
	return (container.end());
}


template<typename T>
void tryFind(T &container, int value)
{
	typename T::iterator it = easyfind(container, value);
	std::cout << "Contains " << value << ":";
	if (it != container.end())
		std::cout << "true, " << *it << std::endl;
	else
		std::cout << "false" << std::endl; 
}

#endif