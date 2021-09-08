/*#include <iostream>       // std::cout
#include <stack>
#include <deque>
#include <vector>
#include "mutantstack.hpp"*/


#include <iostream>
#include <stack>
#include <list>
#include "mutantstack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " << mstack.top() << std::endl;

	std::cout << "---" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(4242);
	mstack.push(24);
	mstack.push(2424);
	mstack.push(0);

	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "mstack content (bottom to top): " << std::endl;
		while(it != ite)
		{
			std::cout << *it;
			if (++it == ite)
				std::cout << std::endl;
			else
				std::cout << ", ";
		}
	}

	{
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "mstack content (bottom to top): " << std::endl;
		while(it != ite)
		{
			std::cout << *it;
			if (++it == ite)
				std::cout << std::endl;
			else
				std::cout << ", ";
		}
	}

	{
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();

		++it;
		--it;

		std::cout << "mstack content (top to bottom): " << std::endl;
		while(it != ite)
		{
			std::cout << *it;
			if (++it == ite)
				std::cout << std::endl;
			else
				std::cout << ", ";
		}
	}

	{
		MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator ite = mstack.rend();

		++it;
		--it;

		std::cout << "mstack content (top to bottom): " << std::endl;
		while(it != ite)
		{
			std::cout << *it;
			if (++it == ite)
				std::cout << std::endl;
			else
				std::cout << ", ";
		}
	}

	std::cout << "---" << std::endl;

	{
		std::stack<int> s(mstack);
		MutantStack<int> st = mstack;

		std::cout << "size: " << st.size() << " (" << mstack.size() << ")" << std::endl;
		std::cout << "top: " << st.top() << " (" << mstack.top() << ")" << std::endl;
		st.pop();
		std::cout << "size: " << st.size() << " (" << mstack.size() << ")" << std::endl;
		std::cout << "top: " << st.top() << " (" << mstack.top() << ")" << std::endl;
	}

	return (0);
}


/*int main ()
{
    std::deque<int> mydeque (3,100);          // deque with 3 elements
    std::vector<int> myvector (2,200);        // vector with 2 elements

    MutantStack<int> first;                    // empty stack
    MutantStack<int> second (mydeque);         // stack initialized to copy of deque

    std::stack<int,std::vector<int> > third;  // empty stack using vector
    std::stack<int,std::vector<int> > fourth (myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';

    return 0;
}*/