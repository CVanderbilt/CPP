#include <vector>
#include <list>
#include <deque>
#include <set>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include "easyfind.hpp"

int main()
{
    std::vector<int>first;
    std::list<int>my_list;
    std::deque<int>my_deque;
	std::set<int>my_set;
	std::multiset<int>my_mset;
	std::map<std::string, int>my_map;
	std::multimap<std::string, int>my_mmap;

	my_mmap.insert ( std::pair<std::string,int>("kk",100) );
	my_mmap.insert ( std::pair<std::string,int>("pp",100) );
	my_mmap.insert ( std::pair<std::string,int>("other",56) );

	my_map["key0"] = 99;
	my_map["key1"] = 3;
	

	my_mset.insert(9);
	my_mset.insert(23);

    first.push_back(0);
    first.push_back(1);

    my_list.push_back(2);
    my_list.push_back(3);

    my_deque.push_back(4);
    my_deque.push_back(5);

	my_set.insert(2);
	my_set.insert(5);
	my_set.insert(8);
	my_set.insert(-1);
	my_set.insert(0);

	std::cout << "Vector:" << std::endl;
	tryFind(first, 1);
	tryFind(first, 10);
	std::cout << "List:" << std::endl;
	tryFind(my_list, 3);
	tryFind(my_list, 5);
	std::cout << "Deque:" << std::endl;
	tryFind(my_deque, 5);
	tryFind(my_deque, 88);
	std::cout << "Set:" << std::endl;
	tryFind(my_set, -1);
	tryFind(my_set, -123);
	std::cout << "Mset:" << std::endl;
	tryFind(my_mset, 23);
	tryFind(my_mset, 0);

	{
		std::cout << "Map:" << std::endl;
		std::map<std::string, int>::iterator it = easyfind(my_map, 3);
		if (it != my_map.end())
			std::cout << "Contains 3:true " << it->first << "->" << it->second << std::endl;
		it = easyfind(my_map, 4);
		if (it == my_map.end())
			std::cout << "Contains 4:false" << std::endl;
		else
			std::cout << "Something wrong" << std::endl;
	}

	{
		std::cout << "Mmap" << std::endl;
		std::multimap<std::string, int>::iterator it = easyfind(my_mmap, 100);
		if (it != my_mmap.end())
			std::cout << "Contains 100:true " << it->first << "->" << it->second << std::endl;
		it = easyfind(my_map, 4);
		if (it == my_map.end())
			std::cout << "Contains 4:false" << std::endl;
		else
			std::cout << "Something wrong" << std::endl;
	}
	

	


    /*try
    {
        int result = easyfind(first, 0);
        std::cout << "Found: " << result << std::endl;
        result = easyfind(my_deque, 4);
        std::cout << "Found: " << result << std::endl;
        result = easyfind(my_list, 2);
        std::cout << "Found: " << result << std::endl;
        result = easyfind(first, 8);
        std::cout << "Found: " << result << std::endl;
    }
    catch(...)
    {
        std::cerr << "Couldnt find or something else went wrong" << std::endl;
    }

	try
	{
		int result = easyfind(my_set, 8);
        std::cout << "Found: " << result << std::endl;
		result = easyfind(my_set, 0);
        std::cout << "Found: " << result << std::endl;
		result = easyfind(my_set, 99);
        std::cout << "Found: " << result << std::endl;
		for (std::set<int>::iterator it = my_set.begin(); it != my_set.end(); it++)
			if (*it == n)
				result = *it;
	}
	catch(...)
	{
		std::cerr << "Couldnt find or something else went wrong" << std::endl;
	}*/
	
    
}