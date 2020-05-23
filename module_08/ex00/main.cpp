#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "EasyFind.hpp"

int main()
{
    std::vector<int>first;
    std::list<int>my_list;
    std::deque<int>my_deque;

    first.push_back(0);
    first.push_back(1);

    my_list.push_back(2);
    my_list.push_back(3);

    my_deque.push_back(4);
    my_deque.push_back(5);

    try
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
    catch(const std::exception& e)
    {
        std::cerr << "Couldnt find or something else went wrong" << std::endl;
    }
    
}