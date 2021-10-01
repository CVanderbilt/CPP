/*#include <iostream>       // std::cout
#include <stack>
#include <deque>
#include <vector>
#include "mutantstack.hpp"*/


#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include "mutantstack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::vector<int> v;

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

	v.push_back(5);
	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	v.push_back(42);
	v.push_back(4242);
	v.push_back(24);
	v.push_back(2424);

	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::vector<int>::iterator vit = v.begin();
	
		++it; ++vit;
		--it; --vit;

		std::cout << "mstack content (bottom to top): " << std::endl;
		while (it != ite)
		{
			std::cout << "(" << *it << ", " << *vit << ")";
			it++;
			vit++;
		}
		std::cout << std::endl;
	}

	{
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		std::vector<int>::const_iterator vit = v.begin();
	
		++it; ++vit;
		--it; --vit;

		std::cout << "mstack content (bottom to top): " << std::endl;
		while (it != ite)
		{
			std::cout << "(" << *it << ", " << *vit << ")";
			it++;
			vit++;
		}
		std::cout << std::endl;
	}

	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::vector<int>::iterator vite = v.end();
	
		--ite;
		--vite;

		std::cout << "mstack content (top to bottom): " << std::endl;
		while (it != ite)
		{
			std::cout << "(" << *ite << ", " << *vite << ")";
			ite--;
			vite--;
		}
		std::cout << std::endl;
	}

	{
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		std::vector<int>::const_iterator vite = v.end();
	
		--ite;
		--vite;

		std::cout << "mstack content (top to bottom): " << std::endl;
		while (it != ite)
		{
			std::cout << "(" << *ite << ", " << *vite << ")";
			ite--;
			vite--;
		}
		std::cout << std::endl;
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