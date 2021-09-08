#include "span.hpp"
#include <iostream>
#include <vector>
#include <set>

int f(void)
{
    int n = rand() % 500000;
    //std::cout << "  Random num generated: " << n << std::endl;
    return (n);
}

int main(void)
{
    srand(time(NULL));
    Span my_span(3);

    std::cout << "TEST_1" << std::endl;
    try
    {
        my_span.addNumber(1);
        my_span.addNumber(2);
        my_span.addNumber(3);
        my_span.addNumber(4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << "Longest: " << my_span.longestSpan() << std::endl;
        std::cout << "Shortest: " << my_span.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "TEST_2" << std::endl;
    Span big_span(150000);
    
    std::vector<int> v(15000);
    try
    {
        std::generate(v.begin(), v.end(), f);
		std::multiset<int>mset(v.begin(), v.end());
        big_span.addNumber(v.begin(), v.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

     try
    {
        std::cout << "Longest: " << big_span.longestSpan() << std::endl;
        std::cout << "Shortest: " << big_span.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "TEST_3" << std::endl;

    try
    {
        std::generate(v.begin(), v.end(), f);
        std::cout << "Vector filled" << std::endl;
        std::vector<int>::iterator b = v.begin();
        std::vector<int>::iterator e = v.end();
        big_span.addNumber(b, e);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	 try
    {
        std::cout << "Longest: " << big_span.longestSpan() << std::endl;
        std::cout << "Shortest: " << big_span.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}