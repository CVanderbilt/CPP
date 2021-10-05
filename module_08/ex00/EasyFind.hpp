#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>









template<typename T>
typename T::iterator easyfind_aux(T &container, int value)
{
	return (std::find(container.begin(), container.end(), value));
}

template<typename key_type>
typename std::map<key_type, int>::iterator easyfind_aux(std::map<key_type, int> &container, int value)
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
typename std::multimap<key_type, int>::iterator easyfind_aux(std::multimap<key_type, int> &container, int value)
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
typename T::iterator easyfind(T& container, int n)
{
	return (easyfind_aux(container, n));
}

template<typename T>
void tryFind(T &container, int value)
{
	typename T::iterator it;
	it = easyfind(container, value);
	if (it == container.end())
		std::cout << "Container does not contain " << value << std::endl;
	else
		std::cout << "Container contains " << value << std::endl;
}

#endif